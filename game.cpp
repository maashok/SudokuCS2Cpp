#include "game.hpp"

Game::Game() {
    grid = new Grid();
}

Game::~Game() {
    grid->~Grid();
}

void Game::Run() {
    cout << "Enter the file name for the sudoku puzzle to load" << endl;
    string fileName;
    cin >> fileName;
    grid->loadBoard(fileName);
    grid->print();
    while (true) {
        cout << "Enter d to do a move (followed by row, column and digit) and u to undo (followed by row and column)" << endl;
        string moveType;
        cin >> moveType;
        if (moveType == "d") {
            string row, col, val;
            cin >> row >> col >> val;
            int irow = atoi(row.c_str());
            int icol = atoi(col.c_str());
            int ival = atoi(val.c_str());
            if (irow < 1 || irow > 9 || icol < 1 || icol > 9) {
                cout << "ERROR: Row and column numbers should be 1-9" << endl;
            }
            else if (ival < 1 || ival > 9) {
                cout << "ERROR: Cell values should be 1-9" << endl;
            }
            else {
                bool worked = grid->writeNum(irow - 1, icol - 1, *val.c_str());
                if (worked == false) {
                    cout << "ERROR: This move is not valid, try again" << endl;
                }
            }
        }
        else if (moveType == "u") {
            string row, col;
            cin >> row >> col;
            int irow = atoi(row.c_str());
            int icol = atoi(col.c_str());
            if (irow < 1 || irow > 9 || icol < 1 || icol > 9) {
                cout << "ERROR: Row and column numbers should be 1-9" << endl;
            }
            else {
                grid->undoNum(irow - 1, icol - 1);
            }
        }
        else {
            cout << "Enter a valid move type" << endl;
        }
        grid->print();
        if (grid->isComplete()) {
            cout << "Good job! You solved it!" << endl;
            return;
        }
    }

}