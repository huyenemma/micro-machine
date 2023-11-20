#ifndef OUTSIDE_H
#define OUTSIDE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>

#include "box2dInclude.hpp"
#include "userDataPointer.hpp"
#include "vehicle.hpp"

using namespace BodyType;
class OutsideArea {
 public:
  OutsideArea(b2World* world, b2Vec2 position, float height, float width);

  std::pair<float, float> GetPosition() const;

  void DeleteBody();

  std::pair<float, float> GetDimension();

  bool IsNullBody();

  void OnContact(Vehicle* car);

 private:
  b2Body* body;
  float height_;
  float width_;
};
#endif
