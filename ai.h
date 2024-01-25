#ifndef AI_H
#define AI_H

#include "gameboard.h"
#include <queue>

#define ROW 10
#define COL 10

class Ai {
public:
    Ai(int ship_amount, bool hard);
    virtual ~Ai();
    bool lost();
    pair<int, int> hunt(GameBoard &board);
    void print_board();
    void shoot(GameBoard &board);
    GameBoard &get_AiBoard();
    vector<Ship *> &get_ships();
    void delete_ships();
private:
    int ship_amount;
    bool hard;
    queue<pair<int, int>> huntq;
    GameBoard AiBoard;
    vector<Ship *> ships;
};

#endif