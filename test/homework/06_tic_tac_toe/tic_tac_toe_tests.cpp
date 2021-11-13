#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include <memory>

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test game over if 9 slots are selected.", "verification") {
	std::unique_ptr<Tic_tac_toe> game;
	game = std::make_unique<Tic_tac_toe_3>();

	game -> start_game("X");

	//REQUIRE(game.game_over() == false);

	game -> mark_board(1);
	REQUIRE(game -> game_over() == false);
	
	game -> mark_board(2);
	REQUIRE(game -> game_over() == false);

	game -> mark_board(3);
	REQUIRE(game -> game_over() == false);

	game -> mark_board(4);
	REQUIRE(game -> game_over() == false);

	game -> mark_board(5);
	REQUIRE(game -> game_over() == false);

	game -> mark_board(7);
	REQUIRE(game -> game_over() == false);

	game -> mark_board(6);
	REQUIRE(game -> game_over() == false);

	game -> mark_board(9);
	REQUIRE(game -> game_over() == false);

	game -> mark_board(8);
	REQUIRE(game -> game_over());
	
	REQUIRE(game -> get_winner() == "C");
	
}

TEST_CASE("Test first player set to X", "verification") {
	std::unique_ptr<Tic_tac_toe> game;
	game = std::make_unique<Tic_tac_toe_3>();


	game -> start_game("X");
	REQUIRE(game -> get_player() == "X");
}

TEST_CASE("Test first player set to O", "verification") {
	std::unique_ptr<Tic_tac_toe> game;
	game = std::make_unique<Tic_tac_toe_3>();
	
	
	game -> start_game("O");
	REQUIRE(game -> get_player() == "O");
}

TEST_CASE("Test win by first column", "verification") {
	std::unique_ptr<Tic_tac_toe> game;
	game = std::make_unique<Tic_tac_toe_3>();


	game -> start_game("X");

	game -> mark_board(1);
	game -> mark_board(8);
	game -> mark_board(4);
	game -> mark_board(9);
	game -> mark_board(7);
	
	REQUIRE(game -> game_over());
	REQUIRE(game -> get_winner() == "X");
}

TEST_CASE("Test win by second column", "verification") {
	std::unique_ptr<Tic_tac_toe> game;
	game = std::make_unique<Tic_tac_toe_3>();


	game -> start_game("X");

	game -> mark_board(2);
	game -> mark_board(6);
	game -> mark_board(5);
	game -> mark_board(9);
	game -> mark_board(8);
	
	REQUIRE(game -> game_over());
	REQUIRE(game -> get_winner() == "X");
}

TEST_CASE("Test win by third column", "verification") {
	std::unique_ptr<Tic_tac_toe> game;
	game = std::make_unique<Tic_tac_toe_3>();


	game -> start_game("X");

	game -> mark_board(3);
	game -> mark_board(5);
	game -> mark_board(6);
	game -> mark_board(4);
	game -> mark_board(9);
	
	REQUIRE(game -> game_over());
	REQUIRE(game -> get_winner() == "X");
	
	REQUIRE(true == true);
}

TEST_CASE("Test win by first row", "verification") {
	std::unique_ptr<Tic_tac_toe> game;
	game = std::make_unique<Tic_tac_toe_3>();


	game -> start_game("X");

	game -> mark_board(1);
	game -> mark_board(6);
	game -> mark_board(2);
	game -> mark_board(9);
	game -> mark_board(3);
	
	REQUIRE(game -> game_over());
	REQUIRE(game -> get_winner() == "X");
}

TEST_CASE("Test win by second row", "verification") {
	std::unique_ptr<Tic_tac_toe> game;
	game = std::make_unique<Tic_tac_toe_3>();


	game -> start_game("X");

	game -> mark_board(4);
	game -> mark_board(7);
	game -> mark_board(5);
	game -> mark_board(9);
	game -> mark_board(6);
	
	REQUIRE(game -> game_over());
	REQUIRE(game -> get_winner() == "X");
}

TEST_CASE("Test win by third row ", "verification") {
	std::unique_ptr<Tic_tac_toe> game;
	game = std::make_unique<Tic_tac_toe_3>();


	game -> start_game("X");

	game -> mark_board(7);
	game -> mark_board(5);
	game -> mark_board(8);
	game -> mark_board(6);
	game -> mark_board(9);
	
	REQUIRE(game -> game_over());
	REQUIRE(game -> get_winner() == "X");
}

TEST_CASE("Test win diagonally from top left", "verification") {
	std::unique_ptr<Tic_tac_toe> game;
	game = std::make_unique<Tic_tac_toe_3>();


	game -> start_game("X");

	game -> mark_board(1);
	game -> mark_board(4);
	game -> mark_board(5);
	game -> mark_board(6);
	game -> mark_board(9);
	
	REQUIRE(game -> game_over());
	REQUIRE(game -> get_winner() == "X");
}

