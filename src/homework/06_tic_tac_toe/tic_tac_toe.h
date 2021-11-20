//h
#include <vector>
#include <string>
#include <iostream>

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H


class Tic_tac_toe
{
    public:
        Tic_tac_toe(int size):pegs(size*size, " ") {};
        Tic_tac_toe(std::vector<std::string> p, std::string win):pegs(p), winner(win) {};
        void display_board() const;
        std::string get_player() const;
        void mark_board(int position);
        void start_game(std::string first_player);
        bool game_over();

        std::string get_winner() const;// this is ok i think

        friend std::ostream& operator<<(std::ostream& out, const Tic_tac_toe& game);
        friend std::istream& operator>>(std::istream& in, Tic_tac_toe& game);
        
        std::vector<std::string> get_pegs() const;

    private:
        std::string player;
        std::string winner;

        void set_next_player();
        bool check_board_full();
        void clear_board();

        void set_winner();
    

    protected:
        std::vector<std::string> pegs;
        virtual bool check_diagonal_win();
        virtual bool check_row_win();
        virtual bool check_column_win();
};


#endif

std::string get_str(std::string prompt);

int get_int(std::string prompt);