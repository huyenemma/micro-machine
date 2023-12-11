#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>

#include "box2dInclude.hpp"
#include "userDataPointer.hpp"
#include "vehicle.hpp"

using namespace BodyType;

/**
 * @brief Class representing an Obstacle that can interact with vehicles.
 */
class Obstacle : public sf::Drawable {
 public:
  /**
   * @brief Constructor for the Obstacle class.
   * @param world Pointer to the Box2D world.
   * @param position Initial position of the obstacle in the world.
   * @param radius Radius of the obstacle.
   * @param texture Reference to the SFML texture for the obstacle.
   */
  Obstacle(b2World* world, b2Vec2 position, float radius, const sf::Texture& texture);

  /**
   * @brief Get the position of the obstacle.
   * @return A pair representing the x and y coordinates of the obstacle.
   */
  std::pair<float, float> GetPosition() const;

  /**
   * @brief Delete the Box2D body associated with the obstacle.
   */
  void DeleteBody();

  /**
   * @brief Get the radius of the obstacle.
   * @return The radius of the obstacle.
   */
  float GetRadius();

  /**
   * @brief Check if the Box2D body associated with the obstacle is null.
   * @return True if the body is null, false otherwise.
   */
  bool IsNullBody();

  /**
   * @brief Implementation of the draw function for rendering the obstacle.
   * @param target Render target.
   * @param states Render states.
   */
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

  /**
   * @brief Function called when the obstacle comes into contact with a vehicle.
   * @param car Pointer to the vehicle in contact with the obstacle.
   */
  void OnContact(Vehicle* car);

 private:
  mutable sf::Sprite sprite_; ///< Sprite for rendering the obstacle.
  sf::Texture texture_;       ///< Texture for the obstacle.

  b2Body* body;   ///< Pointer to the Box2D body.
  float radius_;  ///< Radius of the obstacle.

  sf::SoundBuffer hitBuffer; ///< Sound buffer for the contact sound.
  sf::Sound hit;            ///< Sound played on contact.
};

#endif
