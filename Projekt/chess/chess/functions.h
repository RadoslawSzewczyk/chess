#pragma once
# include "chessDatabase.h"

void get_consent(board& board1, ChessDatabase& database)
{
    while (true) {
        int input;
        std::cout << "Wanna play chess?\n Press 1 to start\n Press 2 to exit\n Press 3 to load position\n Press 4 to delete position" << std::endl;
        std::cin >> input;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number." << std::endl;
            continue;
        }

        if (input == 2) {
            exit(0);
        }
        else if (input == 3) {
            database.positions.clear();
            database.positions = database.loadPositionsFromFile();

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
            database.positions = database.loadPositionsFromFile();
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
                system("cls");
                continue;
            }
            else {
                std::cout << "Invalid position index!" << std::endl;
            }
        }

        system("cls");
        break;
    }
}


int which(board& board1, moveFromPlayer& newmove)
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
