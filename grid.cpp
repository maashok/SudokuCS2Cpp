#include "grid.hpp"

/**
 * @brief Csonstructs a new grid of size 9 x 9. The
 * initial values are read from a file.
 *
 * @param
 *
 * @return
 */
Grid::Grid() {

}

Grid::~Grid() {
    
}

void Grid::loadBoard(string fileName) {
    ifstream fileIn;
    fileIn.open(fileName);
    int lineCt = 0;
    while(!fileIn.eof()) // To get you all the lines.
    {
        string x;
        getline(fileIn, x); // Saves the line in STRING.
        for (int i = 0; i < SIZE; i++) {
            cells[lineCt][i] = x.at(i);
        }
        lineCt += 1;
    }
    fileIn.close();
}

bool Grid::isComplete() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (cells[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Should receive x and y values with 1 already subtracted
bool Grid::writeNum(int x, int y, char val) {
    if (checkValid(x, y, val)) {
        cells[x][y] = val;        
        return true;
    }
    else {
        return false;
    }
}

// Should receive already decremented
void Grid::undoNum(int x, int y) {
    cells[x][y] = ' ';
}

bool Grid::checkValid(int x, int y, char val) {
    for (int i = 0; i < SIZE; i++) {
        if (cells[x][i] == val) {
            cout << "1" << x << i << endl;
            return false;
        }
        if (cells[i][y] == val) {
            cout << "2" << x << i << endl;
            return false;
        }
    }
    int boxRowMin = x - x % 3;
    int boxColMin = y - y % 3;
    for (int i = boxRowMin; i < boxRowMin + 3; i ++) {
        for (int j = boxColMin; j < boxColMin + 3; j++) {
            if (cells[i][j] == val) {
                cout << "3" << i << j << endl;
                return false;
            }
        }
    }
    return true;
}

void Grid::print() {
    cout << "-------------------------" << endl;    
    for (int i = 0; i < SIZE; i++) {
        cout << "| ";
        for (int j = 0; j < SIZE; j++) {
            cout << cells[i][j] << " ";
            if ((j + 1) % 3 == 0) {
                cout << "| ";
            }
        }
        cout << endl;
        
        if ((i + 1) % 3 == 0) {
            cout << "-------------------------" << endl;
        }
    }
}