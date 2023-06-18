#pragma once
# include "chessDatabase.h"
void get_consent(board& board1, ChessDatabase& database)
{
	deleted:
	int input;
	std::cout << "Wanna play chess? \n Press 1 to start\n Press 2 to exit\n Press 3 to load position\n Press 4 to delete position" << std::endl;
	std::cin >> input;
	if (input == 2)
	{
		exit(0);
	}
	if (input == 3)
	{
		database.positions.clear();
		database.positions = database.loadPositionsFromFile();

		if (database.printAllPositions())
			return;

		int index;
		std::cout << "Enter the index of the position to load: ";
		std::cin >> index;

		if (index >= 0 && index < database.positions.size()) 
		{
			board1.pieceTab = database.positions[index].pieceTab;
			board1.whoToMove = database.positions[index].whoToMove;
			board1.whiteCastle = database.positions[index].whiteCastle;
			board1.blackCastle = database.positions[index].blackCastle;
		}
		else 
		{
			std::cout << "Invalid position index!" << std::endl;
		}
	}
	
	if (input == 4)
	{
		database.positions = database.loadPositionsFromFile();
		database.printAllPositions();

		int index;
		std::cout << "Enter the index of the position to delete: ";
		std::cin >> index;
		database.positions.erase(database.positions.begin() + index);
		system("cls");
		goto deleted;
	}

	system("cls");
}

int which(board& board1, moveFromPlayer newmove)
{
	for (int i = 0; i < board1.pieceTab.size(); i++)
	{
		if (newmove.wasX == board1.pieceTab[i]->x && newmove.wasY == board1.pieceTab[i]->y)
		{
			return i;
			break;
		}
	}
	return 99; //error code
}

void move_piece(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, char promotion, int moveType, std::string board1[8][8], std::vector<std::shared_ptr<piece>>& pieceTab, int which)
{

	int t = 99999;
	for (int i = 0; i < pieceTab.size(); i++)
	{
		if (pieceTab[i]->x == willX && pieceTab[i]->y == willY)
			t = i;
	}
	if (t > pieceTab.size())
	{
		pieceTab[which]->x = willX;
		pieceTab[which]->y = willY;
	}
	else {
		pieceTab[which]->x = willX;
		pieceTab[which]->y = willY;
		pieceTab.erase(next(begin(pieceTab), +t));
	}


}
