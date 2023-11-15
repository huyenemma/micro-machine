#include "./include/vehicle.hpp"
#include <cmath>
#include <iostream>

Vehicle::Vehicle(b2World* world, float x , float y )
    : forceOn(false), m_body(nullptr), maxSpeed(MAX_SPEED) 
{
    texture.loadFromFile("../img/runninggoat.png");
    sprite.setTexture(texture);
    rescaleSprite(sprite, 80.0f, 40.0f);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x, y);
    bodyDef.linearDamping = LINEAR_DAMPING;
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
}

Vehicle::~Vehicle() {
    m_body->GetWorld()->DestroyBody(m_body);
}

void Vehicle::UpdateSpeed() {
    b2Vec2 vel = m_body->GetLinearVelocity();
    float forceMagnitude = 0;

    float currentSpeed = vel.Length();
    std::cout << "Current Speed: " << currentSpeed << std::endl;

    if (forceOn && std::abs(vel.x) < maxSpeed)
    {
        forceMagnitude = FORCE_MAGNITUDE;
    }

    b2Vec2 force = b2Vec2(cos(m_body->GetAngle()) * forceMagnitude, sin(m_body->GetAngle()) * forceMagnitude);
    m_body->ApplyForceToCenter(force, true);
}

void Vehicle::Rotate(float torque  ) {
    m_body->ApplyTorque(torque, true);
}

std::pair<float, float> Vehicle::GetPosition() const {
    b2Vec2 position = m_body->GetWorldCenter();
    return std::make_pair(position.x, position.y);
}

void Vehicle::ToggleForce(bool value) {
    forceOn = value;
}

float Vehicle::GetAngle() {
    return m_body->GetAngle();
}

void Vehicle::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
    auto pos = GetPosition(); 
    sprite.setPosition(pos.first * SCALE, pos.second * SCALE); 

    float angleDegrees = m_body->GetAngle() * (180 / b2_pi);
    sprite.setRotation(angleDegrees);

    target.draw(sprite, states);
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

