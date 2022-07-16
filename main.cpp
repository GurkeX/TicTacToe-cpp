#include <iostream>
#include <string>
#include <vector>

#include "tictactoe_field.h"
#include "tictactoe_game.h"
#include "tictactoe_input.h"

using namespace std;

int main(int argc, const char *argv[])
{
    bool player_won = false;
    bool player_turn = true;

    while (1)
    {
        tictactoe_input input;
        tictactoe_game game;
        
        input.tictactoe_menu();

        game.resetTicTacToeField();

        while (player_won != true) {
            int player_input;

            cout << endl << game.getFieldStr() << endl;
            cout << game.getField_1_9_Str() << endl;

            player_input = input.player_field_input();

            player_turn = !player_turn;
            game.change_field_with_player_input(player_input, player_turn);

            if(game.calculateWinner() != '0') {
                if(game.calculateWinner() != '-') {
                    cout << "Spieler " << game.calculateWinner() << " hat gewonnen!" << endl;
                }
                else if(game.calculateWinner() == '-') {
                    cout << "Unentschieden!" << endl;
                }
                player_won = true;
            }
        }
        
        cout << "Endergebniss:" << endl
             << game.getFieldStr() << endl
             << endl;
    }

  return 0;
}