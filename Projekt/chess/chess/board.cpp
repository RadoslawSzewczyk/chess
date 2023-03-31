# include "board.h"

void board::draw_board()
{
	int tDraw = 1;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (tDraw == 1)
				boardSTR[i][j] = "OO";
			else
				boardSTR[i][j] = "XX";
			tDraw *= -1;
		}
		tDraw *= -1;
	}

	for (int i = 0; i < pieceTab.size(); i++)
	{
		boardSTR[pieceTab[i].x][pieceTab[i].y] = pieceTab[i].nameSTR;
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (tDraw == 1)
				std::cout << " " << boardSTR[i][j] << " ";
			else
				std::cout << " " << boardSTR[i][j] << " ";
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
		pawn pawn1(0, i, 1), *p;
;

		pieceTab.push_back(p);
	}
}