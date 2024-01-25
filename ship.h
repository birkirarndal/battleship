#ifndef SHIP_H
#define SHIP_H

#include <vector>
#include "shipcell.h"

using namespace std;


class Ship {
public:
    Ship(int cell_amount);
    bool check_destoryed();
    int get_cell_amount();
    void set_cell_amount(int cell_amount);
    bool get_destroyed();
    void set_destroyed(bool destoryed);
    vector<ShipCell> &get_cells();
    void add_cells();
private:
    vector<ShipCell> cells;
    int cell_amount;
    bool destroyed;
};

#endif