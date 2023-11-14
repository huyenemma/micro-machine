#include "./include/game.hpp"


Game::Game(): window(sf::VideoMode(800, 600), "Mirco machine"), isRunning(false) {
    world = new World(b2Vec2(0.0f, 0.0f));
};

Game::~Game() {
    delete world; 
}

void Game::Initialize() { 
    Vehicle* vehicle = new Vehicle(world->GetPhysicWorld(), 0, 0);
    world->AddVehicle(vehicle);
}

void Game::Run() {
  isRunning = true;
  sf::Clock clock;
  while (window.isOpen() && isRunning) {
    sf::Time deltaTime = clock.restart();
    ProcessEvents();
    Update(deltaTime);
    Render();
  }
}

void Game::ProcessEvents() {
  sf::Event event;
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) window.close();
  }
}

void Game::HandleInput() {
  const float torque = 5.0f;
  Vehicle* vehicle = world->GetVehicle()[0];
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    // Move car
    vehicle->ToggleForce(true);
    vehicle->UpdateSpeed();
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    // turn right
    vehicle->Rotate(torque);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    vehicle->Rotate(-torque);
  } else {
    // Stop the paddle when no key is pressed
    vehicle->ToggleForce(false);
  }
}

void Game::Update(sf::Time deltaTime) {
  // Update car position
  HandleInput();
  world->Update(deltaTime.asSeconds(), velocityIterations, positionIterations);
}

void Game::Render() {
    window.clear();
    if (!world->GetVehicle().empty()) {
        for (auto vehicle : world->GetVehicle()) {
            window.draw(*vehicle);
        }
    }
    window.display();
}