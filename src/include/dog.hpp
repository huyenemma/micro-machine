#ifndef DOG_H
#define DOG_H

#include "box2dInclude.hpp"
#include "vehicle.hpp"

/**
 * @brief Class representing a Dog, derived from Vehicle.
 */
class Dog : public Vehicle {
 private:
  int superSkillCoolDown;  ///< Cooldown for the super skill. Follow camelCase for variable names.

 public:
  /**
   * @brief Constructor for the Dog class.
   * @param world Pointer to the Box2D world.
   * @param x Initial x-coordinate of the Dog (default: 0).
   * @param y Initial y-coordinate of the Dog (default: 0).
   * @param imagePath Path to the image file for the Dog (default: "../img/buffalo.png").
   */
  Dog(b2World* world, float x = 0, float y = 0, const std::string& imagePath = "../img/buffalo.png");

  /**
   * @brief Destructor for the Dog class.
   * @details Destroys the Box2D body associated with the Dog.
   */
  ~Dog();

  /**
   * @brief Overrides the super skill function from the base class (Vehicle).
   */
  void SuperSkill() override;
};

#endif
