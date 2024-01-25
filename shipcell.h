#ifndef SHIPCELL_H
#define SHIPCELL_H

class ShipCell {
public:
    ShipCell();
    bool get_beenShot();
    void set_beenShot(bool beenShot);
private:
    bool beenShot;

};

#endif