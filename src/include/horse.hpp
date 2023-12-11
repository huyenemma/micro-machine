#ifndef HORSE_H
#define HORSE_H

#include "../include/box2d/box2d.h"
#include "vehicle.hpp"

/**
 * @brief Class representing a Horse, derived from Vehicle.
 */
class Horse : public Vehicle {
 private:
  int superSkillCoolDown;  ///< Cooldown for the super skill. Follow camelCase for variable names.

 public:
  /**
   * @brief Constructor for the Horse class.
   * @param world Pointer to the Box2D world.
   * @param x Initial x-coordinate of the Horse.
   * @param y Initial y-coordinate of the Horse.
   * @param texture Reference to the SFML texture for the Horse.
   */
  Horse(b2World* world, float x, float y, const sf::Texture& texture);

  /**
   * @brief Destructor for the Horse class.
   */
  ~Horse();

  /**
   * @brief Overrides the super skill function from the base class (Vehicle).
   */
  void SuperSkill() override;
};

#endif
