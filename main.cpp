#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <thread>
#include "ai.h"
#include "player.h"
using namespace std;

#define COL 10
#define ROW 10

int main() {
    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    int diff;
    bool stop = false;
    while (!stop) {
        cout << "Select AI difficulty" << endl;
        cout << "1. Easy\n2. Hard" << endl;
        cin >> diff;
        while(diff != 1 && diff != 2 || !cin.good()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Select AI difficulty" << endl;
            cout << "1. Easy\n2. Hard" << endl;
            cin >> diff;
        }
        bool hard;
        if (diff == 1) {
            hard = false;
        }
        else {
            hard = true;
        }
        Ai ai = Ai(5, hard);
        Player player = Player(5);
        //player.playerBoard.print_board();
        
        //GameBoard a = GameBoard();
        int arr[5] = {5,4,3,3,2};
        //a.print_board();
        
        for (int i = 0; i < 5; i++) {
            Ship *ship = new Ship(arr[i]);
            Ship *ship2 = new Ship(arr[i]);
            bool v = rand() % 2;
            bool v2 = rand() % 2;
            player.get_ships().push_back(ship);
            ai.get_ships().push_back(ship2);
            if (v) {
                while(player.get_playerBoard().add_ship(rand() % 10, rand() % (10-ship->get_cell_amount()+1), v, *ship) == -1) {}
                
            }
            else {
                while(player.get_playerBoard().add_ship(rand() % (10-ship->get_cell_amount()+1), rand() % 10, v, *ship) == -1) {}
                
            }
            if (v2) {
                while(ai.get_AiBoard().add_ship(rand() % 10, rand() % (10-ship2->get_cell_amount()+1), v2, *ship2) == -1) {}
                
            }
            else {
                while(ai.get_AiBoard().add_ship(rand() % (10-ship2->get_cell_amount()+1), rand() % 10, v2, *ship2) == -1) {}
                
            }
        }
        
        cout << "Your Board:" << endl;
        player.print_board();
        
        int round = 0;
        bool play = true;
        while(play) {
            this_thread::sleep_for(std::chrono::milliseconds(3000));
            round++;
            cout << "Round " << round << endl;
            cout << "Your turn." << endl;
            ai.get_AiBoard().print_board();
            player.shoot(ai.get_AiBoard());
            ai.get_AiBoard().print_board();
            if (ai.lost()) {
                play = false;
            }
            else {
                this_thread::sleep_for(std::chrono::milliseconds(3000));
                cout << "Ai's turn." << endl;
                ai.shoot(player.get_playerBoard());
                player.print_board();
                if (player.lost()) {
                    play = false;
                }
            }
        }
        if (!player.lost()) {
            cout << "You won!" << endl;
        }
        else {
            cout << "Ai won!" << endl;
        }
        int play_again;
        cout << "Want to play again?" << endl;
        cout << "1. Play again\n2. Quit" << endl;
        cin >> play_again;
        while(play_again != 1 && play_again != 2 || !cin.good()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Want to play again?" << endl;
            cout << "1. Play again\n2. Quit" << endl;
            cin >> play_again;
        }
        if (play_again == 2) {
            stop = true;
        }
    }
    
}   