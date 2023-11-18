#include "./include/vehicle.hpp"
#include <cmath>
#include <iostream>

Vehicle::Vehicle(b2World* world, float x , float y, const std::string& imagePath)
    : forceOn(false), m_body(nullptr), maxSpeed(MAX_SPEED), imagePath_(imagePath) 
{
    texture_.loadFromFile(imagePath_);
    sprite_.setTexture(texture_);
    rescaleSprite(sprite_, 60.0f, 60.0f);

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

    std::cout << "Current position: " << GetPosition().first * SCALE << "," << GetPosition().second * SCALE << std::endl;

    if (forceOn && std::abs(vel.x) < maxSpeed)
    {
        forceMagnitude = FORCE_MAGNITUDE*forceBuff;
    }

    b2Vec2 force = b2Vec2(cos(m_body->GetAngle()) * forceMagnitude, sin(m_body->GetAngle()) * forceMagnitude);
    m_body->ApplyForceToCenter(force, true);
}

void Vehicle::Rotate(float torque) {
    m_body->ApplyTorque(torque*TorqueBuff, true);
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

    float angleDegrees = m_body->GetAngle() * (180 / b2_pi);
    sprite_.setRotation(angleDegrees);

    target.draw(sprite_, states);
}

//void Vehicle::ProcessItem()
//{
    // Implementation for processing items
//}

void Vehicle::BoostSpeed(float boost){
    b2Vec2 force = b2Vec2(cos(m_body->GetAngle()) * boost * m_body->GetMass(), sin(m_body->GetAngle()) * boost * m_body->GetMass());
    m_body->ApplyForceToCenter(force, true);
    this->ToggleForce(true);
    std::cout << "speedzz" << std::endl;
}

void Vehicle::CrazyRotate(float torque, float boost, int times){
    for (int i = 0; i < times; i++){
        std::cout << "hi" <<std::endl;
        b2Vec2 force = b2Vec2(cos(m_body->GetAngle()) * -boost * m_body->GetMass(), sin(m_body->GetAngle()) * -boost * m_body->GetMass());
        m_body->ApplyForceToCenter(force, true);
        this->ToggleForce(true);
        m_body->ApplyAngularImpulse(torque*m_body->GetMass(), true); 
    }
    std::cout << "slow down" << std::endl;
}


float Vehicle::GetMass(){
    return m_body->GetMass();
}

void Vehicle::UpdateMaxSpeed(float speed){
    maxSpeed = maxSpeed + speed;
}

void Vehicle::AddBuff(Buff* buff) {
    buffs.push_back(buff);
}

void Vehicle::ApplyBuff(float forceMul, float MaxSpeedMul,float SizeMul,float TorqueMul){
    forceBuff *=forceMul;
    MaxSpeedBuff *= MaxSpeedMul;
    SizeBuff    *= SizeMul;
    TorqueBuff  *= TorqueMul;
};


void Vehicle::UpdateBuff() {
    std::vector<Buff*>::iterator it = buffs.begin();

    // Iterate until the end of the vector is reached
    while (it != buffs.end()) {
        (*it)->Tick();
        ++it;
    };
}

void Vehicle::Update() {
    UpdateSpeed();
    UpdateBuff();
}