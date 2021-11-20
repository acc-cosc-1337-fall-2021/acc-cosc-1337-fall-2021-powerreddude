//cpp
#include <utility>
#include <memory>
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

void Tic_tac_toe_manager::save_game(std::unique_ptr<Tic_tac_toe>& b)
{
    update_winner_count(b -> get_winner());
    games.push_back(std::move(b));
}

std::ostream& operator<<(std::ostream& out, const Tic_tac_toe_manager& manager)
{
    for(auto& i : manager.games)
    {
        std::cout<<*i<<std::endl;
    }
    return out;
}

void Tic_tac_toe_manager::get_winner_total(int& o, int& x, int& t)
{
    o = o_win;
    x = x_win;
    t = ties;
}

Tic_tac_toe_manager::Tic_tac_toe_manager(Tic_tac_toe_data d): data(d)
{
    games = data.get_games();

    for(auto& game : games) {
        update_winner_count(game -> get_winner());
    }
}

Tic_tac_toe_manager::~Tic_tac_toe_manager()
{
    data.save_games(games);
}