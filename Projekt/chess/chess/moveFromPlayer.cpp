# include "moveFromPlayer.h"

void moveFromPlayer::savePositionToFile(board & board1, std::string file)
{
	std::ofstream file1(file);

	file1 << board1.whoToMove << ";" << board1.whiteCastle << ";" << board1.blackCastle << ";" << std::endl;
	for (int i = 0; i < board1.pieceTab.size(); i++)
	{
		file1 << board1.pieceTab[i]->nameSTR << ";" << board1.pieceTab[i]->x << ";" << board1.pieceTab[i]->y << ";" << board1.pieceTab[i]->colour << std::endl;
	}

}

void moveFromPlayer::get_move(board& board1)
{

	std::string input;
	std::cout << board1.whoToMoveF() << " to move" << std::endl;
	std::cout << "Your move: ";


loop:
	std::cin >> input;
	std::cout << std::endl;
	if (input == "exit")
		exit(0);

	if (input == "save")
	{
		std::string inputSave;
		std::cout << "Name your save file:" << std::endl;

		std::cin >> inputSave;
		std::cout << std::endl;
		
		savePositionToFile(board1, inputSave);
		exit(0);
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