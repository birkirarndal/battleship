#include "cell.h"


Cell::Cell() {
    this->beenShot = false;
    this->shipcell = NULL;
    this->ship = NULL;
}

bool Cell::get_beenShot() {
    return this->beenShot;
}
void Cell::set_beenShot(bool beenShot){
    this->beenShot = beenShot;
}
Ship *Cell::get_ship(){
    return this->ship;
}
void Cell::set_ship(Ship *ship){
    this->ship = ship;
}
ShipCell *Cell::get_shipcell(){
    return this->shipcell;
}
void Cell::set_shipcell(ShipCell *shipcell){
    this->shipcell = shipcell;
}