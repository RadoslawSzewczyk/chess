# include <iostream>
# include "board.h"
# include <vector>
# include <string>


void get_consent()
{
	int input;
	std::cout << "Wanna play chess? \n Press 1 to start\n Press 2 to exit" << std::endl;
	std::cin >> input;
	if (input == 2)
	{
		exit(0);
	}
}

void get_move()
{
	std::string input;
	std::cout << "Your move: ";
	std::cin >> input;

	if (input.length() == 2)
	{
		;
	}
}


int main()
{
	board board1;

	board1.draw_board();
}
