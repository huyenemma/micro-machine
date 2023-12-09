#include "./include/map.hpp"

Map::Map(const sf::Texture& texture) {
  sprite.setTexture(texture);
  rescaleSprite(sprite, 800.0f, 800.0f);
}

void Map::Draw(sf::RenderWindow& window) { window.draw(sprite); }