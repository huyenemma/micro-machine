#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "resourceManager.hpp"
#include <SFML/Audio.hpp>

#include "ContactListener.hpp"
#include "constant.hpp"
#include "map.hpp"
#include "negativebuff.hpp"
#include "obstacle.hpp"
#include "ox.hpp"
#include "positivebuff.hpp"
#include "realTime.hpp"
#include "vehicle.hpp"
#include "world.hpp"
#include "menu.hpp"
#include "checkpoint.hpp"

enum class GameState {
    MENU,
    PLAYING,
    PAUSED,
    GAME_OVER
};

class Game {
 private:

  sf::RenderWindow window_;  // The SFML window for rendering
  World* world_;             // The physics world
  bool isRunning_;           // Flag to check if the game is running
  ResourceManager* resourceManager_; 
  RealTime* counterClock_; 
  Map* map_; 
  int playerCount = 1;
  Vehicle* player1;
  Vehicle* player2;
  sf::SoundBuffer backgroundBuffer;
  sf::Sound background;

  sf::SoundBuffer stepBuffer;
  sf::Sound step;

  GameState currentState_; 
  GameMenu menu_; 

 public:
  // Constructor
  Game();

  // Destructor
  ~Game();

  // Initialize the game (create window, create world, etc.)
  void Initialize();

  // The main game loop
  void Run();

  /// Handle input
  void HandleInput();

  // Handle SFML events
  void ProcessEvents();

  // Update game state
  void Update(sf::Time deltaTime);

  //  Add boundary for game window:
  void AddBoundaries();

  // add unpassable wall
  void CreateWall(const b2Vec2& position, const b2Vec2& size);

  // Render the game
  void RenderGame();

  // Draw game world
  void DrawGameWorld();

  // Handle menu input 
  void HandleMenuInput(); 

  //Render the menu
  void RenderMenu(); 
};

#endif  // GAME_H
