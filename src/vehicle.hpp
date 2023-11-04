
#include "../include/box2d/box2d.h"

#include <math.h>

class Vehicle
{
private:
    bool forceOn=false;
    b2Body* m_body;
    float maxSpeed=100;
public:
    Vehicle(b2World* world, float x,float y);

    ~Vehicle();

    void UpdateSpeed(){
        b2Vec2 vel = m_body->GetLinearVelocity();
        float force=0;
        if (forceOn && abs(vel.x) < maxSpeed ) {
            force =40;}
        m_body->ApplyForce(b2Vec2(force,0),m_body->GetWorldCenter(),true);
    };

    void Rotate(float torque=10) {
    m_body->ApplyTorque(torque, true);
    }



};

Vehicle::Vehicle(b2World* world, float x=0,float y=0)
{ 
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x,y);
    
    bodyDef.linearDamping = 0.01f;
    bodyDef.angularDamping = 0.01f;
    bodyDef.awake = true;
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);


    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;


    m_body = world->CreateBody(&bodyDef);
    m_body->CreateFixture(&fixtureDef);
    
}

Vehicle::~Vehicle()
{
  m_body->GetWorld()->DestroyBody(m_body);
}



