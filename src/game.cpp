#include "./include/game.hpp"

Game::Game()
    : window_(sf::VideoMode(800, 800), "Micro machine"),
      isRunning_(false),
      currentState_(GameState::MENU)
{
  resourceManager_ = new ResourceManager();
  resourceManager_->LoadFromJson("../src/resources.json");
  font = resourceManager_->GetFont("clockFont");

  const sf::Texture &menuTexture = resourceManager_->GetImage("menu");
  menu_ = new GameMenu(window_, font, menuTexture);
  menu2_ = new GameMenu2(window_, font, menuTexture);

  const sf::Texture &wintexture = resourceManager_->GetImage("gameWin");
  winnerBoard_ = new WinnerBoard(window_, font, wintexture);
};

Game::~Game()
{
  delete world_;
  delete resourceManager_;
  delete counterClock_;
  delete map_;
  delete menu_;
  delete menu2_;
  delete winnerBoard_;
}

using namespace NegativeBuff;
using namespace PositiveBuff;

void Game::Initialize()
{

  world_ = new World(b2Vec2(0.0f, 0.0f));
  const sf::Font &font = resourceManager_->GetFont("clockFont");
  counterClock_ =
      new RealTime(15, font, sf::Color::White, sf::Vector2f(330, 10));
  counterClock_->SetUp();
  if (playerCount == 2)
  {
    counterClock_->SetGameMode(2);
  };

  const sf::Texture &map_Texture = resourceManager_->GetImage(map);
  map_ = new Map(map_Texture);

  const sf::Texture &oxTexture = resourceManager_->GetImage("buffalo");

  // Setting vehicles
  if (map == "forest")
  {
    Ox *ox = new Ox(world_->GetPhysicWorld(), 200.0f / SCALE, 120.0f / SCALE,
                    oxTexture);

    world_->AddVehicle(ox);
    player1 = ox;

    if (playerCount == 2)
    {
      const sf::Texture &goatTexture = resourceManager_->GetImage("goat");
      Ox *ox2 = new Ox(world_->GetPhysicWorld(), 200.0f / SCALE, 120.0f / SCALE,
                       goatTexture);
      world_->AddVehicle(ox2);
      player2 = ox2;
    }
  }
  else
  {
    Ox *ox = new Ox(world_->GetPhysicWorld(), 220.0f / SCALE, 280.f / SCALE,
                    oxTexture);

    world_->AddVehicle(ox);
    player1 = ox;

    if (playerCount == 2)
    {
      const sf::Texture &goatTexture = resourceManager_->GetImage("goat");
      Ox *ox2 = new Ox(world_->GetPhysicWorld(), 220.0f / SCALE, 270.f / SCALE,
                       goatTexture);
      world_->AddVehicle(ox2);
      player2 = ox2;
    }
  }

  // Setting Contact Listener
  MyContactListener *contactListener = new MyContactListener();
  world_->GetPhysicWorld()->SetContactListener(contactListener);

  // Setting collectable and buff
  if (map == "forest")
  {
    CrazyRotate *badBuff1 = new CrazyRotate(2, 40.f, 30.f);

    const sf::Texture &badTexture1 = resourceManager_->GetImage("badApple");

    Collectable *collectable = new Collectable(
        world_->GetPhysicWorld(), b2Vec2(150.f / SCALE, 440.0f / SCALE),
        30.0f / SCALE, badBuff1, badTexture1);

    MaxSpeed *buff2 = new MaxSpeed(8, 1.5f);
    const sf::Texture &collectable2_Texture =
        resourceManager_->GetImage("goodApple");
    Collectable *collectable2 = new Collectable(
        world_->GetPhysicWorld(), b2Vec2(700.f / SCALE, 320.0f / SCALE),
        30.0f / SCALE, buff2, collectable2_Texture);

    Magnetic *buff3 = new Magnetic(6, 5.f);
    const sf::Texture &collectable3_Texture =
        resourceManager_->GetImage("goodBanana");
    Collectable *collectable3 = new Collectable(
        world_->GetPhysicWorld(), b2Vec2(200.0f / SCALE, 650.f / SCALE),
        50.0f / SCALE, buff3, collectable3_Texture);

    world_->AddCollectable(collectable);
    world_->AddCollectable(collectable2);
    world_->AddCollectable(collectable3);

    const sf::Texture &rock = resourceManager_->GetImage("rock");
    Obstacle *obstacle = new Obstacle(world_->GetPhysicWorld(),
                                      b2Vec2(140.0f / SCALE, 150.0f / SCALE),
                                      20.0f / SCALE, rock);
    world_->AddObstacle(obstacle);

    StartLine *startLine =
        new StartLine(world_->GetPhysicWorld(),
                      b2Vec2(200.0f / SCALE, 120.0f / SCALE), 5.0f, 5.0f);
    CheckPoint *checkPoint1 =
        new CheckPoint(world_->GetPhysicWorld(),
                       b2Vec2(636.0f / SCALE, 620.0f / SCALE), 5.0f, 5.0f);
    CheckPoint *checkPoint2 =
        new CheckPoint(world_->GetPhysicWorld(),
                       b2Vec2(136.0f / SCALE, 620.0f / SCALE), 5.0f, 5.0f);
    startLine->AddCheckPoint(checkPoint1);
    startLine->AddCheckPoint(checkPoint2);
    world_->SetRacingTrack(startLine);

    // // add background sound
    // backgroundBuffer = resourceManager_->GetSoundBackground("grass");

    // background.setBuffer(backgroundBuffer);
    // background.setLoop(true);
    // background.setVolume(50);
    // background.play();

    // // Set sound effect
    // stepBuffer = resourceManager_->GetSoundStep("grass");

    // step.setBuffer(stepBuffer);
    // step.setVolume(40);
  }

  else
  {
    CrazyRotate *badBuff1 = new CrazyRotate(2, 40.f, 30.f);

    const sf::Texture &badTexture1 = resourceManager_->GetImage("badApple");

    Collectable *collectable = new Collectable(
        world_->GetPhysicWorld(), b2Vec2(440.0f / SCALE, 700.f / SCALE),
        30.0f / SCALE, badBuff1, badTexture1);

    MaxSpeed *buff2 = new MaxSpeed(8, 1.5f);
    const sf::Texture &collectable2_Texture =
        resourceManager_->GetImage("goodApple");
    Collectable *collectable2 = new Collectable(
        world_->GetPhysicWorld(), b2Vec2(750.f / SCALE, 120.f / SCALE),
        30.0f / SCALE, buff2, collectable2_Texture);

    Magnetic *buff3 = new Magnetic(6, 5.f);
    const sf::Texture &collectable3_Texture =
        resourceManager_->GetImage("goodBanana");
    Collectable *collectable3 = new Collectable(
        world_->GetPhysicWorld(), b2Vec2(750.0f / SCALE, 240.0f / SCALE),
        50.0f / SCALE, buff3, collectable3_Texture);

    world_->AddCollectable(collectable);
    world_->AddCollectable(collectable2);
    world_->AddCollectable(collectable3);

    /*
    Obstacle* obstacle = new Obstacle(world_->GetPhysicWorld(),
                                    b2Vec2(140.0f / SCALE, 150.0f / SCALE),
                                    50.0f / SCALE, "../img/rock.png");
    world_->AddObstacle(obstacle);
    */

    StartLine *startLine =
        new StartLine(world_->GetPhysicWorld(),
                      b2Vec2(136.0f / SCALE, 120.0f / SCALE), 5.0f, 5.0f);
    CheckPoint *checkPoint1 =
        new CheckPoint(world_->GetPhysicWorld(),
                       b2Vec2(636.0f / SCALE, 620.0f / SCALE), 5.0f, 5.0f);
    CheckPoint *checkPoint2 =
        new CheckPoint(world_->GetPhysicWorld(),
                       b2Vec2(136.0f / SCALE, 620.0f / SCALE), 5.0f, 5.0f);
    startLine->AddCheckPoint(checkPoint1);
    startLine->AddCheckPoint(checkPoint2);
    world_->SetRacingTrack(startLine);

    // // add background sound
    // backgroundBuffer = resourceManager_->GetSoundBackground("ocean");

    // background.setBuffer(backgroundBuffer);
    // background.setLoop(true);
    // background.setVolume(50);
    // background.play();

    // // Set sound effect
    // stepBuffer = resourceManager_->GetSoundStep("ocean");

    // step.setBuffer(stepBuffer);
    // step.setVolume(40);
  }
  AddBoundaries();
}

