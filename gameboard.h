#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "cell.h"
#include <string>
#include <iostream>

#define ROW 10
#define COL 10

class GameBoard {
public: 
    GameBoard();
    int add_ship(int x, int y, bool vertical, Ship &ship);
    void print_board();
    vector<vector<Cell>> &get_board();
private:    
    vector<vector<Cell>> board;     
};

#endif