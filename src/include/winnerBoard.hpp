/**
 * @file WinnerBoard.hpp
 * @brief Header for the WinnerBoard class.
 *
 * This file contains the definition of the WinnerBoard class, which is used to display the winner of the game and provide options for replay or exit.
 */

#ifndef WINNERBOARD_H
#define WINNERBOARD_H

#include "baseMenu.hpp"
#include "reScale.hpp"

/**
 * @class WinnerBoard
 * @brief A class to manage and display the winning screen of the game.
 *
 * WinnerBoard is a subclass of BaseMenu. It manages the display of the winner's information 
 * and provides menu options for replaying the game or exiting.
 */
class WinnerBoard : public BaseMenu {
public:
    /**
     * @enum MenuOption
     * @brief Menu options for the WinnerBoard.
     */
    enum MenuOption { REPLAY, EXIT, NUM_ITEMS };

    /**
     * @brief Constructs a WinnerBoard object.
     *
     * @param window Reference to the SFML RenderWindow.
     * @param font The font used for displaying text.
     * @param texture The background texture for the winner board.
     */
    WinnerBoard(sf::RenderWindow& window, const sf::Font& font, const sf::Texture& texture);

    /**
     * @brief Sets the winner's information.
     *
     * @param playerNumber The player number of the winner.
     */
    void SetWinner(int playerNumber);

    /**
     * @brief Draws the winner board on the screen.
     *
     * Overrides the draw method from BaseMenu to include the winner's information and options.
     */
    void draw() override;

private: 
    sf::Text text_; ///< Text displaying the winner's information.
};

#endif // WINNERBOARD_H
