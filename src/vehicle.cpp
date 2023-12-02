#include "./include/vehicle.hpp"
#include <cmath>
#include <iostream>

Vehicle::Vehicle(b2World* world, float x, float y, const sf::Texture& texture)
    : forceOn(false), m_body(nullptr), maxSpeed(MAX_SPEED), texture_(texture)
{
    sprite_.setTexture(texture_);
    rescaleSprite(sprite_, BOX_WIDTH * SCALE, BOX_HEIGHT * SCALE);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x, y);
    bodyDef.linearDamping = LINEAR_DAMPING;
    bodyDef.angularDamping = ANGULAR_DAMPING;
    bodyDef.awake = true;

    dynamicBox.SetAsBox(BOX_WIDTH, BOX_HEIGHT);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = DENSITY;
    fixtureDef.friction = FRICTION;

    m_body = world->CreateBody(&bodyDef);
    m_body->CreateFixture(&fixtureDef);
    

    // Create the front tire
    b2BodyDef frontTireDef;
    frontTireDef.type = b2_dynamicBody;
    frontTireDef.position.Set(x - 1, y);

    m_frontTire = world->CreateBody(&frontTireDef);
    m_frontTire->CreateFixture(&fixtureDef);

    // Create the rear tire
    b2BodyDef rearTireDef;
    rearTireDef.type = b2_dynamicBody;
    rearTireDef.position.Set(x + 1, y);

    m_rearTire = world->CreateBody(&rearTireDef);
    m_rearTire->CreateFixture(&fixtureDef);

    UserData* data = new UserData(); // Allocate UserData on the heap
    data->info.type = UserType::Vehicle;
    data->info.pointer = this;
    m_body->GetUserData().pointer = reinterpret_cast<uintptr_t>(data); 
}

Vehicle::~Vehicle() {
    m_body->GetWorld()->DestroyBody(m_body);
}

void Vehicle::UpdateSpeed() {
    b2Vec2 vel = m_body->GetLinearVelocity();
    float forceMagnitude = 0;

    if (forceOn && std::abs(vel.x) < maxSpeed * MaxSpeedBuff) {
        // Calculate the remaining force needed to reach maxSpeed * MaxSpeedBuff
        float remainingForce = FORCE_MAGNITUDE * forceBuff;

        // Check if the vehicle is already exceeding the desired speed
        if (std::abs(vel.x) > maxSpeed * MaxSpeedBuff) {
            remainingForce -= m_body->GetMass() * std::abs(vel.x - maxSpeed * MaxSpeedBuff);
        }

        // Limit the force to ensure the vehicle won't exceed maxSpeed * MaxSpeedBuff
        if (remainingForce > 0) {
            forceMagnitude = remainingForce;
        }
    }


    b2Vec2 force = b2Vec2(cos(m_body->GetAngle()) * forceMagnitude, sin(m_body->GetAngle()) * forceMagnitude);
    m_body->ApplyForceToCenter(force, true);
}

void Vehicle::Rotate(float angleInDegrees) {
    // Convert the angle to radians
    float angleInRadians = angleInDegrees*TorqueBuff* b2_pi/180.0f;

    // Get the current position of the body
    b2Vec2 currentPosition = m_body->GetPosition();

    // Get the current angle of the body
    float currentAngle = m_body->GetAngle();

    // Calculate the new position after rotation
    float offsetX = currentPosition.x - cos(currentAngle) * (currentPosition.x - m_body->GetWorldCenter().x)
                    + sin(currentAngle) * (currentPosition.y - m_body->GetWorldCenter().y);
    float offsetY = currentPosition.y - sin(currentAngle) * (currentPosition.x - m_body->GetWorldCenter().x)
                    - cos(currentAngle) * (currentPosition.y - m_body->GetWorldCenter().y);

    // Set the new position and angle for the body
    m_body->SetTransform(b2Vec2(offsetX, offsetY), currentAngle + angleInRadians);
}

std::pair<float, float> Vehicle::GetPosition() const {
    b2Vec2 position = m_body->GetWorldCenter();
    return std::make_pair(position.x, position.y);
}

