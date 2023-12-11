#ifndef WINNERBOARD_H
#define WINNERBOARD_H

#include "baseMenu.hpp"
#include "reScale.hpp"

class WinnerBoard : public BaseMenu {
public:
    enum MenuOption { REPLAY, EXIT, NUM_ITEMS };

    WinnerBoard(sf::RenderWindow& window, const sf::Font& font, const sf::Texture& texture);
    void SetWinner(int playerNumber);
    void draw() override;
private: 
    sf::Text text_; 
};

#endif // WINNERBOARD_H