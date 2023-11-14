#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "reScale.hpp"

class Map {
public:
    // Constructor that loads the texture from a file
    Map(const std::string& texturePath);

    // Method to draw the map
    void Draw(sf::RenderWindow& window);

private:
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif
