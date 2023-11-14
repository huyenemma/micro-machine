#ifndef COLLECTABLE_H
#define COLLECTABLE_H

#include <utility>

#include "./include/vehicle.hpp"
#include "box2d/box2d.h"

class Collectable {
 public:
  Collectable(b2World* world, b2Vec2 position, float radius) : radius_(radius) {
    // Define the collectable's shape
    b2CircleShape shape;
    shape.m_radius = radius;

    // Define the collectable's body definition
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(position.x, position.y);

    // Create the collectable's body
    body = world->CreateBody(&bodyDef);

    // Create the fixture for the collectable
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.isSensor =
        true;  // Make the fixture a sensor to trigger contact without collision

    body->CreateFixture(&fixtureDef);

    // Set a custom user data to identify the collectable
    // b2BodyUserData data = body->GetUserData();
    // uintptr_t uintptrValue = reinterpret_cast<uintptr_t>(this);
    // data.pointer = uintptrValue;
    body->GetUserData().pointer = reinterpret_cast<uintptr_t>(this);
  }

  std::pair<float, float> GetPosition() {
    b2Vec2 position = body->GetWorldCenter();
    return std::make_pair(position.x, position.y);
  }

  float GetRadius() { return radius_; }
  virtual void OnContact() {
    // Delete the collectable
    if (body) {
      body->GetWorld()->DestroyBody(body);
      body = nullptr;
    }
  }

 private:
  b2Body* body;
  float radius_;
};

#endif