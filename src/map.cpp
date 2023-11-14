#include "./include/map.hpp"

Map::Map(const std::string& texturePath) {
  if (!texture.loadFromFile(texturePath)) {
    // Handle the error, e.g., by throwing an exception or logging an error message
    std::cerr << "Failed to load map texture!" << std::endl;
  }
  sprite.setTexture(texture);
  rescaleSprite(sprite, 800.0f, 800.0f);
}

    
void Map::Draw(sf::RenderWindow& window) {
  window.draw(sprite);
}