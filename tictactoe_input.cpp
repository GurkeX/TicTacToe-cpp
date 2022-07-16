#include "tictactoe_input.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

tictactoe_input::tictactoe_input()
{
    cout << "Neuer input wird erstellt" << endl;
}

int tictactoe_input::player_field_input()
{
    int field_input;
    while (1)
    {
        cout << "Bitte wähle eines der felder mit den Zahlen 1-9 aus" << endl
             << endl
             << "Eingabe: ";
        cin >> field_input;

        if (field_input >= 1 && field_input <= 9)
        {
            return field_input --;
        }
        else 
        {
            field_input = 0;
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalide Eingabe, bitte versuche es nocheinmal";
        }
    }
}