/**
 * @file game.h
 * @brief Game class header.
 *
 * The Game class encapsulates all the functionalities of the game including 
 * initialization, game loop, rendering, and handling different game states. 
 * It manages game elements such as the window, world, menus, and game states.
 */

#ifndef GAME_H
#define GAME_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ContactListener.hpp"
#include "baseMenu.hpp"
#include "checkpoint.hpp"
#include "constant.hpp"
#include "map.hpp"
#include "menu.hpp"
#include "menu2.hpp"
#include "negativebuff.hpp"
#include "obstacle.hpp"
#include "ox.hpp"
#include "positivebuff.hpp"
#include "realTime.hpp"
#include "resourceManager.hpp"
#include "vehicle.hpp"
#include "winnerBoard.hpp"
#include "world.hpp"

/**
 * @brief Represents different states of the game.
 */
enum class GameState { MENU, MENU2, PLAYING, PAUSED, GAME_OVER };

/**
 * @class Game
 * @brief Manages the main aspects of the game including rendering, updating, and game state management.
 *
 * The Game class handles the main game loop, event processing, and switching 
 * between different states of the game. It is responsible for initializing and 
 * managing game resources, rendering game elements, and updating game logic.
 */
class Game {
 private:
  sf::RenderWindow window_;  ///< SFML window for rendering the game.
  World* world_;             ///< The physics world of the game.
  bool isRunning_;           ///< Flag indicating if the game is currently running.
  ResourceManager* resourceManager_; ///< Manages resources like textures and fonts.
  RealTime* counterClock_;   ///< In-game clock for real-time events.
  std::string map;           ///< Current map being used in the game.
  Map* map_;                 ///< Map object for the game.
  int playerCount = 1;       ///< Number of players in the game.
  Vehicle* player1;          ///< First player's vehicle.
  Vehicle* player2;          ///< Second player's vehicle (if in two-player mode).
  sf::SoundBuffer backgroundBuffer; ///< Sound buffer for background music.
  sf::Sound background;      ///< Background music sound object.
  sf::Font font;             ///< Font used in the game.
  sf::SoundBuffer stepBuffer;///< Sound buffer for vehicle steps.
  sf::Sound step;            ///< Sound object for vehicle steps.

  GameState currentState_;   ///< Current state of the game.
  GameMenu* menu_;           ///< Main game menu.
  GameMenu2* menu2_;         ///< Secondary game menu.
  WinnerBoard* winnerBoard_; ///< Winner board displayed at the end of the game.

 public:
  /// Constructor
  Game();

  /// Destructor
  ~Game();

  /// Initializes the game (create window, world, etc.)
  void Initialize();

  /// Main game loop
  bool Run();

  /// Handles user input
  void HandleInput();

  /// Updates game state
  void Update(sf::Time deltaTime);

  /// Adds boundaries to the game window
  void AddBoundaries();

  /// Creates an impassable wall
  void CreateWall(const b2Vec2& position, const b2Vec2& size);

  /// Renders the game
  void RenderGame();

  /// Helper function to clamp camera view
  sf::Vector2f ClampViewCenter(const sf::Vector2f& center, const sf::Vector2f& viewSize, const sf::Vector2f& mapSize);

  /// Draws the game world
  void DrawGameWorld();

  /// Handles menu input
  void HandleMenuInput();
  void HandleMenuInput2();
  void HandleWinningBoard();

  /// Renders the menu
  void RenderBaseMenu(BaseMenu& menu);
};

#endif  // GAME_H
