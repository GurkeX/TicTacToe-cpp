#include <iostream>

#include "tictactoe_game.h"

using namespace std;

tictactoe_game::tictactoe_game(std::string player1, std::string player2) {
    this->player1 = player1;
    this->player2 = player2;
    
    cout << "Neues Spiel für " << player1 << " und " << player2 << " wird erstellt" << endl;
}

tictactoe_game::tictactoe_game() {
    player1 = "Spieler1";
    player2 = "Spieler2";

    cout << "Neues Spiel wird erstellt" << endl;
}

void tictactoe_game::player_name_input() {
    string player_name;
    for (int i = 1; i = 2; i++) {
        cout << "Bitte gebe den name von Spieler " << i << " ein" << endl
             << endl
             << "Eingabe: ";
        cin >> player_name;
    }
}