bool Game::Run()
{
  isRunning_ = true;
  sf::Clock clock;

  const sf::Time targetFrameTime = sf::seconds(1.0f / 24.0f);

  while (window_.isOpen() && isRunning_)
  {
    sf::Time deltaTime = clock.restart();
    if (currentState_ == GameState::MENU)
    {
      HandleMenuInput();
      RenderBaseMenu(*menu_);
      //RenderMenu(); 
    }
    else if (currentState_ == GameState::MENU2)
    {
      HandleMenuInput2();
      RenderBaseMenu(*menu2_);
      //RenderMenu2();
    }
    else if (currentState_ == GameState::PLAYING &&
             !counterClock_->IsTimeUp())
    {
      Update(deltaTime);
      RenderGame();
    }
    else if (currentState_ == GameState::GAME_OVER)
    {
      HandleWinningBoard();
      RenderBaseMenu(*winnerBoard_);
      //RenderWinningBoard(); 
    }

    sf::Time elapsedTime = clock.getElapsedTime();

    if (elapsedTime < targetFrameTime)
    {
      sf::sleep(targetFrameTime - elapsedTime);
    }
  }
  return false;
}

void Game::HandleInput()
{
  const float angle = 4.0f;
  Vehicle *vehicle = world_->GetVehicle()[0];

  vehicle->ToggleForce(false);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
    // Move car
    step.play();
    vehicle->ToggleForce(true);
    std::cout << "Current position " << vehicle->GetPosition().first * SCALE
              << ", " << vehicle->GetPosition().second * SCALE << std::endl;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    // turn right
    vehicle->Rotate(angle);
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    vehicle->Rotate(-angle);
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
  {
    vehicle->SuperSkill();
  }

  vehicle->Update();

  if (playerCount == 2)
  {
    Vehicle *vehicle2 = world_->GetVehicle()[1];
    vehicle2->ToggleForce(false);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
      // Move car
      step.play();
      vehicle2->ToggleForce(true);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
      // turn right
      vehicle2->Rotate(angle);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
      vehicle2->Rotate(-angle);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
      vehicle2->SuperSkill();
    }
    vehicle2->Update();
  }
}

