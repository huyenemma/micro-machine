#include "winnerBoard.hpp"

WinnerBoard::WinnerBoard(sf::RenderWindow& window, const sf::Font& font, const sf::Texture& texture): 
    window_(window), font_(font), texture_(texture) {
    
    sprite_.setTexture(texture_);
    rescaleSprite(sprite_, 800.0f, 800.0f);
    text_.setFont(font_);
    text_.setCharacterSize(35);
    text_.setFillColor(sf::Color::White);
    text_.setOutlineColor(sf::Color::Black);
    text_.setOutlineThickness(2); 
    text_.setStyle(sf::Text::Bold);
}

void WinnerBoard::SetWinner(int playerNumber, int player1Score, int player2Score) {

    std::string player = playerNumber == 1 ? "BUFFALO" : "GOAT";
    std::string winnerMessage = "Player " + player + " Wins!";
    text_.setString(winnerMessage);

    sf::FloatRect textRect = text_.getLocalBounds();
    text_.setOrigin(textRect.left + textRect.width / 2.0f, 
                    textRect.top  + textRect.height / 2.0f);
    text_.setPosition(sf::Vector2f(window_.getSize().x / 2.0f, 400.0f)); // Vertically 400px from the top

}

void WinnerBoard::Draw() {

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
}
