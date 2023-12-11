#ifndef CAT_H
#define CAT_H

#include "box2dInclude.hpp"
#include "vehicle.hpp"

/**
 * @brief Class representing a Cat, derived from Vehicle.
 */
class Cat : public Vehicle {
 private:
  int superSkillCoolDown;  ///< Cooldown for the super skill. Follow camelCase for variable names.

 public:
  /**
   * @brief Constructor for the Cat class.
   * @param world Pointer to the Box2D world.
   * @param x Initial x-coordinate of the Cat.
   * @param y Initial y-coordinate of the Cat.
   * @param texture Reference to the SFML texture for the Cat.
   */
  Cat(b2World* world, float x, float y, const sf::Texture& texture);

  /**
   * @brief Destructor for the Cat class.
   */
  ~Cat();

  /**
   * @brief Overrides the super skill function from the base class (Vehicle).
   */
  void SuperSkill() override;
};

#endif
