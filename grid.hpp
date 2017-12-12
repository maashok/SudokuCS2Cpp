#define SIZE 9
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
        int **cells;
        bool checkRows();
        bool checkCols();
        bool checkBoxes();
    public:
        Grid(std::string fileName);
        ~Grid();
        int Query(int x, int y);
        bool isComplete();
        bool writeNum(int x, int y, int val);
        void print();
};