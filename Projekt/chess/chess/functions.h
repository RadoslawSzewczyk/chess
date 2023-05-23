#pragma once
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
}

