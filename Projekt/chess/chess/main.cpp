# include <iostream>
# include "board.h"
# include <vector>
# include <string>


void get_consent()
{
	int input1;
	std::cout << "Wanna play chess? \n Press 1 to start\n Press 2 to exit" << std::endl;
	std::cin >> input1;
	if (input1 == 2)
	{
		exit(0);
	}
}

void get_move()
{
	
}


int main()
{

	board board1;
	board1.draw_board();
}