TEST_CASE("Test win diagonally from bottom left", "verification") {
	std::unique_ptr<Tic_tac_toe> game;
	game = std::make_unique<Tic_tac_toe_3>();


	game -> start_game("X");

	game -> mark_board(7);
	game -> mark_board(4);
	game -> mark_board(5);
	game -> mark_board(6);
	game -> mark_board(3);
	
	REQUIRE(game -> game_over());
	REQUIRE(game -> get_winner() == "X");
}

TEST_CASE("Test TicTacToe manager get winner total function", "verification") {
	std::unique_ptr<Tic_tac_toe> game;
	Tic_tac_toe_manager manager;
	game = std::make_unique<Tic_tac_toe_3>();
	
	game -> start_game("X");

	game -> mark_board(7);
	game -> mark_board(4);
	game -> mark_board(5);
	game -> mark_board(6);
	game -> mark_board(3);
	REQUIRE(game -> game_over());
	REQUIRE(game -> get_winner() == "X");

	manager.save_game(game);
	game = std::make_unique<Tic_tac_toe_3>();

	game -> start_game("O");

	game -> mark_board(7);
	game -> mark_board(4);
	game -> mark_board(5);
	game -> mark_board(6);
	game -> mark_board(3);
	REQUIRE(game -> game_over());
	REQUIRE(game -> get_winner() == "O");

	manager.save_game(game);
	game = std::make_unique<Tic_tac_toe_3>();

	game -> start_game("X");

	game -> mark_board(1);
	game -> mark_board(3);
	game -> mark_board(2);
	game -> mark_board(4);
	game -> mark_board(6);
	game -> mark_board(5);
	game -> mark_board(7);
	game -> mark_board(8);
	game -> mark_board(9);
	REQUIRE(game -> game_over());
	REQUIRE(game -> get_winner() == "C");

	manager.save_game(game);
	int x = 0;
	int o = 0;
	int t = 0;
	manager.get_winner_total(o, x, t);

	REQUIRE(x == 1);
	REQUIRE(o == 1);
	REQUIRE(t == 1);
}







TEST_CASE("Test win by first column 4", "verification") {
	std::unique_ptr<Tic_tac_toe> game;
	game = std::make_unique<Tic_tac_toe_4>();


	game -> start_game("X");

	game -> mark_board(1);
	game -> mark_board(5);
	game -> mark_board(5);
	game -> mark_board(9);
	game -> mark_board(9);
	game -> mark_board(13);
	game -> mark_board(13);
	
	REQUIRE(game -> game_over());
	REQUIRE(game -> get_winner() == "X");
}

TEST_CASE("Test win by second column 4", "verification") {
	std::unique_ptr<Tic_tac_toe> game;
	game = std::make_unique<Tic_tac_toe_4>();


	game -> start_game("X");

	game -> mark_board(2);
	game -> mark_board(6);
	game -> mark_board(6);
	game -> mark_board(10);
	game -> mark_board(10);
	game -> mark_board(14);
	game -> mark_board(14);
	
	REQUIRE(game -> game_over());
	REQUIRE(game -> get_winner() == "X");
}

TEST_CASE("Test win by third column 4", "verification") {
	std::unique_ptr<Tic_tac_toe> game;
	game = std::make_unique<Tic_tac_toe_4>();


	game -> start_game("X");

	game -> mark_board(3);
	game -> mark_board(7);
	game -> mark_board(7);
	game -> mark_board(11);
	game -> mark_board(11);
	game -> mark_board(15);
	game -> mark_board(15);
	
	REQUIRE(game -> game_over());
	REQUIRE(game -> get_winner() == "X");
	
	REQUIRE(true == true);
}

TEST_CASE("Test win by fourth column 4", "verification") {
	std::unique_ptr<Tic_tac_toe> game;
	game = std::make_unique<Tic_tac_toe_4>();


	game -> start_game("X");

	game -> mark_board(4);
	game -> mark_board(8);
	game -> mark_board(8);
	game -> mark_board(12);
	game -> mark_board(12);
	game -> mark_board(16);
	game -> mark_board(16);
	
	REQUIRE(game -> game_over());
	REQUIRE(game -> get_winner() == "X");
	
	REQUIRE(true == true);
}

TEST_CASE("Test win by first row 4", "verification") {
	std::unique_ptr<Tic_tac_toe> game;
	game = std::make_unique<Tic_tac_toe_4>();


	game -> start_game("X");

	game -> mark_board(1);
	game -> mark_board(2);
	game -> mark_board(2);
	game -> mark_board(3);
	game -> mark_board(3);
	game -> mark_board(4);
	game -> mark_board(4);
	
	REQUIRE(game -> game_over());
	REQUIRE(game -> get_winner() == "X");
}

