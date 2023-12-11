/**
 * @file map.h
 * @brief Map class header.
 *
 * This file contains the definition of the Map class, which is used for handling
 * the game map in the graphical interface. It involves loading, scaling, and drawing 
 * the map texture using SFML.
 */

#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "reScale.hpp"

/**
 * @class Map
 * @brief Manages the game map's graphical representation.
 *
 * The Map class is responsible for handling the visual aspects of the game map.
 * It loads the map texture, handles its scaling, and provides functionality for
 * rendering the map on the game window.
 */
class Map {
 public:
  /**
   * @brief Constructs a Map object with a given texture.
   * 
   * Loads the texture for the map and prepares it for rendering.
   * 
   * @param texture The SFML texture object representing the game map.
   */
  Map(const sf::Texture& texture);

  /**
   * @brief Draws the map onto the game window.
   * 
   * Renders the map onto the provided SFML RenderWindow object. This method
   * should be called every frame to display the map in the game window.
   * 
   * @param window The SFML RenderWindow object where the map will be drawn.
   */
  void Draw(sf::RenderWindow& window);

 private:
  sf::Texture texture; ///< Texture object for the map's graphical representation.
  sf::Sprite sprite;   ///< Sprite object used to draw the texture on the window.
};

#endif // MAP_H
