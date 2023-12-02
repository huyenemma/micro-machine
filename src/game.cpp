#include "./include/game.hpp"

Game::Game()
    : window_(sf::VideoMode(800, 800), "Mirco machine"), 
    isRunning_(false),
    currentState_(GameState::MENU),
    menu_(window_) {

  world_ = new World(b2Vec2(0.0f, 0.0f));
  resourceManager_ = new ResourceManager(); 
};

Game::~Game() {
  delete world_;
  delete resourceManager_;
  delete counterClock_;  
  delete map_;
}

using namespace NegativeBuff;
void Game::Initialize() {
  
  resourceManager_->LoadFromJson("../src/resources.json");

  const sf::Font& font = resourceManager_->GetFont("clockFont"); 
  counterClock_ = new RealTime(2, font);
  counterClock_->SetUp();

  const sf::Texture& map_Texture = resourceManager_->GetImage("forest");
  map_ = new Map(map_Texture); 

  const sf::Texture& oxTexture = resourceManager_->GetImage("buffalo");

  Ox* ox = new Ox(world_->GetPhysicWorld(), 136.0f / SCALE, 120.0f / SCALE,
                  oxTexture);

  Ox* ox2 = new Ox(world_->GetPhysicWorld(), 200.0f / SCALE, 120.0f / SCALE,
                   oxTexture);

  MyContactListener* contactListener = new MyContactListener();
  world_->GetPhysicWorld()->SetContactListener(contactListener);

  /*
  ReverseMushroom* buff = new ReverseMushroom("test", 2, 3);

  CrazyRotate* buff2 = new CrazyRotate("rotate", 10, 2, 2);

  Obstacle* obstacle = new Obstacle(world_->GetPhysicworld_(),
                                  b2Vec2(140.0f / SCALE, 150.0f / SCALE),
                                  50.0f / SCALE, "../img/rock.png");

  Collectable* collectable2 = new Collectable(world_->GetPhysicworld_(),
  b2Vec2(440.0f / SCALE, 440.0f / SCALE),50.0f/SCALE, buff2,
  "../img/mushroom.png");

  world_->AddCollectable(collectable2);
  world_->AddObstacle(obstacle);
  */
  // world_->AddCollectable(collectable);
  world_->AddVehicle(ox);
  player1 = ox;
  // world->AddCollectable(collectable);

  world_->AddVehicle(ox2);
  player2 = ox2;

  // Need to update when selecting number of players
  playerCount = 2;
  AddBoundaries();

  //add background sound
  if (!backgroundBuffer.loadFromFile("../sound/background.mp3")){
      std::cerr << "Error loading sound files!" << std::endl;
  }

  background.setBuffer(backgroundBuffer);
  background.setLoop(true);
  background.setVolume(50);
  background.play();

  //Set sound effect
  if (!runBuffer.loadFromFile("../sound/step.mp3")){
      std::cerr << "Error loading sound files!" << std::endl;
  }

  run.setBuffer(runBuffer);
  run.setVolume(40);
}

void Game::Run() {
  isRunning_ = true; 
  sf::Clock clock;
  
  const sf::Time targetFrameTime = sf::seconds(1.0f / 24.0f);

  while (window_.isOpen() && isRunning_ ) {
    sf::Time deltaTime = clock.restart();
    if (currentState_ == GameState::MENU) {
      HandleMenuInput(); 
      RenderMenu(); 
    } 
    else if (currentState_ == GameState::PLAYING && !counterClock_->IsTimeUp()) {
      background.play(); 
      ProcessEvents();
      Update(deltaTime);
      RenderGame();
    }

    sf::Time elapsedTime = clock.getElapsedTime();
      
      if (elapsedTime < targetFrameTime) {
          sf::sleep(targetFrameTime - elapsedTime);
      }
  }
}

void Game::ProcessEvents() {
  sf::Event event;
  while (window_.pollEvent(event)) {
    if (event.type == sf::Event::Closed) window_.close();
  }
}

void Game::HandleInput() {
  const float angle = 4.0f;
  Vehicle* vehicle = world_->GetVehicle()[0];
  
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    // Move car
    run.play();
    vehicle->ToggleForce(true);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    // turn right
    vehicle->Rotate(angle);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    vehicle->Rotate(-angle);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
    //vehicle->SuperSkill();
  } else {
    vehicle->ToggleForce(false);
  }

  vehicle->Update();

  if (playerCount == 2) {
    Vehicle* vehicle2 = world_->GetVehicle()[1];
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
      // Move car
      vehicle2->ToggleForce(true);

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
      // turn right
      vehicle2->Rotate(angle);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
      vehicle2->Rotate(-angle);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
      vehicle2->SuperSkill();
    } else {
      vehicle2->ToggleForce(false);
    }
    vehicle2->Update();
  }
}

