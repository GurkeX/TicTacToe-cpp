#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

#include "tictactoe_field.h"

using namespace std;

tictactoe_field::tictactoe_field() {
    field_1_9 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    field = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    cout << "Neues Feld wird erstellt" << endl;
}

tictactoe_field::tictactoe_field(vector<vector<int>> field_1_9) {
    this->field_1_9 = field_1_9;
    cout << "Ich bin der Constructor, dem die Variable field_1_9 uebergeben wird" << endl;
}

void tictactoe_field::resetTicTacToeField() {
    field_1_9 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    field = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    cout << "Feld wurde zurückgesetzt" << endl;
}

char tictactoe_field::calculateWinner() {
    
    for (int i = 0; i <= 2; i++) {
        if (field.at(i).at(0) != ' ' &&
            field.at(i).at(0) == field.at(i).at(1) &&
            field.at(i).at(0) == field.at(i).at(2)) {
            
            return field.at(i).at(0);
        }
    }
    
    for (int i = 0; i <= 2; i++) {
        if (field.at(0).at(i) != ' ' &&
            field.at(0).at(i) == field.at(1).at(i) &&
            field.at(0).at(i) == field.at(2).at(i)) {
            
            return field.at(0).at(i);
        }
    }
    
    if (field.at(0).at(0) != ' ' &&
        field.at(0).at(0) == field.at(1).at(1) &&
        field.at(0).at(0) == field.at(2).at(2)) {
        
        return field.at(0).at(0);
    }
    
    if (field.at(0).at(2) != ' ' &&
        field.at(0).at(2) == field.at(1).at(1) &&
        field.at(0).at(2) == field.at(2).at(0)) {
        
        return field.at(0).at(2);
    }
    
    return 0;
}
    
string tictactoe_field::getField_1_9_Str() {
    stringstream result;
    
    for (const auto &row : field_1_9) {
        result << " | ";
        for (const auto &item : row) {
            result << item << " | ";
        }
        result << endl;
    }
    
    return result.str();
}

string tictactoe_field::getFieldStr() {
    stringstream result;
    
    for (const auto &row : field) {
        result << " | ";
        for (const auto &item : row) {
            result << item << " | ";
        }
        result << endl;
    }
    
    return result.str();
}

void tictactoe_field::change_field_with_player_input(int player_input, bool player_turn) {
    int row_counter = 0;
    int item_counter = 0;

    int player_1_or_2 = player_turn;
    player_1_or_2 ++;

    for (auto &row : field_1_9) {
        for (auto &item : row) {
            if (item == player_input) {
                if (player_turn == false) {
                    field.at(row_counter).at(item_counter) = 'X';
                }
                else if (player_turn == true) {
                    field.at(row_counter).at(item_counter) = 'O';
                }
            }
            item_counter ++;
            if (item_counter >= 3) {
            item_counter = 0;
        }
        }
        row_counter ++;
    }
}