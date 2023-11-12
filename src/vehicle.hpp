#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <math.h>
#include <utility> 
#include "../libs/include/Box2d/box2d.h"
#include "usertype.hpp"

class Vehicle {
 private:
  bool forceOn = false;
  b2Body* m_body;
  float maxSpeed = 40;

 public:
  Vehicle(b2World* world, float x, float y);

  ~Vehicle();

  void UpdateSpeed() {
    b2Vec2 vel = m_body->GetLinearVelocity();
    float forceMagnitude = 0;
    if (forceOn && abs(vel.x) < maxSpeed) {
      forceMagnitude = 5*m_body->GetMass();
    }
    b2Vec2 force = b2Vec2(cos(m_body->GetAngle()) * forceMagnitude,
                          sin(m_body->GetAngle()) * forceMagnitude);
    m_body->ApplyForceToCenter(force, true);
  };

  void Rotate(float torque = 100) { m_body->ApplyAngularImpulse(torque*m_body->GetMass(), true); }

  std::pair<float, float> GetPosition() {
    b2Vec2 position = m_body->GetWorldCenter();
    return std::make_pair(position.x, position.y);
  }

  void ToggleForce(bool value) { forceOn = value; };

  float GetAngle() { return m_body->GetAngle(); }

  float GetMass() {return m_body->GetMass();}

  void CollectableHit(b2Vec2 impulse){ m_body->ApplyLinearImpulse(impulse, m_body->GetWorldCenter(), true);}

  void ProcessItem(){

  };
};

Vehicle::Vehicle(b2World* world, float x = 0, float y = 0) {
  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody;
  bodyDef.position.Set(x, y);

  bodyDef.linearDamping = 0.6f;
  bodyDef.angularDamping = 0.95f;
  bodyDef.awake = true;
  b2PolygonShape dynamicBox;
  dynamicBox.SetAsBox(25.0f, 25.0f);

  
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &dynamicBox;
  fixtureDef.density = 1.0f;
  fixtureDef.friction = 0.3f;
  

  m_body = world->CreateBody(&bodyDef);
  m_body->CreateFixture(&fixtureDef);

  UserData* data = new UserData(); // Allocate UserData on the heap
  data->info.type = UserType::Vehicle;
  data->info.pointer = this;
  m_body->GetUserData().pointer = reinterpret_cast<uintptr_t>(data);

}

Vehicle::~Vehicle() { m_body->GetWorld()->DestroyBody(m_body); }

#endif