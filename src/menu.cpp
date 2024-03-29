#include "./include/menu.hpp"

GameMenu::GameMenu(sf::RenderWindow& window, const sf::Font& font, const sf::Texture& texture)
: BaseMenu(window, font, texture) {
    sf::Text menuItem; 
    
    // Initialize menu items
    menuItems_[0].setFont(font);
    menuItems_[0].setCharacterSize(50); 
    menuItems_[0].setFillColor(sf::Color::Red); // Highlighted by default
    menuItems_[0].setOutlineColor(sf::Color::Black); // Black outline
    menuItems_[0].setOutlineThickness(2);
    menuItems_[0].setString("ONE PLAYER");
    menuItems_[0].setStyle(sf::Text::Bold); 
    menuItems_[0].setPosition(sf::Vector2f(320, 300));

    menuItems_[1].setFont(font);
    menuItems_[1].setCharacterSize(50); 
    menuItems_[1].setFillColor(sf::Color::White);
    menuItems_[1].setOutlineColor(sf::Color::Black); // Black outline
    menuItems_[1].setOutlineThickness(2);
    menuItems_[1].setString("TWO PLAYERS");
    menuItems_[1].setStyle(sf::Text::Bold); 
    menuItems_[1].setPosition(sf::Vector2f(320, 350));

    menuItems_[2].setFont(font);
    menuItems_[2].setCharacterSize(50); 
    menuItems_[2].setFillColor(sf::Color::White);
    menuItems_[2].setOutlineColor(sf::Color::Black); // Black outline
    menuItems_[2].setOutlineThickness(2);
    menuItems_[2].setString("EXIT");
    menuItems_[2].setStyle(sf::Text::Bold); 
    menuItems_[2].setPosition(sf::Vector2f(320, 400));

    selectedItemIndex = 0;
}