#include "player.h"

Player::Player(int ship_amount) {
    this->playerBoard = GameBoard();
    this->ship_amount = ship_amount;
}

Player::~Player() {
    this->delete_ships();
}
void Player::delete_ships() {
    for(int i= 0; i< this->ship_amount; i++) {
        delete this->ships[i];
    }
}

void Player::print_board() {
    string ret_str;
    string temp_str;
    for (int i = 0; i < COL; i++) {
        temp_str +=  "+-----";
    }
    temp_str += "+\n";
    temp_str = "     " + temp_str;
    ret_str += temp_str;
    cout << "        1     2     3     4     5     6     7     8     9     10   " << endl;
    for (int y = 0; y < ROW; y++) {
        for (int x = 0; x < COL; x++) {
            if (x == 0 && y == 9) {
                ret_str += " " + to_string(y+1) + "  "; 
            }
            else if (x == 0) {
                ret_str += "  " + to_string(y+1) + "  "; 
            }
            if (this->playerBoard.get_board()[y][x].get_shipcell() && this->playerBoard.get_board()[y][x].get_beenShot() && this->playerBoard.get_board()[y][x].get_ship()->get_destroyed()) {
                
                ret_str+= "| \033[0;34m X \033[0m ";

            }
            else if (this->playerBoard.get_board()[y][x].get_shipcell() && this->playerBoard.get_board()[y][x].get_beenShot()) {
                
                ret_str+= "| \033[0;31m X \033[0m ";

            }
            else if (this->playerBoard.get_board()[y][x].get_beenShot()) {
                
                ret_str+= "|  X  ";

            }
            else if (this->playerBoard.get_board()[y][x].get_shipcell()) {
                
                ret_str+= "| \033[0;32m S \033[0m ";

            }
            else {
                ret_str+= "|     ";
            }
        }
        // ret_str += "|\n+-----+-----+-----+-----+-----+\n" ;
        ret_str += "|\n" + temp_str;
    }
    cout << ret_str << endl;
}
void Player::shoot(GameBoard &board) {
    cout << "Pick x y you want to shoot at." << endl;
    cout << "Enter x y: ";
    int x,y;
    cin >> x >> y;
    while ((1 > x || x > COL) || (1 > y || y > COL)) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "This coordinate is outside the board" << endl;
        cout << "Pick x y you want to shoot at." << endl;
        cout << "Enter x y: ";
        cin >> x >> y;
    }
    cout << "You shoot at x: " << x << " y: " << y << endl;
    x = x - 1;
    y = y - 1;
    if (board.get_board()[y][x].get_beenShot()) {
        cout << "Missed!" << endl;
        return;
    }
    board.get_board()[y][x].set_beenShot(true);
    if (board.get_board()[y][x].get_shipcell()) {
        board.get_board()[y][x].get_shipcell()->set_beenShot(true);
        bool a = board.get_board()[y][x].get_ship()->check_destoryed(); 
        if (a) {
            cout << "\033[0;31mShip destoyed! \033[0m" << endl;
            board.get_board()[y][x].get_ship()->set_destroyed(true);
        }
        else {
            cout << "Ship hit!" << endl;
        }
    }
    else {
        cout << "Missed!" << endl;
    }
}
bool Player::lost() {
    for (int i = 0; i < this->ship_amount; i++) {
        if (this->ships[i]->get_destroyed() == false) {
            return false; 
        }
    }
    return true;
    
}

int Player::get_ship_amount() {
    return this->ship_amount;
}
GameBoard &Player::get_playerBoard() {
    return this->playerBoard;
}
vector<Ship *> &Player::get_ships() {
    return this->ships;
}