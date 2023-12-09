#ifndef COLLECTABLE_H
#define COLLECTABLE_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "box2dInclude.hpp"
#include "buff.hpp"
#include "constant.hpp"
#include "userDataPointer.hpp"
#include "vehicle.hpp"

using namespace BodyType;

/**
 * @class Collectable
 * @brief Represents a collectable item in the game.
 * @details Inherits from sf::Drawable and provides functionality for handling
 * collectables.
 */
class Collectable : public sf::Drawable {
 public:
  /**
   * @brief Constructs a Collectable object.
   * @param world The Box2D world in which the collectable exists.
   * @param position The initial position of the collectable.
   * @param radius The radius of the collectable.
   * @param buff A pointer to the Buff associated with the collectable.
   * @param texture The texture used for rendering the collectable.
   */
  Collectable(b2World* world, b2Vec2 position, float radius, Buff* buff,
              const sf::Texture& texture);

  /**
   * @brief Gets the current position of the collectable.
   * @return A pair representing the x and y coordinates of the collectable's
   * position.
   */
  std::pair<float, float> GetPosition() const;

  /**
   * @brief Deletes the Box2D body associated with the collectable.
   */
  void DeleteBody();

  /**
   * @brief Gets the radius of the collectable.
   * @return The radius of the collectable.
   */
  float GetRadius();

  /**
   * @brief Checks if the collectable has a null body.
   * @return True if the collectable has a null body, false otherwise.
   */
  bool IsNullBody();

  /**
   * @brief Marks the collectable to be deleted.
   */
  void setDelete();

  /**
   * @brief Gets the delete status of the collectable.
   * @return True if the collectable is marked to be deleted, false otherwise.
   */
  bool getDelete();

  /**
   * @brief Handles the contact event with a Vehicle.
   * @param car A pointer to the Vehicle involved in the contact.
   */
  void OnContact(Vehicle* car);

  /**
   * @brief Draws the collectable on the target.
   * @param target The rendering target.
   * @param states The rendering states.
   */
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;

 private:
  mutable sf::Sprite sprite_;  ///< The sprite used for rendering.
  sf::Texture texture_;        ///< The texture used for rendering.
  Buff* buff;     ///< A pointer to the Buff associated with the collectable.
  b2Body* body;   ///< The Box2D body of the collectable.
  float radius_;  ///< The radius of the collectable.
  bool toBeDeleted =
      false;  ///< Flag indicating whether the collectable should be deleted.

  sf::SoundBuffer hitBuffer;  ///< Sound buffer for hit sound.
  sf::Sound hit;              ///< Sound played on contact.
};

#endif
