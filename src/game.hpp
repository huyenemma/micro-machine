#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "../libs/include/Box2d/box2d.h"
#include "vehicle.hpp"

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void handleInput(); 

    sf::RenderWindow window;
    b2World world;
    Vehicle vehicle;  
};

#endif