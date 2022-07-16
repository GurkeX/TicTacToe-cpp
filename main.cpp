#include <iostream>
#include <string>
#include <vector>

#include "tictactoe_field.h"
#include "tictactoe_game.h"
#include "tictactoe_input.h"

using namespace std;

void tictactoe_menu()
{
    int input;

    while (1)
    {
        input = 0;

        cout << "(1) Tictactoe spielen" << endl
             << "(2) Programm beenden" << endl
             << endl
             << "Eingabe: ";

        cin >> input;

        cout << endl;

        if (input == 1)
        {
            return;
        }
        else if (input == 2)
        {
            exit(0);
        }
        else if(cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
        }
        cout << "Invalide eingabe, versuche es nocheinmal" << endl;
    }
}

int main(int argc, const char *argv[])
{
    bool player_won = false;
    bool player_turn = true;

    while (1)
    {
        tictactoe_menu();

        tictactoe_input input;

        tictactoe_game game;
        game.resetTicTacToeField();

        while (player_won != true) {
            int player_input;
            
            if(game.calculateWinner() != 0) {
                cout << "Spieler " << game.calculateWinner() << " hat gewonnen!" << endl;
                break;
            }

            cout << endl << game.getFieldStr() << endl;
            cout << game.getField_1_9_Str() << endl;

            player_input = input.player_field_input();

            player_turn = !player_turn;
            game.change_field_with_player_input(player_input, player_turn);
        }
        cout << "Endergebniss:" << endl
             << game.getFieldStr() << endl
             << endl;
    }

  return 0;
}