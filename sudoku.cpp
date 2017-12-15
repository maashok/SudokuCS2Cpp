#include "game.hpp"

int main() {
    Grid *grid = new Grid();
    string fileName;
    cout << "File name of board you want to solve" << endl;
    cin >> fileName;
    grid->loadBoard(fileName);
    grid->print();
    
    grid->solve();
    grid->print();
/*
    Game *game = new Game();
    game->Run();*/
    return 0;
}