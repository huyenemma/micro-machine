#include "vehicle.hpp"
#include "../include/box2d/box2d.h"
#include <cmath>
#include "userDataPointer.hpp"

constexpr float MAX_SPEED = 5.0f;
constexpr float LINEAR_DAMPING = 0.6f;
constexpr float ANGULAR_DAMPING = 0.3f;
constexpr float BOX_WIDTH = 20.0f;
constexpr float BOX_HEIGHT = 20.0f;
constexpr float DENSITY = 1.0f;
constexpr float FRICTION = 0.3f;
constexpr float FORCE_MAGNITUDE = 2.0f;

using namespace BodyType;
Vehicle::Vehicle(b2World* world, float x , float y )
    : forceOn(false), m_body(nullptr), maxSpeed(MAX_SPEED)
{
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



    UserData* data = new UserData(); // Allocate UserData on the heap
    data->info.type = UserType::Vehicle;
    data->info.pointer = this;
    m_body->GetUserData().pointer = reinterpret_cast<uintptr_t>(data);
}



Vehicle::~Vehicle()
{
    m_body->GetWorld()->DestroyBody(m_body);
}

void Vehicle::UpdateSpeed()
{
    b2Vec2 vel = m_body->GetLinearVelocity();
    float forceMagnitude = 0;

    if (forceOn && std::abs(vel.x) < maxSpeed)
    {
        forceMagnitude = FORCE_MAGNITUDE*m_body->GetMass();
    }

    b2Vec2 force = b2Vec2(cos(m_body->GetAngle()) * forceMagnitude, sin(m_body->GetAngle()) * forceMagnitude);
    m_body->ApplyForceToCenter(force, true);
}

void Vehicle::Rotate(float torque  )
{
    m_body->ApplyTorque(torque*m_body->GetMass(), true);
}

std::pair<float, float> Vehicle::GetPosition()
{
    b2Vec2 position = m_body->GetWorldCenter();
    return std::make_pair(position.x, position.y);
}

void Vehicle::ToggleForce(bool value)
{
    forceOn = value;
}

float Vehicle::GetAngle()
{
    return m_body->GetAngle();
}

void Vehicle::ProcessItem()
{
    // Implementation for processing items
}