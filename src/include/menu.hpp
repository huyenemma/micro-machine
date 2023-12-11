/**
 * @file menu.hpp
 * @brief GameMenu class header.
 *
 * This file contains the definition of the GameMenu class, which is used for handling
 * the main game menu interface. It extends from the BaseMenu class, providing specific
 * options for the main game menu.
 */

#ifndef GAMEMENU_HPP
#define GAMEMENU_HPP

#include <SFML/Graphics.hpp>
#include "baseMenu.hpp"

/**
 * @class GameMenu
 * @brief Manages the main game menu interface.
 *
 * The GameMenu class extends the BaseMenu class to provide a specific interface for the
 * main game menu. It includes options for starting a single player or two-player game,
 * or exiting the game.
 */
class GameMenu: public BaseMenu {
public:
  /**
   * @enum MenuOption
   * @brief Defines menu options available in the game menu.
   */
  enum MenuOption { ONE_PLAYER, TWO_PLAYER, EXIT, NUM_ITEMS };

  /**
   * @brief Constructs a GameMenu object with a given window, font, and texture.
   * 
   * Initializes the game menu with specified appearance and functionality, setting up
   * the menu items and their properties.
   * 
   * @param window The SFML RenderWindow object where the menu will be drawn.
   * @param font The SFML Font object used to render text in the menu.
   * @param texture The SFML Texture object used for the menu's background.
   */
  GameMenu(sf::RenderWindow& window, const sf::Font& font, const sf::Texture& texture);
};

#endif // GAMEMENU_HPP
