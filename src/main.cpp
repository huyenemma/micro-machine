#include "./include/game.hpp"


int main() {

    // Create a Game object
    Game* game = new Game();

    // Initialize game resources, settings, etc.
    //game.Initialize();

    // Run the game loop
    if (!game->Run())
        game->~Game();

    return 0;
}
