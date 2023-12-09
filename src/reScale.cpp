#include "./include/reScale.hpp"

void rescaleSprite(sf::Sprite& sprite, float desiredWidth,
                   float desiredHeight) {
  // Get the original size of the texture
  sf::Vector2u textureSize = sprite.getTexture()->getSize();

  // Calculate the scale factors
  float scaleX = desiredWidth / static_cast<float>(textureSize.x);
  float scaleY = desiredHeight / static_cast<float>(textureSize.y);

  // Set the scale of the sprite
  sprite.setScale(scaleX, scaleY);
};