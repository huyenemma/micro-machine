#include "./include/menu2.hpp"

GameMenu2::GameMenu2(sf::RenderWindow& window, const sf::Font& font, const sf::Texture& texture)
: BaseMenu(window, font, texture) {
    
  // Initialize menu items
  menuItems_[0].setFont(font_);
  menuItems_[0].setCharacterSize(50);
  menuItems_[0].setFillColor(sf::Color::Red);       // Highlighted by default
  menuItems_[0].setOutlineColor(sf::Color::Black);  // Black outline
  menuItems_[0].setOutlineThickness(2);
  menuItems_[0].setString("FOREST");
  menuItems_[0].setStyle(sf::Text::Bold);
  menuItems_[0].setPosition(sf::Vector2f(350, 300));

  menuItems_[1].setFont(font_);
  menuItems_[1].setCharacterSize(50);
  menuItems_[1].setFillColor(sf::Color::White);
  menuItems_[1].setOutlineColor(sf::Color::Black);  // Black outline
  menuItems_[1].setOutlineThickness(2);
  menuItems_[1].setString("OCEAN");
  menuItems_[1].setStyle(sf::Text::Bold);
  menuItems_[1].setPosition(sf::Vector2f(350, 350));

  menuItems_[2].setFont(font_);
  menuItems_[2].setCharacterSize(50);
  menuItems_[2].setFillColor(sf::Color::White);
  menuItems_[2].setOutlineColor(sf::Color::Black);  // Black outline
  menuItems_[2].setOutlineThickness(2);
  menuItems_[2].setString("EXIT");
  menuItems_[2].setStyle(sf::Text::Bold);
  menuItems_[2].setPosition(sf::Vector2f(350, 400));

  selectedItemIndex = 0;
}
