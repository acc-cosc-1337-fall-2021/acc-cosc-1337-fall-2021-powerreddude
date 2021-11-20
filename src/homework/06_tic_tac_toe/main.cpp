#include <memory>
#include <iostream>
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_data.h"
//test


int main() 
{
	Tic_tac_toe_data data;
	std::unique_ptr<Tic_tac_toe> game;
	Tic_tac_toe_manager manager(data);


	while(true)
	{
		int game_type = get_int("Please enter 3 for 3x3 or 4 for 4x4 default will be 3x3: ");
		if(game_type == 4) {
			game = std::make_unique<Tic_tac_toe_4>();
		} else {
			game = std::make_unique<Tic_tac_toe_3>();
		}

		game -> start_game(get_str("Please enter who will go first (X or O): "));
		std::cout<<*game;
		do
		{
			std::cin>>*game;
			std::cout<<*game;
		} while (!game -> game_over());

		manager.save_game(game);

		int o, x, t;
		manager.get_winner_total(o, x, t);

		std::cout<<"X wins "<<x<<", O wins "<<o<<", Ties "<<t<<std::endl;

		//std::cout<<"The winner is "<<game -> get_winner()<<std::endl;

		std::string answer;
		std::cout<<"Would you like to contunue playing? (yes/no): ";
		std::cin>>answer;
		if(answer != "yes" && answer != "y")
		{
			std::cout<<manager;
			break;
		}
	} 
	
	return 0;
}