#include "winnerBoard.hpp"

WinnerBoard::WinnerBoard(sf::RenderWindow& window, const sf::Font& font, const sf::Texture& texture)
: BaseMenu(window, font, texture) {
    
    rescaleSprite(sprite_, 800.0f, 800.0f);
    
    text_.setFont(font);
    text_.setCharacterSize(35);
    text_.setFillColor(sf::Color::White);
    text_.setOutlineColor(sf::Color::Black);
    text_.setOutlineThickness(2); 
    text_.setStyle(sf::Text::Bold);

    menuItems_[0].setFont(font);
    menuItems_[0].setCharacterSize(40);
    menuItems_[0].setFillColor(sf::Color::Red);// Highlighted by default
    menuItems_[0].setOutlineColor(sf::Color::Black);
    menuItems_[0].setOutlineThickness(2); 
    menuItems_[0].setStyle(sf::Text::Bold);
    menuItems_[0].setString("Replay");
    menuItems_[0].setPosition(350, 650);

    menuItems_[1].setFont(font);
    menuItems_[1].setCharacterSize(40);
    menuItems_[1].setFillColor(sf::Color::White);
    menuItems_[1].setOutlineColor(sf::Color::Black);
    menuItems_[1].setOutlineThickness(2); 
    menuItems_[1].setStyle(sf::Text::Bold);
    menuItems_[1].setString("Exit");
    menuItems_[1].setPosition(350, 700);
}

void WinnerBoard::SetWinner(int playerNumber) {

    std::string player = playerNumber == 1 ? "BUFFALO" : "GOAT";
    std::string winnerMessage = "Player " + player + " Wins!";
    text_.setString(winnerMessage);

    sf::FloatRect textRect = text_.getLocalBounds();
    text_.setOrigin(textRect.left + textRect.width / 2.0f, 
                    textRect.top  + textRect.height / 2.0f);
    text_.setPosition(sf::Vector2f(window_.getSize().x / 2.0f, 400.0f)); // Vertically 400px from the top

}

void WinnerBoard::draw() {

    sf::RectangleShape backgroundBox;
    backgroundBox.setSize(sf::Vector2f(300, 35 + 20)); 
    backgroundBox.setFillColor(sf::Color(0, 0, 0, 128)); // Semi-transparent black
    backgroundBox.setOutlineColor(sf::Color::Black); 
    backgroundBox.setOutlineThickness(1);
    backgroundBox.setPosition(text_.getPosition().x - backgroundBox.getSize().x / 2.0f, 
                              text_.getPosition().y - text_.getCharacterSize());

    window_.draw(sprite_); 
    window_.draw(backgroundBox);
    window_.draw(text_);

    for (int i = 0; i < 2; ++i) {
        window_.draw(menuItems_[i]);
    }
}

