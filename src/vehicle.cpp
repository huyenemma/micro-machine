#include "./include/vehicle.hpp"
#include <cmath>
#include <iostream>

Vehicle::Vehicle(b2World* world, float x , float y, const std::string& imagePath)
    : forceOn(false), m_body(nullptr), maxSpeed(MAX_SPEED), imagePath_(imagePath) 
{
    texture_.loadFromFile(imagePath_);
    sprite_.setTexture(texture_);
    rescaleSprite(sprite_, BOX_WIDTH * SCALE, BOX_HEIGHT * SCALE);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x, y);
    bodyDef.angularDamping = ANGULAR_DAMPING;
    bodyDef.awake = true;

    b2PolygonShape dynamicBox;
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

    if (forceOn && std::abs(vel.x) < maxSpeed)
    {
        forceMagnitude = FORCE_MAGNITUDE*forceBuff;
    }

    b2Vec2 force = b2Vec2(cos(m_body->GetAngle()) * forceMagnitude, sin(m_body->GetAngle()) * forceMagnitude);
    m_body->ApplyForceToCenter(force, true);
}

void Vehicle::Rotate(float angleInDegrees) {
    // Convert the angle to radians
    float angleInRadians = angleInDegrees*180.0f/3.14f;

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

//void Vehicle::ProcessItem()
//{
    // Implementation for processing items
//}


void Vehicle::UpdateLateralVelocity() {
    // Calculate the lateral velocity
    b2Vec2 currentRightNormal = m_body->GetWorldVector(b2Vec2(0, 1.0f));
    b2Vec2 lateralVelocity = b2Dot(currentRightNormal, m_body->GetLinearVelocity()) * currentRightNormal;

    // Apply impulse to cancel out the lateral velocity
    b2Vec2 impulse = m_body->GetMass() * -lateralVelocity;
    m_body->ApplyLinearImpulse(impulse, m_body->GetWorldCenter(),true);
    if ( impulse.Length() > MAX_LATERAL_IMPULSE )
      impulse *= MAX_LATERAL_IMPULSE / impulse.Length();
    std::cout<<impulse.Length()<<std::endl;
    m_body->ApplyAngularImpulse( 0.001f * m_body->GetInertia() * -m_body->GetAngularVelocity() ,true);
}

/*
void Vehicle::BoostSpeed(float boost){
    b2Vec2 force = b2Vec2(cos(m_body->GetAngle()) * boost * m_body->GetMass(), sin(m_body->GetAngle()) * boost * m_body->GetMass());
    m_body->ApplyForceToCenter(force, true);
    this->ToggleForce(true);
    std::cout << "speedzz" << std::endl;
}
void Vehicle::CrazyRotate(float torque, float boost,int time){
    b2Vec2 force = b2Vec2(cos(m_body->GetAngle()) * -boost * m_body->GetMass(), sin(m_body->GetAngle()) * -boost * m_body->GetMass());
    m_body->ApplyForceToCenter(force, true);
    this->ToggleForce(true);
    m_body->ApplyAngularImpulse(torque*m_body->GetMass(), true); 
}


float Vehicle::GetMass(){
    return m_body->GetMass();
}

void Vehicle::UpdateMaxSpeed(float speed){
    maxSpeed = maxSpeed + speed;
}
*/
void Vehicle::AddBuff(Buff* buff) {
    buffs.push_back(buff);
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
            (*it)->ApplyEffect(this);
            ++it;
        }
        else{
            std::cout << "reverse" << std::endl;
            (*it)->ReverseEffect(this);
            it = buffs.erase(it);
        }
    }
}

void Vehicle::Update() {

    UpdateSpeed();
    UpdateBuff();
}