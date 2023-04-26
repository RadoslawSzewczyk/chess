# include "board.h"


board::board()
//board for game start
{
	for (int i = 0; i < 8; i++)
	{
		std::shared_ptr<pawn> Bpawn1 (new pawn(i, 7, 1));
		std::shared_ptr<pawn> Wpawn1(new pawn(i, 0, 0));

		pieceTab.push_back(Bpawn1);
		pieceTab.push_back(Wpawn1);
	}
}

void board::draw_board()
{
	int tDraw = 1;

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

void board::update_board()
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
		;
		boardSTR[pieceTab[i]->x][pieceTab[i]->y] = pieceTab[i]->nameSTR;
	}

}


std::string board::whoToMoveF()
{
	if (whoToMove)
	{
		return whoToMoveSTR = "Black";
	}
	else
	{
		return whoToMoveSTR = "White";
	}
}