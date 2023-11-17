#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <iostream>
#include <utility>

#include "box2dInclude.hpp"
#include "userDataPointer.hpp"
#include "vehicle.hpp"

using namespace BodyType;
class Obstacle : public sf::Drawable {
 public:
  Obstacle(b2World* world, b2Vec2 position, float radius);

  std::pair<float, float> GetPosition() const;

  void DeleteBody();

  float GetRadius();

  bool IsNullBody();

  void draw(sf::RenderTarget& target, sf::RenderStates states) const;

  void OnContact(Vehicle* car);

 private:
  mutable sf::Sprite sprite;
  sf::Texture texture;  // Declare texture as a member

  b2Body* body;
  float radius_;
};
#endif