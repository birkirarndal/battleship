#include "shipcell.h"

ShipCell::ShipCell() {
    this->beenShot = false;
}

bool ShipCell::get_beenShot() {
    return this->beenShot;
}
void ShipCell::set_beenShot(bool beenShot) {
    this->beenShot = beenShot;
}