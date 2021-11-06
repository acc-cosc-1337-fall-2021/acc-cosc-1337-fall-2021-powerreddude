//cpp
#include <string>
#include <iostream>
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

void Tic_tac_toe_manager::update_winner_count(std::string winner)
{
    if(winner == "X")
    {
        x_win++;
    } else if(winner == "O") {
        o_win++;
    } else {
        ties++;
    }
}

void Tic_tac_toe_manager::save_game(Tic_tac_toe b)
{
    games.push_back(b);
    update_winner_count(b.get_winner());
}

std::ostream& operator<<(std::ostream & out, const Tic_tac_toe_manager & manager)
{
    for(auto i : manager.games)
    {
        std::cout<<i<<std::endl;
    }
    return out;
}

void Tic_tac_toe_manager::get_winner_total(int& o, int& x, int& t)
{
    o = o_win;
    x = x_win;
    t = ties;
}