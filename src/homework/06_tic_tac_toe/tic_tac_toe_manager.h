//h
#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include "tic_tac_toe.h"

#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H
class Tic_tac_toe_manager
{
    public:
        void save_game(std::unique_ptr<Tic_tac_toe>& b);
        friend std::ostream& operator<<(std::ostream & out, const Tic_tac_toe_manager & manager);
        void get_winner_total(int& o, int& x, int& t);

    private:
        std::vector<std::unique_ptr<Tic_tac_toe>> games;
        int x_win = 0;
        int o_win = 0;
        int ties = 0;

        void update_winner_count(std::string winner);
};


#endif
