#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Vehicle.h"  // Assuming Vehicle class is defined in Vehicle.h

int main() {
    // Create the Box2D world
    b2Vec2 gravity(0.0f, 0.0f);
    b2World world(gravity);

    // Create a window for rendering (SFML)
    sf::RenderWindow window(sf::VideoMode(800, 600), "Vehicle Test");

    // Create a Vehicle instance
    Vehicle vehicle(&world, 0, 0);

    // Main loop
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    // Apply a force when the Up arrow key is pressed
                    vehicle.ToggleForce(true);
                }
                else if (event.key.code == sf::Keyboard::Right) {
                    // Apply a torque (rotation) when the Right arrow key is pressed
                    vehicle.Rotate(10);
                }
            }
            else if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Up) {
                    // Stop applying force when the Up arrow key is released
                    vehicle.ToggleForce(false);
                }
            }
        }

        // Update the vehicle
        vehicle.UpdateSpeed();

        // Get the position of the vehicle
        std::pair<float, float> position = vehicle.GetPosition();

        // Clear the window
        window.clear();

        // Set the position of the square to match the vehicle's position
        square.setPosition(position.first, position.second);

        // Draw the square at the vehicle's position
        window.draw(square);


        // Display the window
        window.display();
    }

    return 0;
}
