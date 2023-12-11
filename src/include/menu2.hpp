/**
 * @file menu2.hpp
 * @brief GameMenu2 class header.
 *
 * This file contains the definition of the GameMenu2 class, which is a specialized
 * version of the BaseMenu for a secondary game menu. This menu offers different
 * environment choices for the game, like forest and ocean themes.
 */

#ifndef GAMEMENU2_HPP
#define GAMEMENU2_HPP

#include <SFML/Graphics.hpp>
#include "baseMenu.hpp"

/**
 * @class GameMenu2
 * @brief Manages the secondary game menu interface.
 *
 * The GameMenu2 class extends the BaseMenu class to provide a specific interface for the
 * secondary game menu. It includes options for choosing different game environments or
 * exiting the game.
 */
class GameMenu2: public BaseMenu {
public:
  /**
   * @enum MenuOption
   * @brief Defines menu options available in the secondary game menu.
   */
  enum MenuOption { FOREST, OCEAN, EXIT, NUM_ITEMS };

  /**
   * @brief Constructs a GameMenu2 object with a given window, font, and texture.
   * 
   * Initializes the secondary game menu with specified appearance and functionality,
   * setting up the menu items and their properties specific to game environment selection.
   * 
   * @param window The SFML RenderWindow object where the menu will be drawn.
   * @param font The SFML Font object used to render text in the menu.
   * @param texture The SFML Texture object used for the menu's background.
   */
  GameMenu2(sf::RenderWindow& window, const sf::Font& font, const sf::Texture& texture);
};

#endif // GAMEMENU2_HPP
