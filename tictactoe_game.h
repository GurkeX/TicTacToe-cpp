#pragma once

#include <string>

#include "tictactoe_field.h"
#include "tictactoe_input.h"

class tictactoe_game : public tictactoe_field
{
private:
    std::string player1;
    std::string player2;
    
public:
    tictactoe_game(std::string player1, std::string player2);
    tictactoe_game();
    
    void player_name_input();
};