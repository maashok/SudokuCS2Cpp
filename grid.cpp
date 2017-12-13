#include "grid.hpp"

/**
 * @brief Constructs a new grid of size 9 x 9. The
 * initial values are read from a file.
 *
 * @param
 *
 * @return
 */
Grid::Grid(string fileName) {
    ifstream inf(fileName);

    if (!inf)
    {
        cerr << "Can't read files of initial values" << endl;
        exit(1);
    }
    int lineCt = 0;
    while (inf)
    {
        std::string strInput;
        getline(inf, strInput);
        for (int i = 0; i < strInput.length(); i++) {
            cells[lineCt][i] = strInput[i];
        }
    }
}

bool Grid::checkRows() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                if (j != k && cells[i][j] == cells[i][k]) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool Grid::checkCols() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                if (j != k && cells[j][i] == cells[k][i]) {
                    return false;
                }
            }
        }
    }
    return true;
}

void Grid::print() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << cells[i][j] << " ";
        }
        cout << endl;
    }
}