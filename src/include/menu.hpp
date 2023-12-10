#ifndef GAMEMENU_HPP
#define GAMEMENU_HPP

#include <SFML/Graphics.hpp>

#include "resourceManager.hpp"

class GameMenu {
 public:
  enum MenuOption { ONE_PLAYER, TWO_PLAYER, EXIT, NUM_ITEMS };

  GameMenu(sf::RenderWindow& window, const sf::Font& font, const sf::Texture& texture);
  void draw();
  void MoveUp();
  void MoveDown();
  int GetPressedItem() const;

 private:
  int selectedItemIndex;
  sf::Text menuItems_[NUM_ITEMS];
  sf::Text startText_;
  sf::RenderWindow& window_;
  //ResourceManager* resourceManager_;
  sf::Texture texture_; 
  sf::Sprite sprite_;
  sf::Font font_; 
};

#endif