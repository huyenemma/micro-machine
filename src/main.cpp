#include <stdio.h>

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../libs/include/Box2d/box2d.h"
#include "collectable.hpp"
#include "obstacle.hpp"
#include "vehicle.hpp"
#include "ContactListener.hpp"
#include "collectableGood.hpp"
#include "collectableBad.hpp"

int main() {
  // Create the Box2D world
  b2Vec2 gravity(0.0f, 0.0f);
  b2World world(gravity);

  int FPS = 24;
  float timeStep =
      1.0f / FPS;  // the length of time passed to simulate (seconds)
  int velocityIterations = 8;  // how strongly to correct velocity
  int positionIterations = 3;  // how strongly to correct position

  // Create a window for rendering (SFML)
  sf::RenderWindow window(sf::VideoMode(2000, 1600), "Vehicle Test");

  // Create a Vehicle instance
  Vehicle vehicle(&world, 0, 0);

  // Create a test Obstacle object
  Obstacle obstacle(&world, b2Vec2(5.f, 10.f), 5.f);

  //Create a bad collectable object
  CollectableBad collectable(&world, b2Vec2(100.f, 100.f), 20.f);

  // Main loop
  while (window.isOpen()) {
    // Handle eventss
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      } else if (event.type == sf::Event::KeyPressed)  {
        if (event.key.code == sf::Keyboard::W) {
          // Apply a force when the Up arrow key is pressed
          vehicle.ToggleForce(true);
        } else if (event.key.code == sf::Keyboard::D) {
          // Apply a torque (rotation) when the Right arrow key is pressed
          vehicle.Rotate(10);
        }
      } else if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::W) {
          // Stop applying force when the Up arrow key is released
          vehicle.ToggleForce(false);
        }
      }
    }
    window.clear();
    // Update the vehicle
    vehicle.UpdateSpeed();

    world.Step(timeStep, velocityIterations, positionIterations);

    world.ClearForces();

    // Get the position of the vehicle
    std::pair<float, float> position = vehicle.GetPosition();

    // Clear the window

    sf::CircleShape triangle(30, 3);
    // Set the position of the square to match the vehicle's position
    triangle.setPosition(position.first, position.second);

    float angle = vehicle.GetAngle();
    triangle.setRotation(angle * 180.0f / b2_pi);

    // Draw the square at the vehicle's position
    window.draw(triangle);


    //Draw collectable
    if (!collectable.IsNullBody()){
      std::pair<float, float> positionC = collectable.GetPosition();
      sf::CircleShape circle;
      circle.setRadius(collectable.GetRadius());
      circle.setPosition(positionC.first, positionC.second);
      circle.setFillColor(sf::Color::Green);
      window.draw(circle);
      collectable.DeleteBody();
    }
    

    //setting contact listener
    MyContactListener contactListener;
    world.SetContactListener(&contactListener);

    // Display the window
    window.display();
  }

  return 0;
}
