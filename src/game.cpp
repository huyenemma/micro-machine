#include "game.hpp"

Game::Game() : window(sf::VideoMode(800, 600), "Mirco machine"),
               world(b2Vec2(0.f, 9.8f)),
               vehicle(world, 5, 5),
{};

void Game::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::handleInput() {
    const float speed = 10.0f; // Adjust the speed as needed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        // Move car
        vehicle.ToggleForce(true);
        vehicle.UpdateSpeed();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        // turn right 
        vehicle.Rotate(float torque = 1);
    } else {
        // Stop the paddle when no key is pressed
        vehicle.ToggleForce(false);
    }
}

void Game::update(sf::Time deltaTime) {
    // Update car position
    handleInput();
    world.Step(deltaTime.asSeconds(), 8, 3);
}

void Game::render() {
    window.clear();
    window.draw(vehicle);
    window.display();
}