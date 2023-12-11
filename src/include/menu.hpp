#ifndef GAMEMENU_HPP
#define GAMEMENU_HPP

#include <SFML/Graphics.hpp>
#include "baseMenu.hpp"

class GameMenu: public BaseMenu {
public:
  enum MenuOption { ONE_PLAYER, TWO_PLAYER, EXIT, NUM_ITEMS };

  GameMenu(sf::RenderWindow& window, const sf::Font& font, const sf::Texture& texture);
};

#endif