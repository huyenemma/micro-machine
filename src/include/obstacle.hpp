#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <iostream>
#include <utility>

#include "box2dInclude.hpp"
#include "userDataPointer.hpp"
#include "vehicle.hpp"

using namespace BodyType;
class Obstacle {
 public:
  Obstacle(b2World* world, b2Vec2 position, float radius);

  std::pair<float, float> GetPosition();

  void DeleteBody();

  float GetRadius();

  bool IsNullBody();

  void OnContact(Vehicle* car);

 private:
  b2Body* body;
  float radius_;
};
#endif