//cpp
#include <memory>
#include <vector>
#include <fstream>
#include <iostream>
#include "tic_tac_toe_data.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

void Tic_tac_toe_data::save_games(const std::vector<std::unique_ptr<Tic_tac_toe>>& games)
{
    std::ofstream file("games.txt");
    if(file.is_open()) {
        for(const auto& game : games) {
            for(const auto& string : game -> get_pegs()) {
                for(auto c : string) {
                    file<<c;
                }
            }
            file<<game -> get_winner()<<std::endl;
        }
    }
    file.close();
}

std::vector<std::unique_ptr<Tic_tac_toe>> Tic_tac_toe_data::get_games()
{
    std::vector<std::unique_ptr<Tic_tac_toe>> games;
    std::ifstream file("games.txt");
    std::string line;
    while(getline(file, line)) {
        std::vector<std::string> pegs;
        for(auto c : line.substr(0, line.length() - 1)) {
            pegs.push_back(std::string(1,c));
        }
        std::string winner = std::string(1,line.back());
        std::unique_ptr<Tic_tac_toe> game;
        if(pegs.size() == 9) {
            game = std::make_unique<Tic_tac_toe_3>(pegs, winner);
        } else if(pegs.size() == 16) {
            game = std::make_unique<Tic_tac_toe_4>(pegs, winner);
        }
        games.push_back(std::move(game));
    }
    file.close();
    return games;
}