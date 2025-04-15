#pragma warning(disable : 4996)

#include "moveFromPlayer.hpp"

std::string getCurrentDateTime()
{
	const auto now = std::chrono::system_clock::now();
	const std::time_t t_c = std::chrono::system_clock::to_time_t(now);

	std::stringstream ss;
	ss << std::put_time(std::localtime(&t_c), "%Y-%m-%d %H:%M:%S");

	return ss.str();
}
//promotion force choose
void moveFromPlayer::getMove(Board& board1, ChessDatabase& database)
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

	if (input == "o-o-o" || input == "o-o")
	{
		rawInput = input;
		goto exit_loop;
	}

	if ((input.length() >= 3 && input.length() < 6) &&
		(int(input[0]) >= 97 && int(input[0]) <= 104 || int(input[0]) == 111) &&
		(int(input[1]) - 48 >= 1 && int(input[1]) - 48 <= 8) &&
		(input[2] == '-' || input[2] == 'x' || input[2] == 'Q' || input[2] == 'R' || input[2] == 'N' || input[2] == 'B') &&
		((int(input[3]) >= 97) && int(input[3]) <= 104 || input.empty()) &&
		(int(input[4]) - 48 >= 1 && int(input[4]) - 48 <= 8 || input.empty()))
	{
		rawInput = input;
		goto exit_loop;
	}
	std::cout << "Invalid move \n";

	goto loop;

exit_loop:

	if (input[0] != 'o')
	{
		wasX = 7-(int(input[0]) - 97);//0
		wasY = (int(input[1]) - 49);//7
		willX = 7-(int(input[3]) - 97);
		willY = (int(input[4]) - 49);

		if (input[2] == 'Q' || input[2] == 'N' || input[2] == 'B' || input[2] == 'R')
		{
			promotionCH = input[2];
		}
		else
			promotionCH = 'E';
	}
}

void moveFromPlayer::getConsent(Board& board1, ChessDatabase& database)
{
	while (true) {
		int input;
		std::cout << " Press 1 to start\n Press 2 to exit\n Press 3 to load position\n Press 4 to delete position" << std::endl;
		std::cin >> input;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter a number." << std::endl;
			continue;
		}
		if (input == 1)
		{
			clearScreen();
			break;
		}
		else if (input == 2) {
			system("pause");
			exit(0);
		}
		else if (input == 3) {

			if (database.printAllPositions()) {
				continue;
			}

			int index;
			std::cout << "Enter the index of the position to load: ";
			std::cin >> index;

			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input. Please enter a number." << std::endl;
				continue;
			}

			if (index >= 0 && index < database.positions.size()) {
				board1.pieceTab = database.positions[index].pieceTab;
				board1.whoToMove = database.positions[index].whoToMove;
				board1.whiteCastle = database.positions[index].whiteCastle;
				board1.blackCastle = database.positions[index].blackCastle;
			}
			else {
				std::cout << "Invalid position index!" << std::endl;
			}
		}
		else if (input == 4) {
			database.printAllPositions();

			int index;
			std::cout << "Enter the index of the position to delete: ";
			std::cin >> index;

			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input. Please enter a number." << std::endl;
				continue;
			}

			if (index >= 0 && index < database.positions.size()) {
				database.positions.erase(database.positions.begin() + index);
				clearScreen();
				continue;
			}
			else {
				std::cout << "Invalid position index!" << std::endl;
			}
		}
		else
			continue;

	}
}

void moveFromPlayer::chooseGameMode()
{
	int input;
	while (true) 
	{
		std::cout << "Choose Game mode\n 1. Player vs Player\n 2. Player vs Computer [WORK IN PROGRESS...]\n";
		std::cin >> input;
		if (input == 1)
		{
			clearScreen();
			twoHumans();
			return;
		}
		else if (input == 2)
		{
			clearScreen();
			computer();
			return;
		}
		else
		{
			clearScreen();
			continue;
		}
	}
}


int moveFromPlayer::which(const Board& board)
{
	for (int i = 0; i < board.pieceTab.size(); i++)
	{
		if (wasX == board.pieceTab[i]->x && wasY == board.pieceTab[i]->y)
		{
			return i;
		}
	}
	return 99;
}