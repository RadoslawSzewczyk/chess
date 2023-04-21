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



class move
{
public:
	//a5-a6
	//a5xa6
	//o-o
	//o-o-o
	//a7Qa8
	//

	int wasX, wasY, willX, willY;


	void get_move(board& board1)
	{

		std::string input;
		std::cout << board1.whoToMoveF() << " to move" << std::endl;
		std::cout << "Your move: ";

		do
		{
			std::cin >> input;
			std::cout << std::endl;
			if ((input.length() < 3 || input.length() > 6))
			{
				std::cout << "Invalid move\nYour move: ";
			}
		} while (input.length() < 3 || input.length() > 6);

	}

};

int main()
{
	board board1;

	board1.draw_board();


}
