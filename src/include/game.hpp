#ifndef GAME_H
#define GAME_H

//#include "../../libs/include/SFML/Graphics.hpp"
#include <SFML/Graphics.hpp>

#include "constant.h"
#include "vehicle.hpp"
#include "constant.h"

class Game {
private:
    sf::RenderWindow window;  // The SFML window for rendering
    World* world;             // The physics world
    bool isRunning;           // Flag to check if the game is running

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

  // Render the game
  void Render();
};

#endif  // GAME_H
