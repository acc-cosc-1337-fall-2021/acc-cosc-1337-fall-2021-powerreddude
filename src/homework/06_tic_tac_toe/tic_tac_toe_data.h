//h
#include <vector>
#include <memory>
#include "tic_tac_toe.h"

#ifndef TIC_TAC_TOE_DATA_H
#define TIC_TAC_TOE_DATA_H
class Tic_tac_toe_data
{
    public:
        void save_games(const std::vector<std::unique_ptr<Tic_tac_toe>>& games);
        std::vector<std::unique_ptr<Tic_tac_toe>> get_games();

};
#endif