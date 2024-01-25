#include "gameboard.h"

GameBoard::GameBoard(){
    for (int y = 0; y < ROW; y++)
    {
        vector<Cell> a;
        for (int x = 0; x < COL; x++) {
            a.push_back(Cell());
        }
        this->board.push_back(a);
    }
    
}
int GameBoard::add_ship(int x, int y, bool vertical, Ship &ship) {
    //bool canCreate = true;
    if (vertical) {
        for (int i = 0; i < ship.get_cell_amount(); i++ ) {
            if (this->board[y+i][x].get_shipcell()) {
                return -1;
            }
        }
        
        for (int i = 0; i < ship.get_cell_amount(); i++ ) {
            this->board[y+i][x].set_shipcell(&ship.get_cells()[i]);
            this->board[y+i][x].set_ship(&ship);    
        }
        
    }

    if (!vertical) {
        for (int i = 0; i < ship.get_cell_amount(); i++ ) {
            if (this->board[y][x+i].get_shipcell()) {
                return -1;
            }
        }

        for (int i = 0; i < ship.get_cell_amount(); i++) {
            this->board[y][x+i].set_shipcell(&ship.get_cells()[i]);
            this->board[y][x+i].set_ship(&ship); 
        }    
    }
    return 1;
    
}
void GameBoard::print_board() {
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
            if (this->board[y][x].get_shipcell() && this->board[y][x].get_beenShot() && this->board[y][x].get_ship()->get_destroyed()) {
                
                ret_str+= "| \033[0;34m X \033[0m ";

            }
            else if (this->board[y][x].get_shipcell() && this->board[y][x].get_beenShot()) {
                
                ret_str+= "| \033[0;31m X \033[0m ";

            }
            else if (this->board[y][x].get_beenShot()) {
                
                ret_str+= "|  X  ";

            }
            else {
                ret_str+= "|     ";
            }
        }
        ret_str += "|\n" + temp_str;
    }
    cout << ret_str << endl;
}

vector<vector<Cell>> &GameBoard::get_board() {
    return this->board;
}