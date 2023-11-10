#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include "../include/box2d/box2d.h"
#include "ox.hpp"


int main() {
    // Create the Box2D world
    b2Vec2 gravity(0.0f, 0.0f);
    b2World world(gravity);

    int FPS =24;
    float timeStep = 1.0f/FPS;      //the length of time passed to simulate (seconds)
    int velocityIterations = 8;   //how strongly to correct velocity
    int positionIterations = 3;   //how strongly to correct position

    // Create a window for rendering (SFML)
    sf::RenderWindow window(sf::VideoMode(1000, 1600), "Vehicle Test");

    // Create a Vehicle instance
    Ox ox(&world, 0, 0);

                    std::cout<<"1"<<std::endl;
    // Main loop
    while (window.isOpen()) {
        // Handle events
        sf::Event event;

                    std::cout<<"1"<<std::endl;
        while (window.pollEvent(event)) {
            
                    std::cout<<"1"<<std::endl;
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::W) {
                    // Apply a force when the Up arrow key is pressed
                    ox.ToggleForce(true);
                }
                else if (event.key.code == sf::Keyboard::D) {
                    // Apply a torque (rotation) when the Right arrow key is pressed
                    std::cout<<"KeyPressed"<<std::endl;
                    ox.Rotate(3);
                }else if (event.key.code == sf::Keyboard::E) {
                    ox.SuperSkill();
                }
            }
            else if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::W) {
                    // Stop applying force when the Up arrow key is released
                    ox.ToggleForce(false);
                }
            }
        }
        window.clear();
        // Update the vehicle
        ox.UpdateSpeed();
        
        world.Step( timeStep, velocityIterations, positionIterations);

        world.ClearForces();

        // Get the position of the vehicle
        std::pair<float, float> position = ox.GetPosition();

        
        // Clear the window
        
        sf::CircleShape triangle(30, 3);
        // Set the position of the square to match the vehicle's position
        triangle.setPosition(position.first, position.second);

        float angle = ox.GetAngle();
        triangle.setRotation(angle * 180.0f / b2_pi);

        // Draw the square at the vehicle's position
        window.draw(triangle);


        // Display the window
        window.display();
    }

    return 0;
}
