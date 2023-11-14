#ifndef VEHICLE_H
#define VEHICLE_H

#include <SFML/Graphics.hpp>
#include "box2dInclude.hpp"
#include "constant.hpp"
#include "reScale.hpp"

// Class representing a simple vehicle in a 2D physics world using Box2D
class Vehicle : public sf::Drawable {
 protected:
  bool forceOn;    // Flag indicating whether a force is applied to the vehicle
  b2Body* m_body;  // Box2D body representing the vehicle
  float maxSpeed;  // Maximum speed of the vehicle
  mutable sf::Sprite sprite;
  sf::Texture texture;

 public:
  // Constructor: Creates a new vehicle in the given Box2D world at the
  // specified position (default at the origin)
  Vehicle(b2World* world, float x = 0, float y = 0);

  // Destructor: Destroys the Box2D body associated with the vehicle
  ~Vehicle();

  // Update the speed of the vehicle based on applied force
  void UpdateSpeed();

  // Rotate the vehicle by applying angular impulse (default torque is 1)
  void Rotate(float torque = 1);

  // Get the current position of the vehicle
  std::pair<float, float> GetPosition() const;

  // Toggle the force applied to the vehicle on/off
  void ToggleForce(bool value);

  // Get the current angle of the vehicle
  float GetAngle();

  // Placeholder function for processing items (to be implemented as needed)
  void ProcessItem();

  // A skill particular to each vehicle
  // virtual void SuperSkill() = 0;

  // draw vehicle
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif  // VEHICLE_H
