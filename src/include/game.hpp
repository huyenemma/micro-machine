#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "resourceManager.hpp"

#include "ContactListener.hpp"
#include "constant.hpp"
#include "map.hpp"

#include "ox.hpp"
#include "negativebuff.hpp"
#include "obstacle.hpp"
#include "vehicle.hpp"
#include "world.hpp"
#include "ContactListener.hpp"
#include "realTime.hpp"
#include "positivebuff.hpp"

class Game {
 private:
  sf::RenderWindow window_;  // The SFML window for rendering
  World* world_;             // The physics world
  bool isRunning_;           // Flag to check if the game is running
  ResourceManager* resourceManager_; 
  RealTime* counterClock_; 
  Map* map_; 

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
  void Render();
};

#endif  // GAME_H