void Game::Update(sf::Time deltaTime)
{
  // Update car position
  HandleInput();
  world_->Update(deltaTime.asSeconds(), velocityIterations, positionIterations);
  counterClock_->Update(world_->GetPoint(player1), world_->GetPoint(player2));
  if (world_->HaveAnyOneWin())
  {
    winnerBoard_->SetWinner(1);
    currentState_ = GameState::GAME_OVER;
  }
}

void Game::RenderGame()
{
  window_.clear();

  if (currentState_ == GameState::GAME_OVER)
  {
    HandleWinningBoard();
    RenderBaseMenu(*winnerBoard_);
    //RenderWinningBoard(); 
  }
  else
  {
    sf::Vector2f mapSize(800.0f, 800.0f);

    // Define the view for player
    if (playerCount == 1)
    {
      sf::View view;

      // view.setCenter(sf::Vector2f(player1->GetPosition().first * SCALE,
      // player1->GetPosition().second * SCALE));
      view.zoom(zoomCoef);

      sf::Vector2f clampedCenter =
          ClampViewCenter(sf::Vector2f(player1->GetPosition().first * SCALE,
                                       player1->GetPosition().second * SCALE),
                          view.getSize(), mapSize);
      view.setCenter(clampedCenter);
      window_.setView(view);
      DrawGameWorld();
    }
    else if (playerCount == 2)
    {
      sf::View view1;
      view1.zoom(zoomCoef);
      view1.setViewport(sf::FloatRect(0.f, 0.f, 0.5f, 1.f));
      sf::Vector2f clampedCenter1 =
          ClampViewCenter(sf::Vector2f(player1->GetPosition().first * SCALE,
                                       player1->GetPosition().second * SCALE),
                          view1.getSize(), mapSize);
      view1.setCenter(clampedCenter1);
      window_.setView(view1);
      DrawGameWorld();

      sf::View view2;
      view2.zoom(zoomCoef);
      view2.setViewport(sf::FloatRect(0.5f, 0.f, 0.5f, 1.f));
      sf::Vector2f clampedCenter2 =
          ClampViewCenter(sf::Vector2f(player2->GetPosition().first * SCALE,
                                       player2->GetPosition().second * SCALE),
                          view2.getSize(), mapSize);
      view2.setCenter(clampedCenter2);
      window_.setView(view2);
      DrawGameWorld();
    }

    // view for fix ui element
    sf::View uiView = window_.getDefaultView();
    window_.setView(uiView);
    counterClock_->Draw(window_);
  }

  window_.display();
}

