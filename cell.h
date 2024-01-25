#ifndef CELL_H
#define CELL_H

#include "ship.h"

class Cell {
public:
    Cell();
    bool get_beenShot();
    void set_beenShot(bool beenShot);
    Ship *get_ship();
    void set_ship(Ship *ship);
    ShipCell *get_shipcell();
    void set_shipcell(ShipCell *shipcell);
private:
    Ship *ship;
    ShipCell *shipcell;
    bool beenShot;
};

#endif