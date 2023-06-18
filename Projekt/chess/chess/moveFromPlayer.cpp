#pragma warning(disable : 4996)
# include "moveFromPlayer.h"
# include <chrono>
#include <iomanip>
# include <sstream>

std::string getCurrentDateTime()
{
	const auto now = std::chrono::system_clock::now();
	const std::time_t t_c = std::chrono::system_clock::to_time_t(now);

	std::stringstream ss;
	ss << std::put_time(std::localtime(&t_c), "%Y-%m-%d %H:%M:%S");

	return ss.str();
}

void moveFromPlayer::get_move(board& board1, ChessDatabase database)
{

	std::string input;
	std::cout << board1.whoToMoveF() << " to move" << std::endl;
	std::cout << "Your move: ";


loop:
	std::cin >> input;
	std::cout << std::endl;
	if (input == "exit")
	{
		database.savePositionsToFile();
		exit(0);
	}


	if (input == "save")
	{

		std::string inputName;

		std::cout << "Name your position:" << std::endl;

		std::cin >> inputName;

		std::cout << std::endl;

		ChessPosition position;

		std::string dateTime;
		std::stringstream ss;
		ss << getCurrentDateTime();
		dateTime = ss.str();

		position.name = inputName;
		position.date = dateTime;
		position.pieceTab = board1.pieceTab;
		position.whoToMove = board1.whoToMove;
		position.blackCastle = board1.blackCastle;
		position.whiteCastle = board1.whiteCastle;

		database.addPosition(position);
		std::cout << "Position added " << std::endl;
	}


	if ((input.length() >= 3 && input.length() < 6) && (int(input[0]) >= 97 && int(input[0]) <= 104 || int(input[0]) == 111) && (int(input[1]) - 48 >= 1 && int(input[1]) - 48 <= 8 || input[1] == '-') && (input[2] == '-' || input[2] == 'x' || input[2] == 'o' || input[2] == 'Q' || input[2] == 'R' || input[2] == 'N' || input[2] == 'B') && (int(input[3]) >= 97 && int(input[3]) <= 104 || int(input[3]) == 111 || input.empty()) && (int(input[4]) - 48 >= 1 && int(input[4]) - 48 <= 8 || input[4] == '-' || input.empty()))
	{
		goto exit_loop;
	}
	std::cout << "Invalid move\nYour move: ";

	goto loop;

exit_loop:

	if (input[0] != 'o')
	{
		wasX = 7-(int(input[0]) - 97);//0
		wasY = (int(input[1]) - 49);//7
		willX = 7-(int(input[3]) - 97);
		willY = (int(input[4]) - 49);


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