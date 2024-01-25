#include "ai.h"


Ai::Ai(int ship_amount, bool hard) {
    this->AiBoard = GameBoard();
    this->ship_amount = ship_amount;
    this->hard = hard;
}

Ai::~Ai() {
    this->delete_ships();
}
void Ai::delete_ships() {
    for(int i= 0; i< this->ship_amount; i++) {
        delete this->ships[i];
    }
}

bool Ai::lost() {
    for (int i = 0; i < this->ship_amount; i++) {
        if (this->ships[i]->get_destroyed() == false) {
            return false; 
        }
    }
    return true;
    
}
pair<int, int> Ai::hunt(GameBoard &board) {
    int x = this->huntq.front().first;
    int y = this->huntq.front().second;
    if (x != 9 && !board.get_board()[y][x+1].get_beenShot()) {
        return {x+1, y};
    }
    else if (x != 0 && !board.get_board()[y][x-1].get_beenShot()) {
        return {x-1, y};
    }
    else if (y != 9 && !board.get_board()[y+1][x].get_beenShot()) {
        return {x, y+1};
    }
    else if (y != 0 && !board.get_board()[y-1][x].get_beenShot()) {
        this->huntq.pop();
        return {x, y-1};
    }
    this->huntq.pop();
    if (!huntq.empty()) return hunt(board);
    return {-1, -1};
}
void Ai::print_board() {
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
            if (this->AiBoard.get_board()[y][x].get_shipcell() && this->AiBoard.get_board()[y][x].get_beenShot() && this->AiBoard.get_board()[y][x].get_ship()->get_destroyed()) {
                
                ret_str+= "| \033[0;34m X \033[0m ";

            }
            else if (this->AiBoard.get_board()[y][x].get_shipcell() && this->AiBoard.get_board()[y][x].get_beenShot()) {
                
                ret_str+= "| \033[0;31m X \033[0m ";

            }
            else if (this->AiBoard.get_board()[y][x].get_beenShot()) {
                
                ret_str+= "|  X  ";

            }
            else if (this->AiBoard.get_board()[y][x].get_shipcell()) {
                
                ret_str+= "|  S  ";

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
void Ai::shoot(GameBoard &board) {
    int x,y;
    if (huntq.empty()) {
        x = rand() % 10;
        y = rand() % 10;
        while(board.get_board()[y][x].get_beenShot()) {
            x = rand() % 10;
            y = rand() % 10;
        }
    }
    else {
        pair<int, int> ret = this->hunt(board);
        x = ret.first;
        y = ret.second;
        if (x == -1) {
            x = rand() % 10;
            y = rand() % 10;
            while(board.get_board()[y][x].get_beenShot()) {
                x = rand() % 10;
                y = rand() % 10;
            }
        }
    }
    cout << "Ai shoots at x: " << x+1 << " y: " << y+1 << endl;
    board.get_board()[y][x].set_beenShot(true);
    if (board.get_board()[y][x].get_shipcell()) {
        board.get_board()[y][x].get_shipcell()->set_beenShot(true);
        if (board.get_board()[y][x].get_ship()->check_destoryed()) {
            cout << "\033[0;31mShip destoyed! \033[0m" << endl;
            board.get_board()[y][x].get_ship()->set_destroyed(true);
            if (this->hard) {
                this->huntq.push({x, y});
            }
        }
        else {
            cout << "Ship hit!" << endl;
            if (this->hard) {
                this->huntq.push({x, y});
            } 
        }
    }
    else {
        cout << "Missed!" << endl;
    }
}

GameBoard &Ai::get_AiBoard() {
    return this->AiBoard;
}
vector<Ship *> &Ai::get_ships() {
    return this->ships;
}