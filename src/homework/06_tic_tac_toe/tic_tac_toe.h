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

        std::string get_winner();

    private:
        std::vector<std::string> pegs{ " ", " ", " ", " ", " ", " ", " ", " ", " " };
        std::string player;
        std::string winner;

        void set_next_player();
        bool check_board_full();
        void clear_board();

        void set_winner();
        bool check_diagonal_win();
        bool check_row_win();
        bool check_column_win();
};


#endif

std::string get_str(std::string prompt);

int get_int(std::string prompt);