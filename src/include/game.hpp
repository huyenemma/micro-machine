#ifndef GAME_H
#define GAME_H

//#include "../../libs/include/SFML/Graphics.hpp"
#include <SFML/Graphics.hpp>

#include "constant.hpp"
#include "vehicle.hpp"
#include "constant.hpp"
#include "world.hpp"
#include "map.hpp"
#include "negativebuff.hpp"
#include "ContactListener.hpp"

class Game {
private:
    sf::RenderWindow window;  // The SFML window for rendering
    World* world;             // The physics world
    bool isRunning;           // Flag to check if the game is running
    Map* map;
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
