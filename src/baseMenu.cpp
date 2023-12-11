#include "baseMenu.hpp"

BaseMenu::BaseMenu(sf::RenderWindow& window, const sf::Font& font, const sf::Texture& texture)
    : window_(window), font_(font), texture_(texture), selectedItemIndex(0) {
    sprite_.setTexture(texture_);
}

void BaseMenu::draw() {
    window_.draw(sprite_); 
    for (auto& menuItem : menuItems_) {
        window_.draw(menuItem);
    }
}

void BaseMenu::MoveUp() {
    if (selectedItemIndex > 0) {
        menuItems_[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menuItems_[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void BaseMenu::MoveDown() {
    if (selectedItemIndex + 1 < NUM_ITEMS) {
        menuItems_[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menuItems_[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

int BaseMenu::GetPressedItem() const {
    return selectedItemIndex;
}