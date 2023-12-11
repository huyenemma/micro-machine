#ifndef GAMEMENU2_HPP
#define GAMEMENU2_HPP

#include <SFML/Graphics.hpp>
#include "baseMenu.hpp"

class GameMenu2: public BaseMenu {
public:
  enum MenuOption { FOREST, TWO_PLAYER, EXIT, NUM_ITEMS };

  GameMenu2(sf::RenderWindow& window, const sf::Font& font, const sf::Texture& texture);
};

#endif