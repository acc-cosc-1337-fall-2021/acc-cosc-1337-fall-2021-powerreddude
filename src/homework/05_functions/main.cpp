/*
use a vector of int with values 8, 4, 20, 88, 66, 99

Prompt user for 1 for Get Max from vector and 2 for Get primes.
Prompt user for a number and return max value or list of primes
and display them to screen.
Program continues until user decides to exit.

*/
#include <func.h>
#include <iostream>

int main() 
{
	bool cont;

	do
	{
		print_menu();

		cont = run_menu_choice();
	} while (cont == true);
	
	return 0;
}