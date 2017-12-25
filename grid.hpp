#define SIZE 9
#define BOX_SIZE 3
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/** 
 * @brief Represents a sudoku puzzle grid. Allows for certain actions such as
 * writing a number in a certain cell and checking if complete
 */

class Grid
{
    private:
        char cells[SIZE][SIZE];
        char original[SIZE][SIZE];
        bool checkValid(int x, int y, char val);
        bool backtrack(char origCells[SIZE][SIZE], int x, int y);
    public:
        Grid();
        ~Grid();
        void loadBoard(string fileName);
        bool isComplete();
        bool writeNum(int x, int y, char val);
        void undoNum(int x, int y);
        void print();
        void solve();
};