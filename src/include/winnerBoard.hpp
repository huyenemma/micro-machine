#ifndef WINNERBOARD_H
#define WINNERBOARD_H

#include <SFML/Graphics.hpp>
#include "reScale.hpp"

class WinnerBoard {
public:
    // Constructor
    WinnerBoard(sf::RenderWindow& window, const sf::Font& font, const sf::Texture& texture);

    // Set the winner information
    void SetWinner(int playerNumber, int player1Score, int player2Score);

    // Render the winner board
    void Draw();

private:
    sf::RenderWindow& window_;
    sf::Texture texture_; 
    sf::Sprite sprite_;
    sf::Font font_; 
    sf::Text text_; 
};

#endif // WINNERBOARD_H
