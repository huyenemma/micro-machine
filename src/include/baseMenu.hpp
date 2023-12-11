/**
 * @file BaseMenu.hpp
 * @brief Header file for BaseMenu class.
 *
 * The BaseMenu class provides a basic structure for menu interfaces in SFML.
 * It includes functions for drawing the menu, navigating through menu items, 
 * and getting the currently selected item. This class is designed to be 
 * inherited by more specific menu types, where you can override the drawing 
 * function and add specific functionalities.
 */

#ifndef BASE_MENU_HPP
#define BASE_MENU_HPP

#include <SFML/Graphics.hpp>
#include <vector>

/**
 * @def NUM_ITEMS
 * @brief Defines the number of items in the menu.
 */
const int NUM_ITEMS = 3; 

/**
 * @class BaseMenu
 * @brief A base class for creating menus in an SFML application.
 *
 * BaseMenu is intended to be a parent class for specific menu types. It handles
 * basic functionalities like rendering menu items, navigating through them, and 
 * keeping track of the currently selected item.
 */
class BaseMenu {
public:

    /**
     * @brief Constructor for BaseMenu.
     * @param window A reference to the SFML RenderWindow object.
     * @param font The font used to display menu items.
     * @param texture The texture used for the menu background.
     */
    BaseMenu(sf::RenderWindow& window, const sf::Font& font, const sf::Texture& texture);

    /**
     * @brief Virtual destructor for BaseMenu.
     */
    virtual ~BaseMenu() {};

    /**
     * @brief Virtual function to draw the menu to the window.
     * 
     * This function should be overridden by derived classes to provide 
     * specific drawing implementations.
     */
    virtual void draw();

    /**
     * @brief Move the selection up in the menu.
     * 
     * If the first item is selected, this function does nothing.
     */
    void MoveUp();

    /**
     * @brief Move the selection down in the menu.
     * 
     * If the last item is selected, this function does nothing.
     */
    void MoveDown();

    /**
     * @brief Get the index of the currently selected menu item.
     * @return The index of the selected item.
     */
    int GetPressedItem() const;

protected:
    sf::Text menuItems_[NUM_ITEMS];  ///< Array of Text objects for menu items.
    sf::RenderWindow& window_;       ///< Reference to the SFML RenderWindow.
    sf::Font font_;                  ///< Font used for menu items.
    sf::Texture texture_;            ///< Texture used for the menu background.
    sf::Sprite sprite_;              ///< Sprite used for the menu background.
    std::size_t selectedItemIndex;   ///< Index of the currently selected menu item.
    
};

#endif // BASE_MENU_HPP