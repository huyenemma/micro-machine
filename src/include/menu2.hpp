#include <SFML/Graphics.hpp>

#include "resourceManager.hpp"

class GameMenu2 {
 public:
  enum MenuOption { ONE_PLAYER, TWO_PLAYER, EXIT, NUM_ITEMS };

  GameMenu2(sf::RenderWindow& window);
  void draw();
  void MoveUp();
  void MoveDown();
  int GetPressedItem() const;

 private:
  int selectedItemIndex;
  sf::Text menuItems_[NUM_ITEMS];
  sf::Text startText_;
  sf::RenderWindow& window_;
  ResourceManager* resourceManager_;
  sf::Sprite sprite_;
};