#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include <utility>

#include "../libs/include/Box2d/box2d.h"
#include "vehicle.hpp"

class Obstacle {
 public:
  Obstacle(b2World* world, b2Vec2 position, float radius) {
    // Create obstacle body
    b2CircleShape shape;
    shape.m_radius = radius;
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(position.x, position.y);
    body = world->CreateBody(&bodyDef);

    // Create obstacle fixture
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;

    body->CreateFixture(&fixtureDef);

    // Set a custom user data to identify the collectable
    fixtureDef.userData.pointer = reinterpret_cast<uintptr_t>(this);
  }

  std::pair<float, float> getPosition() {
    b2Vec2 position = body->GetWorldCenter();
    return std::make_pair(position.x, position.y);
  }

  virtual void OnContact() {
    // Delete the collectable
    if (body) {
      body->GetWorld()->DestroyBody(body);
      body = nullptr;
    }
  }

 private:
  b2Body* body;
};
#endif