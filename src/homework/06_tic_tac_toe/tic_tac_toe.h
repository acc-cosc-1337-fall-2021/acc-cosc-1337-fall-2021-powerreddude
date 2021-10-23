//h
#include <vector>
#include <string>

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H


class Tic_tac_toe
{
    public:
        void display_board() const;
        std::string get_player() const;
        void mark_board(int position);
        void start_game(std::string first_player);
        bool game_over();

    private:
        std::vector<std::string> pegs{ " ", " ", " ", " ", " ", " ", " ", " ", " " };
        std::string player;

        void set_next_player();
        bool check_board_full();
        void clear_board();
};


#endif

std::string get_str(std::string prompt);

int get_int(std::string prompt);