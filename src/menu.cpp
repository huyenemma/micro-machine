#include "./include/menu.hpp"

GameMenu::GameMenu(sf::RenderWindow& window): window_(window) {
    
    resourceManager_ = new ResourceManager();

    resourceManager_->LoadFromJson("../src/resources.json");
    const sf::Font& font_ = resourceManager_->GetFont("clockFont");

    const sf::Texture& texture = resourceManager_->GetImage("menu"); 
    sprite_.setTexture(texture);

    // Initialize menu items
    menuItems_[0].setFont(font_);
    menuItems_[0].setCharacterSize(50); 
    menuItems_[0].setFillColor(sf::Color::Red); // Highlighted by default
    menuItems_[0].setOutlineColor(sf::Color::Black); // Black outline
    menuItems_[0].setOutlineThickness(2);
    menuItems_[0].setString("ONE PLAYER");
    menuItems_[0].setStyle(sf::Text::Bold); 
    menuItems_[0].setPosition(sf::Vector2f(350, 300));

    menuItems_[1].setFont(font_);
    menuItems_[1].setCharacterSize(50); 
    menuItems_[1].setFillColor(sf::Color::White);
    menuItems_[1].setOutlineColor(sf::Color::Black); // Black outline
    menuItems_[1].setOutlineThickness(2);
    menuItems_[1].setString("TWO PLAYERS");
    menuItems_[1].setStyle(sf::Text::Bold); 
    menuItems_[1].setPosition(sf::Vector2f(350, 350));

    menuItems_[2].setFont(font_);
    menuItems_[2].setCharacterSize(50); 
    menuItems_[2].setFillColor(sf::Color::White);
    menuItems_[2].setOutlineColor(sf::Color::Black); // Black outline
    menuItems_[2].setOutlineThickness(2);
    menuItems_[2].setString("EXIT");
    menuItems_[2].setStyle(sf::Text::Bold); 
    menuItems_[2].setPosition(sf::Vector2f(350, 400));

    selectedItemIndex = 0;
}

void GameMenu::draw() {
    window_.draw(sprite_); 

    for (int i = 0; i < NUM_ITEMS; ++i) {
        window_.draw(menuItems_[i]);
    }
    window_.draw(startText_); 
}

void GameMenu::MoveUp() {
    if (selectedItemIndex - 1 >= 0) {
        menuItems_[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menuItems_[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void GameMenu::MoveDown() {
    if (selectedItemIndex + 1 < NUM_ITEMS) {
        menuItems_[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menuItems_[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

int GameMenu::GetPressedItem() const {
    return selectedItemIndex;
}