void Game::Update(sf::Time deltaTime) {
  // Update car position
  HandleInput();
  world_->Update(deltaTime.asSeconds(), velocityIterations, positionIterations);
  counterClock_->Update(); 
}

void Game::RenderGame() {
  
  window_.clear();
  map_->Draw(window_);
 
  // Define the view
  if (playerCount == 1) {
    sf::View view;
    view.setCenter(sf::Vector2f(player1->GetPosition().first * SCALE,
                                player1->GetPosition().second * SCALE));
    view.zoom(zoomCoef);
    window_.setView(view);
    DrawGameWorld();
  }

  else if (playerCount == 2) {
    sf::View view1;
    view1.setCenter(sf::Vector2f(player1->GetPosition().first * SCALE,
                                 player1->GetPosition().second * SCALE));
    view1.zoom(zoomCoef);
    view1.setViewport(sf::FloatRect(0.f, 0.f, 0.5f, 1.f));
    window_.setView(view1);
    DrawGameWorld();

    sf::View view2;
    view2.setCenter(sf::Vector2f(player2->GetPosition().first * SCALE,
                                 player2->GetPosition().second * SCALE));
    view2.zoom(zoomCoef);
    view2.setViewport(sf::FloatRect(0.5f, 0.f, 0.5f, 1.f));
    window_.setView(view2);
    DrawGameWorld();
  }

  window_.display();
}

void Game::DrawGameWorld() {

  map_->Draw(window_);

  if (!world_->GetVehicle().empty()) {
    for (auto vehicle : world_->GetVehicle()) {
      window_.draw(*vehicle);
    }
  }

  if (!world_->GetCollectable().empty()) {
    for (auto collectable : world_->GetCollectable()) {
      if (!collectable->IsNullBody()) {
        window_.draw(*collectable);
        collectable->DeleteBody();
      }
    }
  }

  if (!world_->GetObstacle().empty()) {
    for (auto obstacle : world_->GetObstacle()) {
      window_.draw(*obstacle);
    }
  }

  counterClock_->Draw(window_);

  //window_.display();
}

void Game::HandleMenuInput() {
  sf::Event event;
  while (window_.pollEvent(event)) {
    switch (event.type) {
      case sf::Event::KeyPressed:
        switch (event.key.code) {
          case sf::Keyboard::Up:
            menu_.MoveUp();
            break;
          case sf::Keyboard::Down:
            menu_.MoveDown();
            break;
          case sf::Keyboard::Enter:
            int selectedItem = menu_.GetPressedItem();
            if (selectedItem == GameMenu::ONE_PLAYER) {
                playerCount = 1;
                currentState_ = GameState::PLAYING;
                Initialize(); 
            } else if (selectedItem == GameMenu::TWO_PLAYER) {
                playerCount = 2;
                currentState_ = GameState::PLAYING;
                Initialize(); 
            } else if (selectedItem == GameMenu::EXIT) {
                window_.close();
            }
            break;
        }
        break;
      case sf::Event::Closed:
          window_.close();
          break;
    }
  }
}

void Game::RenderMenu() {
  window_.clear();
  menu_.draw();
  window_.display();
}

void Game::AddBoundaries() {
  float world_Width = 800.0f / SCALE;   // Width of window_ in Box2D units
  float world_Height = 800.0f / SCALE;  // Height of  window_ in Box2D units
  float thickness = 0.0005f / SCALE;   // Thickness of the boundary walls

  // Define the positions and sizes of the boundary walls
  b2Vec2 topWallPos(world_Width / 2, thickness / 2);
  b2Vec2 bottomWallPos(world_Width / 2, world_Height - thickness / 2);
  b2Vec2 leftWallPos(thickness / 2, world_Height / 2);
  b2Vec2 rightWallPos(world_Width - thickness / 2, world_Height / 2);

  b2Vec2 horizontalSize(world_Width, thickness);
  b2Vec2 verticalSize(thickness, world_Height);

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
  b2Body* body = world_->GetPhysicWorld()->CreateBody(&bodyDef);

  b2PolygonShape shape;
  shape.SetAsBox(size.x / 2, size.y / 2);

  b2FixtureDef fixtureDef;
  fixtureDef.shape = &shape;
  body->CreateFixture(&fixtureDef);
}