#include "./include/game.hpp"


Game::Game(): window(sf::VideoMode(800, 800), "Mirco machine"), isRunning(false) {
    world = new World(b2Vec2(0.0f, 0.0f));
    map = new Map("../img/finalMap.png");
};

Game::~Game() {
    delete world; 
    delete map;
}

using namespace NegativeBuff;

void Game::Initialize() { 
    Vehicle* vehicle = new Vehicle(world->GetPhysicWorld(), 136.0f / SCALE, 120.0f / SCALE, "../img/buffalo.png");
    MyContactListener* contactListener =new MyContactListener();
    world->GetPhysicWorld()->SetContactListener(contactListener);
    
    ReverseMushroom* buff = new ReverseMushroom("test", 2, 3, "../img/buffalo1.png");

    Collectable* collectable = new Collectable(world->GetPhysicWorld(), b2Vec2(400.0f / SCALE, 400.0f / SCALE), 50.0f/SCALE, buff, "../img/buffalo1.png");

    world->AddVehicle(vehicle);
    world->AddCollectable(collectable);

    AddBoundaries();
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

void Game::AddBoundaries() {
    float worldWidth = 800.0f / SCALE; // Width of your window in Box2D units
    float worldHeight = 800.0f / SCALE; // Height of your window in Box2D units
    float thickness = 0.0005f / SCALE; // Thickness of the boundary walls

    // Define the positions and sizes of the boundary walls
    b2Vec2 topWallPos(worldWidth / 2, thickness / 2);
    b2Vec2 bottomWallPos(worldWidth / 2, worldHeight - thickness / 2);
    b2Vec2 leftWallPos(thickness / 2, worldHeight / 2);
    b2Vec2 rightWallPos(worldWidth - thickness / 2, worldHeight / 2);

    b2Vec2 horizontalSize(worldWidth, thickness);
    b2Vec2 verticalSize(thickness, worldHeight);

    // Create each wall as a static body
    CreateWall(topWallPos, horizontalSize);
    CreateWall(bottomWallPos, horizontalSize);
    CreateWall(leftWallPos, verticalSize);
    CreateWall(rightWallPos, verticalSize);
}

void Game::CreateWall(const b2Vec2& position, const b2Vec2& size) {
    b2BodyDef bodyDef;
    bodyDef.position = position;
    bodyDef.type = b2_staticBody;
    b2Body* body = world->GetPhysicWorld()->CreateBody(&bodyDef);

    b2PolygonShape shape;
    shape.SetAsBox(size.x / 2, size.y / 2);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    body->CreateFixture(&fixtureDef);
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