void Vehicle::ToggleForce(bool value) {
    if (value) {
        forceOn = true;
        m_body->SetLinearDamping(0);
    } else {
        forceOn = false;    
        m_body->SetLinearDamping(LINEAR_DAMPING);
    }
}

float Vehicle::GetAngle() {
    return m_body->GetAngle();
}

void Vehicle::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
    auto pos = GetPosition(); 
    sprite_.setPosition(pos.first * SCALE, pos.second * SCALE); 

    sf::Vector2f spriteOrigin(sprite_.getLocalBounds().width / 2, sprite_.getLocalBounds().height / 2);
    sprite_.setOrigin(spriteOrigin);
    float angleDegrees = m_body->GetAngle() * (180 / b2_pi);
    sprite_.setRotation(angleDegrees);
    target.draw(sprite_, states);
}




void Vehicle::UpdateLateralVelocity() {
    // Calculate the lateral velocity
    b2Vec2 currentRightNormal = m_body->GetWorldVector(b2Vec2(1.0f, 0.0f));
    b2Vec2 lateralVelocity = b2Dot(currentRightNormal, m_body->GetLinearVelocity()) * currentRightNormal;

    // Apply impulse to cancel out the lateral velocity
    b2Vec2 impulse = m_body->GetMass() * -lateralVelocity;
    if ( impulse.Length() > MAX_LATERAL_IMPULSE )
      impulse *= MAX_LATERAL_IMPULSE / impulse.Length();
    
    m_body->ApplyLinearImpulse(impulse, m_body->GetWorldCenter(),true);  
}

void Vehicle::CrazyRotate(float degree, float intensity){
    // Convert degrees to radians
    float radians = degree * b2_pi / 180.0f;

    // Calculate linear force based on the current angle
    b2Vec2 linearForce = b2Vec2(cos(m_body->GetAngle() + radians) * intensity * m_body->GetMass(),
                                 sin(m_body->GetAngle() + radians) * intensity * m_body->GetMass());

    // Apply linear force to center of the body
    m_body->ApplyForceToCenter(linearForce, true);

    // Calculate rotational force
    float torque = intensity * m_body->GetMass(); // Adjust the multiplier as needed

    // Apply torque to the body for rotational effect
    m_body->ApplyTorque(torque, true);
}

void Vehicle::AddBuff(Buff* buff) {
    buffs.push_back(buff);
    
    if ( !(buff)->IsContinuous() ) {
        buff->ApplyEffect(this);  
    }
    
}

void Vehicle::ApplyBuff(float forceMul, float MaxSpeedMul,float SizeMul,float TorqueMul){
    forceBuff *= forceMul;
    MaxSpeedBuff *= MaxSpeedMul;
    SizeBuff    *= SizeMul;
    TorqueBuff  *= TorqueMul;
};


void Vehicle::UpdateBuff() {
    std::vector<Buff*>::iterator it = buffs.begin();
    // Iterate until the end of the vector is reached
    while (it != buffs.end()) {
        if (!(*it)->Tick()){
            if ( (*it)->IsContinuous() ) {
                (*it)->ApplyEffect(this);
            }
            ++it;
        }
        else{
            std::cout << "reverse" << std::endl;
            (*it)->ReverseEffect(this);
            delete *it;
            it = buffs.erase(it);
        }
    }
}


void Vehicle::UpdateCoolDown(){
    if (superSkillCoolDown > 0)
        superSkillCoolDown--;
};


void Vehicle::Update() {
    UpdateCoolDown();
    UpdateBuff();
    UpdateSpeed();
}

void Vehicle::SuperSkill() {
    std::cout<<"HI"<<std::endl;
}

void Vehicle::MagneticPull(float radius) {
    b2Fixture* fixture = m_body->GetFixtureList();
    if (fixture) {
        b2Shape* shape = fixture->GetShape();
        dynamic_cast<b2PolygonShape*>(shape)->SetAsBox(BOX_WIDTH*radius, BOX_HEIGHT*radius);
    }
}

void Vehicle::ReverseMagneticPull() {
    b2Fixture* fixture = m_body->GetFixtureList();
    if (fixture) {
        b2Shape* shape = fixture->GetShape();
        dynamic_cast<b2PolygonShape*>(shape)->SetAsBox(BOX_WIDTH, BOX_HEIGHT);
    }
}

