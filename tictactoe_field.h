#pragma once

#include <vector>
#include <string>
#include <sstream>


class tictactoe_field {
protected:
    std::vector<std::vector<char>> field;
    std::vector<std::vector<int>> field_1_9;
public:
    tictactoe_field();
    tictactoe_field(std::vector<std::vector<int>> field_1_9);
    
    void resetTicTacToeField();
    char calculateWinner();
    void change_field_with_player_input(int player_input, bool player_turn);

    std::string getField_1_9_Str();
    std::string getFieldStr();
};