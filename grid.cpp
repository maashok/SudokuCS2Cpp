#include "grid.hpp"

#include <iostream>
#include <fstream>
using namespace std;

/**
 * @brief Constructs a new grid of size 9 x 9. The
 * initial values are read from a file.
 *
 * @param
 *
 * @return
 */
Grid::Grid(char *fileName) {
    ifstream inf(fileName);

    if (!inf)
    {
        cerr << "Can't read files of initial values" << endl;
        exit(1);
    }
    lineCt = 0;
    while (inf)
    {
        std::string strInput;
        getline(inf, strInput);
        for (int i = 0; i < strInput.length(); i++) {
            cells[lineCt][i] = strInput[i];
        }
    }
}