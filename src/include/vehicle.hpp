#ifndef VEHICLE_H
#define VEHICLE_H

#include <SFML/Graphics.hpp>
#include "box2dInclude.hpp"
#include "constant.hpp"
#include "reScale.hpp"
#include "buff.hpp"
#include "userDataPointer.hpp"


// Class representing a simple vehicle in a 2D physics world using Box2D
class Vehicle : public sf::Drawable {
 protected:
  bool forceOn;    // Flag indicating whether a force is applied to the vehicle
  b2Body* m_body;  // Box2D body representing the vehicle
  float maxSpeed;  // Maximum speed of the vehicle
  mutable sf::Sprite sprite_;
  sf::Texture texture_;

  int superSkillCoolDown=0; 


  b2Body* m_frontTire;

  b2Body* m_rearTire;
  //Variable that relate to Buff with 1 as default value
  float forceBuff     = 1.0f;
  float MaxSpeedBuff  = 1.0f; 
  float SizeBuff      = 1.0f;
  float TorqueBuff    = 1.0f;

  //A collection of Buffs

  std::vector<Buff*> buffs;

 public:
  // Constructor: Creates a new vehicle in the given Box2D world at the
  // specified position (default at the origin)
  Vehicle(b2World* world, float x, float y, const sf::Texture& texture);

  // Destructor: Destroys the Box2D body associated with the vehicle
  ~Vehicle();

  void Update();

  void UpdateLateralVelocity();

  // Update the speed of the vehicle based on applied force
  void UpdateSpeed();

  // Rotate the vehicle by applying angular impulse (default torque is 1)
  void Rotate(float angle = 1);

  // Get the current position of the vehicle
  std::pair<float, float> GetPosition() const;

  // Toggle the force applied to the vehicle on/off
  void ToggleForce(bool value);

  // Get the current angle of the vehicle
  float GetAngle();

  // Placeholder function for processing items (to be implemented as needed)
  void ProcessItem();

  // draw vehicle
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

  //Multiply 
  void ApplyBuff(float forceMu=1.0f, float MaxSpeedMul=1.0f,float SizeMul=1.0f,float TorqueMul=1.0f);

  void AddBuff(Buff* buff);

  void UpdateBuff();

  void virtual SuperSkill() ;
};

#endif  // VEHICLE_H
