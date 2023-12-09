#include "./include/game.hpp"

int main() {
  
  // Create a Game object
  Game* game = new Game();


    // Run the game loop
    if (!game->Run())
        game->~Game();

    return 0;
}
