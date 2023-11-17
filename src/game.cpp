#include "./include/game.hpp"


Game::Game(): window(sf::VideoMode(800, 800), "Mirco machine"), isRunning(false) {
    world = new World(b2Vec2(0.0f, 0.0f));
    map = new Map("../img/finalmap.png");
};

Game::~Game() {
    delete world; 
    delete map;
}

using namespace NegativeBuff;
void Game::Initialize() { 
    Vehicle* vehicle = new Vehicle(world->GetPhysicWorld(), 136.0f / SCALE, 120.0f / SCALE);
    MyContactListener* contactListener =new MyContactListener();
    world->GetPhysicWorld()->SetContactListener(contactListener);
    ReverseMushroom* buff = new ReverseMushroom("test", 2, 3);

    Collectable* collectable = new Collectable(world->GetPhysicWorld(), b2Vec2(400.0f / SCALE, 400.0f / SCALE), 50.0f/SCALE, buff);

    world->AddVehicle(vehicle);
    world->AddCollectable(collectable);
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
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::HandleInput() {
    const float torque = 5.0f;  
    Vehicle* vehicle = world->GetVehicle()[0];
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        // Move car
        vehicle->ToggleForce(true);
        vehicle->Update();
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
    map->Draw(window);
    if (!world->GetVehicle().empty()) {
        for (auto vehicle : world->GetVehicle()) {
            window.draw(*vehicle);
        }
    }

    if (!world->GetCollectable().empty()) {
        for (auto collectable : world->GetCollectable()){
            window.draw(*collectable);
        }
    }
    window.display();
}