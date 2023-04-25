# include "moveFromPlayer.h"

void moveFromPlayer::get_move(board& board1)
{

	std::string input;
	std::cout << board1.whoToMoveF() << " to move" << std::endl;
	std::cout << "Your move: ";


loop:
	std::cin >> input;
	std::cout << std::endl;
	if ((input.length() >= 3 && input.length() < 6) && (int(input[0]) >= 97 && int(input[0]) <= 104 || int(input[0]) == 111) && (int(input[1]) - 48 >= 1 && int(input[1]) - 48 <= 8 || input[1] == '-') && (input[2] == '-' || input[2] == 'x' || input[2] == 'o' || input[2] == 'Q' || input[2] == 'R' || input[2] == 'N' || input[2] == 'B') && (int(input[3]) >= 97 && int(input[3]) <= 104 || int(input[3]) == 111 || input.empty()) && (int(input[4]) - 48 >= 1 && int(input[4]) - 48 <= 8 || input[4] == '-' || input.empty()))
	{
		goto exit_loop;
	}
	std::cout << "Invalid move\nYour move: ";

	goto loop;

exit_loop:

	if (input[0] != 'o')
	{
		wasX = int(input[0]) - 97;
		wasY = int(input[1]) - 48;
		willX = int(input[3]) - 97;
		willY = int(input[4]) - 48;

		if (input[2] == '-')
			moveType = 0;
		if (input[2] == 'x')
			moveType = 1;
		if (input[2] == 'Q' || input[2] == 'N' || input[2] == 'B' || input[2] == 'R')
		{
			moveType = 2;
			promotionCH = input[2];
		}
	}
	else if (input[4] == 'o')
		moveType = 4;
	else
		moveType = 3;
}