// helper function
sf::Vector2f Game::ClampViewCenter(const sf::Vector2f &center,
                                   const sf::Vector2f &viewSize,
                                   const sf::Vector2f &mapSize)
{
  sf::Vector2f clampedCenter = center;

  // Clamp X coordinates
  float minX = viewSize.x / 2;
  float maxX = mapSize.x - minX;
  clampedCenter.x = std::max(clampedCenter.x, minX);
  clampedCenter.x = std::min(clampedCenter.x, maxX);

  // Clamp Y coordinates
  float minY = viewSize.y / 2;
  float maxY = mapSize.y - minY;
  clampedCenter.y = std::max(clampedCenter.y, minY);
  clampedCenter.y = std::min(clampedCenter.y, maxY);

  return clampedCenter;
}

void Game::DrawGameWorld()
{
  map_->Draw(window_);

  if (!world_->GetVehicle().empty())
  {
    for (auto vehicle : world_->GetVehicle())
    {
      window_.draw(*vehicle);
    }
  }

  if (!world_->GetCollectable().empty())
  {
    for (auto collectable : world_->GetCollectable())
    {
      if (!collectable->IsNullBody())
      {
        window_.draw(*collectable);
        collectable->DeleteBody();
      }
    }
  }

  if (!world_->GetObstacle().empty())
  {
    for (auto obstacle : world_->GetObstacle())
    {
      window_.draw(*obstacle);
    }
  }
  // counterClock_->Draw(window_);
}

void Game::HandleMenuInput()
{
  sf::Event event;
  while (window_.pollEvent(event))
  {
    switch (event.type)
    {

    case sf::Event::KeyPressed:
      switch (event.key.code)
      {
      case sf::Keyboard::Up:
        menu_->MoveUp();
        break;
      case sf::Keyboard::Down:
        menu_->MoveDown();
        break;
      case sf::Keyboard::Enter:
        int selectedItem = menu_->GetPressedItem();
        if (selectedItem == GameMenu::ONE_PLAYER)
        {
          playerCount = 1;
          currentState_ = GameState::MENU2;
        }
        else if (selectedItem == GameMenu::TWO_PLAYER)
        {
          playerCount = 2;
          currentState_ = GameState::MENU2;
        }
        else if (selectedItem == GameMenu::EXIT)
        {
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

void Game::HandleMenuInput2()
{
  sf::Event event;
  while (window_.pollEvent(event))
  {
    switch (event.type)
    {
    case sf::Event::KeyPressed:
      switch (event.key.code)
      {
      case sf::Keyboard::Up:
        menu2_->MoveUp();
        break;
      case sf::Keyboard::Down:
        menu2_->MoveDown();
        break;
      case sf::Keyboard::Enter:
        int selectedItem = menu2_->GetPressedItem();
        if (selectedItem == GameMenu2::FOREST)
        {
          map = "forest";
          currentState_ = GameState::PLAYING;
          Initialize();
        }
        else if (selectedItem == GameMenu::TWO_PLAYER)
        {
          map = "ocean";
          currentState_ = GameState::PLAYING;
          Initialize();
        }
        else if (selectedItem == GameMenu::EXIT)
        {
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

void Game::HandleWinningBoard()
{
  sf::Event event;
  while (window_.pollEvent(event))
  {
    switch (event.type)
    {
    case sf::Event::KeyPressed:
      switch (event.key.code)
      {
      case sf::Keyboard::Up:
        winnerBoard_->MoveUp();
        break;
      case sf::Keyboard::Down:
        winnerBoard_->MoveDown();
        break;
      case sf::Keyboard::Enter:
        int selectedItem = winnerBoard_->GetPressedItem();
        if (selectedItem == WinnerBoard::REPLAY)
        {
          // Reset the game to start a new round
          delete world_;
          delete counterClock_;
          delete map_;
          currentState_ = GameState::MENU;
        }
        else if (selectedItem == WinnerBoard::EXIT)
        {
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

void Game::RenderBaseMenu(BaseMenu& menu)
{
  window_.clear();
  menu.draw();
  window_.display();
}

void Game::AddBoundaries()
{
  float world_Width = 800.0f / SCALE;  // Width of window_ in Box2D units
  float world_Height = 800.0f / SCALE; // Height of  window_ in Box2D units
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

void Game::CreateWall(const b2Vec2 &position, const b2Vec2 &size)
{
  b2BodyDef bodyDef;
  bodyDef.position = position;
  bodyDef.type = b2_staticBody;
  b2Body *body = world_->GetPhysicWorld()->CreateBody(&bodyDef);

  b2PolygonShape shape;
  shape.SetAsBox(size.x / 2, size.y / 2);

  b2FixtureDef fixtureDef;
  fixtureDef.shape = &shape;
  body->CreateFixture(&fixtureDef);
}
