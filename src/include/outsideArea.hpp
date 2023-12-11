/**
 * @file outside.hpp
 * @brief OutsideArea class header.
 *
 * This file contains the definition of the OutsideArea class, which represents areas
 * in the game world that are outside the main playable area, like checkpoints and start lines.
 */

#ifndef OUTSIDE_H
#define OUTSIDE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>

#include "box2dInclude.hpp"
#include "userDataPointer.hpp"
#include "vehicle.hpp"

/**
 * @class OutsideArea
 * @brief Represents areas outside the main playable region in the game.
 *
 * The OutsideArea class is used to create and manage areas in the game world that are
 * not part of the central gameplay but are significant for game mechanics, such as 
 * checkpoints and start lines. It handles their physical representation and interactions.
 */
class OutsideArea {
 public:
  /**
   * @brief Constructs an OutsideArea object.
   *
   * Initializes an area outside the main playable region with a position, height, and width.
   *
   * @param world The Box2D world where the outside area exists.
   * @param position The position of the area in the game world.
   * @param height The height of the area.
   * @param width The width of the area.
   */
  OutsideArea(b2World* world, b2Vec2 position, float height, float width);

  /**
   * @brief Gets the position of the outside area.
   * 
   * @return A pair of floats representing the x and y coordinates of the area.
   */
  std::pair<float, float> GetPosition() const;

  /**
   * @brief Deletes the physical body associated with the area.
   */
  void DeleteBody();

  /**
   * @brief Gets the dimensions of the outside area.
   * 
   * @return A pair of floats representing the height and width of the area.
   */
  std::pair<float, float> GetDimension();

  /**
   * @brief Checks if the physical body of the area is null.
   * 
   * @return True if the body is null, false otherwise.
   */
  bool IsNullBody();

  /**
   * @brief Virtual function to handle contact with a vehicle.
   * 
   * This function can be overridden in derived classes to define specific behavior
   * when a vehicle comes into contact with the area.
   * 
   * @param car A pointer to the vehicle that made contact with the area.
   */
  virtual void OnContact(Vehicle* car);

 private:
  b2Body* body; ///< The Box2D body representing the area.
  float height_; ///< The height of the area.
  float width_; ///< The width of the area.
};

#endif // OUTSIDE_H
