#include <iostream>
#include "tic_tac_toe.h"


int main() 
{
	Tic_tac_toe game;

	while(true)
	{
		game.start_game(get_str("Please enter who will go first (X or O): "));
		game.display_board();
		do
		{
			game.mark_board(get_int("Please enter the number of the square you would like to mark: "));
			game.display_board();
		} while (!game.game_over());

		std::string answer;
		std::cout<<"Would you like to contunue playing? (yes/no): ";
		std::cin>>answer;
		if(answer == "no")
		{
			break;
		}
	} 
	
	return 0;
}