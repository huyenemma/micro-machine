
#include "../include/box2d/box2d.h"

#include <math.h>

class Vehicle
{
private:
    bool forceOn=false;
    b2Body* m_body;
    float maxSpeed=10;
public:
    Vehicle(b2World* world, float x,float y);

    ~Vehicle();

    void UpdateSpeed(){
        b2Vec2 vel = m_body->GetLinearVelocity();
        float forceMagnitude=0;
        if (forceOn && abs(vel.x) < maxSpeed ) {
            forceMagnitude =1;}
        b2Vec2 force = b2Vec2(cos(m_body->GetAngle())*forceMagnitude, sin(m_body->GetAngle())*forceMagnitude) ;
        m_body->ApplyForceToCenter(force, true);    
    };

    //positive value of torque means the object turn right.
        void Rotate(float torque=1) {
        m_body->ApplyAngularImpulse(torque, true);
    }

    std::pair<float, float> GetPosition() {
        b2Vec2 position = m_body->GetWorldCenter();
        return std::make_pair(position.x, position.y);
    }

    void ToggleForce(bool value){
        forceOn = value;
    };
     
    float GetAngle(){
        return m_body->GetAngle();
    }



};

Vehicle::Vehicle(b2World* world, float x=0,float y=0)
{ 
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x,y);
    
    bodyDef.linearDamping = 0.05f;
    bodyDef.angularDamping = 0.95f;
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



