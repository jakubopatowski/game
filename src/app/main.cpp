#include <iostream>
#include "game.hpp"

int main( int argc, char const* argv[] ) {
    std::cout << "Welcome to basic 2D pixel art game project!\n";

    Game game;
    game.gameLoop();

    return 0;
}


