#ifndef VEHICLE_H
#define VEHICLE_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "box2dInclude.hpp"
#include "buff.hpp"
#include "collectable.hpp"
#include "constant.hpp"
#include "reScale.hpp"
#include "userDataPointer.hpp"

using namespace BodyType;

/**
 * @brief Class representing a simple vehicle in a 2D physics world using Box2D.
 */
class Vehicle : public sf::Drawable {
 protected:
  bool forceOn;    ///< Flag indicating whether a force is applied to the vehicle.
  b2Body* m_body;  ///< Box2D body representing the vehicle.
  float maxSpeed;  ///< Maximum speed of the vehicle.
  mutable sf::Sprite sprite_;
  sf::Texture texture_;

  int superSkillCoolDown = 0;

  b2PolygonShape dynamicBox;

  b2Body* m_frontTire;

  b2Body* m_rearTire;
  // Variables related to Buff with 1 as the default value
  float forceBuff = 1.0f;
  float MaxSpeedBuff = 1.0f;
  float SizeBuff = 1.0f;
  float TorqueBuff = 1.0f;

  // A collection of Buffs
  std::vector<Buff*> buffs;

  // Sound effect
  sf::SoundBuffer runBuffer;
  sf::Sound run;

 public:
  /**
   * @brief Constructor for Vehicle.
   * @param world Pointer to the Box2D world.
   * @param x Initial x-coordinate of the vehicle.
   * @param y Initial y-coordinate of the vehicle.
   * @param texture Reference to the SFML texture for the vehicle.
   */
  Vehicle(b2World* world, float x, float y, const sf::Texture& texture);

  /**
   * @brief Destructor for Vehicle.
   * @details Destroys the Box2D body associated with the vehicle.
   */
  ~Vehicle();

  /**
   * @brief Update function for the vehicle.
   */
  void Update();

  /**
   * @brief Update the lateral velocity of the vehicle.
   */
  void UpdateLateralVelocity();

  /**
   * @brief Update the speed of the vehicle based on applied force.
   */
  void UpdateSpeed();

  /**
   * @brief Rotate the vehicle by applying angular impulse.
   * @param angle The angular impulse (default is 1).
   */
  void Rotate(float angle = 1);

  /**
   * @brief Update the cooldown for the super skill.
   */
  void UpdateCoolDown();

  /**
   * @brief Get the current position of the vehicle.
   * @return A pair representing the x and y coordinates of the vehicle.
   */
  std::pair<float, float> GetPosition() const;

  /**
   * @brief Toggle the force applied to the vehicle on/off.
   * @param value True to enable the force, false to disable.
   */
  void ToggleForce(bool value);

  /**
   * @brief Get the current angle of the vehicle.
   * @return The current angle of the vehicle.
   */
  float GetAngle();

  /**
   * @brief Placeholder function for processing items (to be implemented as needed).
   */
  void ProcessItem();

  /**
   * @brief Draw the vehicle.
   * @param target Render target.
   * @param states Render states.
   */
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

  /**
   * @brief Apply a rotating buff to the vehicle.
   * @param degree The rotation degree.
   * @param intensity The intensity of the rotation.
   */
  void CrazyRotate(float degree, float intensity);

  /**
   * @brief Apply a magnetic pull buff to the vehicle.
   * @param radius The radius of the magnetic pull.
   */
  void MagneticPull(float radius);

  /**
   * @brief Reverse the magnetic pull buff.
   */
  void ReverseMagneticPull();

  /**
   * @brief Multiply various attributes of the vehicle by the specified factors.
   * @param forceMu Force multiplication factor.
   * @param MaxSpeedMul Maximum speed multiplication factor.
   * @param SizeMul Size multiplication factor.
   * @param TorqueMul Torque multiplication factor.
   */
  void ApplyBuff(float forceMu = 1.0f, float MaxSpeedMul = 1.0f, float SizeMul = 1.0f, float TorqueMul = 1.0f);

  /**
   * @brief Add a buff to the vehicle.
   * @param buff Pointer to the buff to be added.
   */
  void AddBuff(Buff* buff);

  /**
   * @brief Update active buffs on the vehicle.
   */
  void UpdateBuff();

  /**
   * @brief Virtual function representing the super skill of the vehicle.
   */
  virtual void SuperSkill();

  /**
   * @brief Get the state of the force applied to the vehicle.
   * @return True if force is applied, false otherwise.
   */
  bool GetForce();
};

#endif  // VEHICLE_H
