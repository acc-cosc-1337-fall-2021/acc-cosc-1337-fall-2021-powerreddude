#include <string>
#include <iostream>
#include "tic_tac_toe.h"

//cpp

void Tic_tac_toe::display_board() const
{
    std::cout<<pegs[0]<<pegs[1]<<pegs[2]<<std::endl<<pegs[3]<<pegs[4]<<pegs[5]<<std::endl<<pegs[6]<<pegs[7]<<pegs[8]<<std::endl;
}

std::string Tic_tac_toe::get_player() const
{
    return player;
}

void Tic_tac_toe::mark_board(int position)
{
    if(position >= 1 && position <= pegs.size())
    {
        pegs[position - 1] = player;
        set_next_player();
    }
}

void Tic_tac_toe::start_game(std::string first_player)
{
    if(first_player == "X" || first_player == "O")
    {
        player = first_player;
        clear_board();
    }
}

bool Tic_tac_toe::game_over()
{
    if(check_row_win() || check_column_win() || check_diagonal_win())
    {
        set_winner();
        return true;
    } else if(check_board_full()) {
        winner = "C";
    } else {
        return false;
    }
}

void Tic_tac_toe::set_next_player()
{
    if(player == "X")
    {
        player = "O";
    } else {
        player = "X";
    }
}

bool Tic_tac_toe::check_board_full()
{
    for(std::string i : pegs)
    {
        if(i == " ")
        {
            return false;
        }
    }
    return true;
}

void Tic_tac_toe::clear_board()
{
    for(std::string& i : pegs)
    {
        i = " ";
    }
}

std::string get_str(std::string prompt)
{
    std::string output;
    
    std::cout<<prompt;

    std::cin>>output;

    if( !(output == "X" || output == "O") )
    {
        return get_str("Please enter either X or O: ");
    } else {
        return output;
    }
}

int get_int(std::string prompt)
{
    int output;
    
    std::cout<<prompt;

    std::cin>>output;

    if( !(output >= 0 && output <= 9) )
    {
        return get_int("Please enter a number between 0 and 9 (>= 0, <=9): ");
    } else {
        return output;
    }
}

void Tic_tac_toe::set_winner()
{
    if(player == "X")
    {
        winner = "O";
    } else {
        winner = "X";
    }
}

bool Tic_tac_toe::check_diagonal_win()
{
    if( ( (pegs[0] == pegs[4] && pegs[8] == pegs[4]) || (pegs[2] == pegs[4] && pegs[6] == pegs[4] ) ) && pegs[4] != " ")
    {
        return true;
    } else {
        return false;
    }
}

bool Tic_tac_toe::check_row_win()
{
    for (auto i = 0; i < 7; i += 3)
    {
        if((pegs[i] == pegs[i + 1] && pegs[i + 1] == pegs[i + 2]) && pegs[i] != " ")
        {
            return true;
        }
    }
    return false;
}

bool Tic_tac_toe::check_column_win()
{
    for (auto i = 0; i < 3; i++)
    {
        if((pegs[i] == pegs[i + 3] && pegs[i + 6] == pegs[i + 3]) && pegs[i] != " ")
        {
            return true;
        }
    }
    return false;
}

std::string Tic_tac_toe::get_winner()
{
    return winner;
}