#include "game.hpp"

int main() {
    Grid *grid = new Grid();
    grid->loadBoard("testFile.in");
    grid->print();
    
    grid->solve();
    grid->print();
/*
    Game *game = new Game();
    game->Run();*/
    return 0;
}