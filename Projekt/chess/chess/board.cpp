# include "board.h"


board::board()
//board for game start
{
	for (int i = 0; i < 8; i++)
	{
		std::shared_ptr<pawn> Bpawn1 (new pawn(i, 6, 1));
		std::shared_ptr<pawn> Wpawn1(new pawn(i, 1, 0));

		pieceTab.push_back(Bpawn1);
		pieceTab.push_back(Wpawn1);
	}
	//black
	std::shared_ptr<bishop> Bbishop(new bishop(2, 7, 1));
	pieceTab.push_back(Bbishop);

	std::shared_ptr<bishop> Bbishop2(new bishop(5, 7, 1));
	pieceTab.push_back(Bbishop2);

	std::shared_ptr<rook> Brook(new rook(7, 7, 1));
	pieceTab.push_back(Brook);

	std::shared_ptr<rook> Brook2(new rook(0, 7, 1));
	pieceTab.push_back(Brook2);
	
	std::shared_ptr<queen> Bqueen(new queen(3, 7, 1));
	pieceTab.push_back(Bqueen);

	std::shared_ptr<knight> Bknight(new knight(1, 7, 1));
	pieceTab.push_back(Bknight);

	std::shared_ptr<knight> Bknight2(new knight(6, 7, 1));
	pieceTab.push_back(Bknight2);

	std::shared_ptr<king> Bking(new king(4, 7, 1));
	pieceTab.push_back(Bking);

	//white
	std::shared_ptr<bishop> Wbishop(new bishop(2, 0, 0));
	pieceTab.push_back(Wbishop);

	std::shared_ptr<bishop> Wbishop2(new bishop(5, 0, 0));
	pieceTab.push_back(Wbishop2);

	std::shared_ptr<rook> Wrook(new rook(7, 0, 0));
	pieceTab.push_back(Wrook);

	std::shared_ptr<rook> Wrook2(new rook(0, 0, 0));
	pieceTab.push_back(Wrook2);

	std::shared_ptr<queen> Wqueen(new queen(3, 0, 0));
	pieceTab.push_back(Wqueen);

	std::shared_ptr<knight> Wknight(new knight(1, 0, 0));
	pieceTab.push_back(Wknight);

	std::shared_ptr<knight> Wknight2(new knight(6, 0, 0));
	pieceTab.push_back(Wknight2);

	std::shared_ptr<king> Wking(new king(4, 0, 0));
	pieceTab.push_back(Wking);
}

void board::draw_board()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << " " << boardSTR[7 - j][7 - i] << " ";
		}
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