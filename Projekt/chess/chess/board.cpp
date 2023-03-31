# include "board.h"

void board::draw_board()
{
	int tDraw = 1;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (tDraw == 1)
				boardINT[i][j] = "OO";
			else
				boardINT[i][j] = "XX";
			tDraw *= -1;
		}
		tDraw *= -1;
	}

	for (int i = 0; i < pieceTab.size(); i++)
	{
		boardINT[pieceTab[i].x][pieceTab[i].y] = pieceTab[i].nameSTR;
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (tDraw == 1)
				std::cout << " " << boardINT[i][j] << " ";
			else
				std::cout << " " << boardINT[i][j] << " ";
			tDraw *= -1;
		}
		tDraw *= -1;
		std::cout << std::endl;
	}
}

board ::board()
//board for game start
{
	for (int i = 0; i < 8; i++)
	{
		pawn pawn1(0, i, 1);
		pieceTab.push_back(pawn1);
	}
}