#include "ship.h"

Ship::Ship(int cell_amount) {
    this->cell_amount = cell_amount;
    this->destroyed = false;
    this->add_cells();
}

int Ship::get_cell_amount() {
    return this->cell_amount;
}
void Ship::set_cell_amount(int cell_amount) {
    this->cell_amount = cell_amount;
}
bool Ship::get_destroyed() {
    return this->destroyed;
}
void Ship::set_destroyed(bool destoryed) {
    this->destroyed = destoryed;
}
vector<ShipCell> &Ship::get_cells() {
    return this->cells;
}

void Ship::add_cells() {
    for (int i = 0; i < this->cell_amount; i++) {
        cells.push_back(ShipCell());
    }
}
bool Ship::check_destoryed() {
    for (int i = 0; i < this->cell_amount; i++) {
        if (this->cells[i].get_beenShot() == false) {
            return false; 
        }
    }
    return true;
    
}