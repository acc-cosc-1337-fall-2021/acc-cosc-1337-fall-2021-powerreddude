#include <iostream>
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
//test


int main() 
{
	Tic_tac_toe game;
	Tic_tac_toe_manager manager;

	while(true)
	{
		game.start_game(get_str("Please enter who will go first (X or O): "));
		std::cout<<game;
		do
		{
			//game.mark_board(get_int("Please enter the number of the square you would like to mark: "));
			std::cin>>game;
			std::cout<<game;
		} while (!game.game_over());

		manager.save_game(game);

		int o, x, t;
		manager.get_winner_total(o, x, t);

		std::cout<<"X wins "<<x<<", O wins "<<o<<", Ties "<<t<<std::endl;

		std::cout<<"The winner is "<<game.get_winner()<<std::endl;

		std::string answer;
		std::cout<<"Would you like to contunue playing? (yes/no): ";
		std::cin>>answer;
		if(answer == "no")
		{
			std::cout<<manager;
			break;
		}
	} 
	
	return 0;
}