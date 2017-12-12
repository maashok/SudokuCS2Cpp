#include "grid.hpp"

int main() {
    string fileName;
    cin >> fileName;
    Grid *g = new Grid(fileName);
    g->print();
}