TEST_CASE("Test win by second row 4", "verification") {
	std::unique_ptr<Tic_tac_toe> game;
	game = std::make_unique<Tic_tac_toe_4>();


	game -> start_game("X");

	game -> mark_board(5);
	game -> mark_board(6);
	game -> mark_board(6);
	game -> mark_board(7);
	game -> mark_board(7);
	game -> mark_board(8);
	game -> mark_board(8);
	
	REQUIRE(game -> game_over());
	REQUIRE(game -> get_winner() == "X");
}

TEST_CASE("Test win by third row 4", "verification") {
	std::unique_ptr<Tic_tac_toe> game;
	game = std::make_unique<Tic_tac_toe_4>();


	game -> start_game("X");

	game -> mark_board(9);
	game -> mark_board(10);
	game -> mark_board(10);
	game -> mark_board(11);
	game -> mark_board(11);
	game -> mark_board(12);
	game -> mark_board(12);
	
	REQUIRE(game -> game_over());
	REQUIRE(game -> get_winner() == "X");
}

TEST_CASE("Test win by fourth row 4", "verification") {
	std::unique_ptr<Tic_tac_toe> game;
	game = std::make_unique<Tic_tac_toe_4>();


	game -> start_game("X");

	game -> mark_board(13);
	game -> mark_board(14);
	game -> mark_board(14);
	game -> mark_board(15);
	game -> mark_board(15);
	game -> mark_board(16);
	game -> mark_board(16);
	
	REQUIRE(game -> game_over());
	REQUIRE(game -> get_winner() == "X");
}

TEST_CASE("Test win diagonally from top left 4", "verification") {
	std::unique_ptr<Tic_tac_toe> game;
	game = std::make_unique<Tic_tac_toe_4>();


	game -> start_game("X");

	game -> mark_board(1);
	game -> mark_board(6);
	game -> mark_board(6);
	game -> mark_board(11);
	game -> mark_board(11);
	game -> mark_board(16);
	game -> mark_board(16);
	
	REQUIRE(game -> game_over());
	REQUIRE(game -> get_winner() == "X");
}

TEST_CASE("Test win diagonally from bottom left 4", "verification") {
	std::unique_ptr<Tic_tac_toe> game;
	game = std::make_unique<Tic_tac_toe_4>();


	game -> start_game("X");

	game -> mark_board(4);
	game -> mark_board(7);
	game -> mark_board(7);
	game -> mark_board(10);
	game -> mark_board(10);
	game -> mark_board(13);
	game -> mark_board(13);
	
	REQUIRE(game -> game_over());
	REQUIRE(game -> get_winner() == "X");
}

TEST_CASE("Test TicTacToe manager get winner total function 4", "verification") {
	std::unique_ptr<Tic_tac_toe> game;
	Tic_tac_toe_manager manager;
	game = std::make_unique<Tic_tac_toe_4>();
	
	game -> start_game("X");

	game -> mark_board(1);
	game -> mark_board(2);
	game -> mark_board(2);
	game -> mark_board(3);
	game -> mark_board(3);
	game -> mark_board(4);
	game -> mark_board(4);
	REQUIRE(game -> game_over());
	REQUIRE(game -> get_winner() == "X");

	manager.save_game(game);
	game = std::make_unique<Tic_tac_toe_4>();

	game -> start_game("O");

	game -> mark_board(1);
	game -> mark_board(2);
	game -> mark_board(2);
	game -> mark_board(3);
	game -> mark_board(3);
	game -> mark_board(4);
	game -> mark_board(4);
	REQUIRE(game -> game_over());
	REQUIRE(game -> get_winner() == "O");

	manager.save_game(game);
	game = std::make_unique<Tic_tac_toe_4>();

	game -> start_game("X");

	game -> mark_board(1);
	game -> mark_board(3);
	game -> mark_board(2);
	game -> mark_board(4);
	game -> mark_board(6);
	game -> mark_board(5);
	game -> mark_board(7);
	game -> mark_board(8);
	game -> mark_board(9);
	game -> mark_board(11);
	game -> mark_board(10);
	game -> mark_board(12);
	game -> mark_board(16);
	game -> mark_board(14);
	game -> mark_board(13);
	game -> mark_board(15);
	REQUIRE(game -> game_over());
	REQUIRE(game -> get_winner() == "C");

	manager.save_game(game);
	int x = 0;
	int o = 0;
	int t = 0;
	manager.get_winner_total(o, x, t);

	REQUIRE(x == 1);
	REQUIRE(o == 1);
	REQUIRE(t == 1);
}