#ifndef PLAYER_H
#define PLAYER_H

#include "gameboard.h"
#include <chrono>

class Player {
public:
    Player(int ship_amount);
    virtual ~Player();
    void print_board();
    void shoot(GameBoard &board);
    bool lost();
    int get_ship_amount();
    GameBoard &get_playerBoard();
    vector<Ship *> &get_ships();
    void delete_ships();
private:
    int ship_amount;
    GameBoard playerBoard;
    vector<Ship *> ships;
};

#endif