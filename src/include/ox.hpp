#ifndef OX_H
#define OX_H

#include "vehicle.hpp"

/**
 * @brief Class representing an Ox, derived from Vehicle.
 */
class Ox : public Vehicle {
 private:
  // No private members in this example

 public:
  /**
   * @brief Constructor for the Ox class.
   * @param world Pointer to the Box2D world.
   * @param x Initial x-coordinate of the Ox.
   * @param y Initial y-coordinate of the Ox.
   * @param texture Reference to the SFML texture for the Ox.
   */
  Ox(b2World* world, float x, float y, const sf::Texture& texture);

  /**
   * @brief Destructor for the Ox class.
   * @details Destroys the Box2D body associated with the Ox.
   */
  ~Ox();

  /**
   * @brief Overrides the super skill function from the base class (Vehicle).
   */
  void SuperSkill() override;
};

#endif  // OX_H
