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
	
	std::shared_ptr<queen> Bqueen(new queen(4, 7, 1));
	pieceTab.push_back(Bqueen);

	std::shared_ptr<knight> Bknight(new knight(1, 7, 1));
	pieceTab.push_back(Bknight);

	std::shared_ptr<knight> Bknight2(new knight(6, 7, 1));
	pieceTab.push_back(Bknight2);

	std::shared_ptr<king> Bking(new king(3, 7, 1));
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

	std::shared_ptr<queen> Wqueen(new queen(4, 0, 0));
	pieceTab.push_back(Wqueen);

	std::shared_ptr<knight> Wknight(new knight(1, 0, 0));
	pieceTab.push_back(Wknight);

	std::shared_ptr<knight> Wknight2(new knight(6, 0, 0));
	pieceTab.push_back(Wknight2);

	std::shared_ptr<king> Wking(new king(3, 0, 0));
	pieceTab.push_back(Wking);
}

void board::move_piece(int wasX, int wasY, int willX, int willY, char promotion)
{
	int which;//TODO
	int t = std::numeric_limits<int>::max();

	for (int i = 0; i < pieceTab.size(); i++)
	{
		if (pieceTab[i]->x == willX && pieceTab[i]->y == willY)
			t = i;
	}
	for (int i = 0; i < pieceTab.size(); i++)
	{
		if (wasX == pieceTab[i]->x && wasY == pieceTab[i]->y)
		{
			which = i;
			break;
		}
		else
		{
			which = 99;
		}
	}
	if (which == 99)
	{

	}
	if (t > pieceTab.size())
	{
		pieceTab[which]->x = willX;
		pieceTab[which]->y = willY;
	}
	else if (promotion != 'E')
	{
		if (whoToMove = 0 && wasY == 6 && willY == 7)
		{
			if (promotion == 'Q')
			{
				std::shared_ptr<queen> Wqueen(new queen(2, 7, 0));
				pieceTab.push_back(Wqueen);
			}
			else if (promotion == 'R')
			{
				std::shared_ptr<rook> Wrook(new rook(2, 7, 0));
				pieceTab.push_back(Wrook);
			}
			else if (promotion == 'N')
			{
				std::shared_ptr<knight> Wknight(new knight(2, 7, 0));
				pieceTab.push_back(Wknight);
			}
			else if (promotion == 'B')
			{
				std::shared_ptr<bishop> Wbishop(new bishop(2, 7, 0));
				pieceTab.push_back(Wbishop);
			}
		}
		else if (whoToMove = 1 && wasY == 1 && willY == 0)
		{
			if (promotion == 'Q')
			{
				std::shared_ptr<queen> Bqueen(new queen(2, 7, 1));
				pieceTab.push_back(Bqueen);
			}
			else if (promotion == 'R')
			{
				std::shared_ptr<rook> Brook(new rook(2, 7, 1));
				pieceTab.push_back(Brook);
			}
			else if (promotion == 'N')
			{
				std::shared_ptr<knight> Bknight(new knight(2, 7, 1));
				pieceTab.push_back(Bknight);
			}
			else if (promotion == 'B')
			{
				std::shared_ptr<bishop> Bbishop(new bishop(2, 7, 1));
				pieceTab.push_back(Bbishop);
			}
		}
	}
	else {
		pieceTab[which]->x = willX;
		pieceTab[which]->y = willY;
		pieceTab.erase(next(begin(pieceTab), +t));
	}


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

int board::pieceCount()
{
	return int(pieceTab.size());
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

bool board::isKingInCheck(int kingX, int kingY)
{
	if (kingX == -1)
	{
		for (int i = 0; i < pieceCount(); i++)
		{
			if (pieceTab[i]->nameSTR[1] == 'K' && pieceTab[i]->nameSTR[0] == (whoToMove ? 'B' : 'W'))
			{
				kingX = pieceTab[i]->x;
				kingY = pieceTab[i]->y;
				break;
			}
		}
	}


	for (int i = 0; i < pieceCount(); i++)
	{
		if (!pieceTab[i]->validate_move(whoToMove, pieceTab[i]->colour, pieceTab[i]->x, pieceTab[i]->y, kingX, kingY, 0, 'E', boardSTR, i,0))
		{
			return true;
		}

	}

	return false;
}

bool board::isOpponentKingInCheck()
{
	int kingX = -1;
	int kingY = -1;

	for (int i = 0; i < pieceCount(); i++)
	{
		if (pieceTab[i]->nameSTR[1] == 'K' && pieceTab[i]->nameSTR[0] != (whoToMove ? 'B' : 'W'))
		{
			kingX = pieceTab[i]->x;
			kingY = pieceTab[i]->y;
			break;
		}
	}

	for (int i = 0; i < pieceCount(); i++)
	{
		if (!pieceTab[i]->validate_move(!whoToMove, pieceTab[i]->colour, pieceTab[i]->x, pieceTab[i]->y, kingX, kingY, 0, 'E', boardSTR, i, 0))
		{
			return true;
		}
	}

	return false;
}

bool board::is_checkmate()
{
	int legalMoves = 0;

	int kingX = -1;
	int kingY = -1;
	int kingIndex = -1;


	if (!isOpponentKingInCheck())
		return false;

	for (int i = 0; i < pieceTab.size(); i++)
	{
		if (pieceTab[i]->nameSTR[1] == 'K' && pieceTab[i]->nameSTR[0] != (whoToMove ? 'B' : 'W'))
		{
			kingX = pieceTab[i]->x;
			kingY = pieceTab[i]->y;
			kingIndex = i;
			break;
		}
	}
	board tempBoard;

	tempBoard.whoToMove = whoToMove;
	tempBoard.pieceTab = pieceTab;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			tempBoard.boardSTR[i][j] = boardSTR[i][j];
		}
	}


	if (!pieceTab[kingIndex]->validate_move(!whoToMove, pieceTab[kingIndex]->colour, kingX, kingY, kingX + 1, kingY + 1, 0, 'E', boardSTR, kingIndex, 0))
	{
		tempBoard.move_piece(kingX, kingY, kingX + 1, kingY + 1, 0);
		tempBoard.update_board();
		if(tempBoard.isOpponentKingInCheck())
			return false;
	}

	tempBoard.whoToMove = whoToMove;
	tempBoard.pieceTab = pieceTab;

	if (!pieceTab[kingIndex]->validate_move(!whoToMove, pieceTab[kingIndex]->colour, kingX, kingY, kingX + 1, kingY, 0, 'E', boardSTR, kingIndex, 0))
	{
		tempBoard.move_piece(kingX, kingY, kingX + 1, kingY + 1, 'E');
		tempBoard.update_board();
		if (tempBoard.isOpponentKingInCheck())
			return false;
	}


	tempBoard.whoToMove = whoToMove;
	tempBoard.pieceTab = pieceTab;
	if (!pieceTab[kingIndex]->validate_move(!whoToMove, pieceTab[kingIndex]->colour, kingX, kingY, kingX + 1, kingY - 1, 0, 'E', boardSTR, kingIndex, 0))
	{
		tempBoard.move_piece(kingX, kingY, kingX + 1, kingY - 1, 'E');
		tempBoard.update_board();
		if (tempBoard.isOpponentKingInCheck())
			return false;
	}


	tempBoard.whoToMove = whoToMove;
	tempBoard.pieceTab = pieceTab;
	if (!pieceTab[kingIndex]->validate_move(!whoToMove, pieceTab[kingIndex]->colour, kingX, kingY, kingX - 1, kingY - 1, 0, 'E', boardSTR, kingIndex, 0))
	{
		tempBoard.move_piece(kingX, kingY, kingX - 1, kingY - 1, 'E');
		tempBoard.update_board();
		if (tempBoard.isOpponentKingInCheck())
			return false;
	}


	tempBoard.whoToMove = whoToMove;
	tempBoard.pieceTab = pieceTab;
	if (!pieceTab[kingIndex]->validate_move(!whoToMove, pieceTab[kingIndex]->colour, kingX, kingY, kingX, kingY - 1, 0, 'E', boardSTR, kingIndex, 0))
	{
		tempBoard.move_piece(kingX, kingY, kingX, kingY - 1, 'E');
		tempBoard.update_board();
		if (tempBoard.isOpponentKingInCheck())
			return false;
	}


	tempBoard.whoToMove = whoToMove;
	tempBoard.pieceTab = pieceTab;
	if (!pieceTab[kingIndex]->validate_move(!whoToMove, pieceTab[kingIndex]->colour, kingX, kingY, kingX - 1, kingY, 0, 'E', boardSTR, kingIndex, 0))
	{
		tempBoard.move_piece(kingX, kingY, kingX - 1, kingY, 'E');
		tempBoard.update_board();
		if (tempBoard.isOpponentKingInCheck())
			return false;
	}


	tempBoard.whoToMove = whoToMove;
	tempBoard.pieceTab = pieceTab;
	if (!pieceTab[kingIndex]->validate_move(!whoToMove, pieceTab[kingIndex]->colour, kingX, kingY, kingX - 1, kingY + 1, 0, 'E', boardSTR, kingIndex, 0))
	{
		tempBoard.move_piece(kingX, kingY, kingX - 1, kingY + 1, 'E');
		tempBoard.update_board();
		if (tempBoard.isOpponentKingInCheck())
			return false;
	}


	tempBoard.whoToMove = whoToMove;
	tempBoard.pieceTab = pieceTab;
	if (!pieceTab[kingIndex]->validate_move(!whoToMove, pieceTab[kingIndex]->colour, kingX, kingY, kingX , kingY + 1, 0, 'E', boardSTR, kingIndex, 0))
	{
		tempBoard.move_piece(kingX, kingY, kingX, kingY + 1, 'E');
		tempBoard.update_board();
		if (tempBoard.isOpponentKingInCheck())
			return false;
	}

	return true;
}

bool board::castle(bool kingside)
{
	if (boardSTR[4][0] == "WK" || boardSTR[4][7] == "BK")
		return 0;
	int kingX, kingY;
	int rookX, rookY;

	if (whoToMove == 0) {
		kingX = 3;
		kingY = 0;
		rookX = (kingside) ? 5 : 2;
		rookY = 0;
		if (!kingside)
		{
			if (boardSTR[1][0][0] != 'O' && boardSTR[2][0][0] != 'X' && boardSTR[3][0][0] != 'X' && boardSTR[0][0] != "WR")
				return 0;
			if (isKingInCheck(1, 0) == 1 || isKingInCheck(2, 0) == 1 || isKingInCheck(3, 0) == 1)
				return 0;
		}
		else 
		{
			if (boardSTR[6][0][0] != 'O' && boardSTR[5][0][0] != 'X' && boardSTR[0][0] != "WR")
			{
				return 0;
			}
			if (isKingInCheck(6, 0) == 1 || isKingInCheck(5, 0) == 1)
				return 0;
		}
	}
	else 
	{
		kingX = 3;
		kingY = 7;
		rookX = (kingside) ? 5 : 2;
		rookY = 7;
		if (!kingside)
		{
			if (boardSTR[1][7][0] != 'O' && boardSTR[2][7][0] != 'X' && boardSTR[3][7][0] != 'X' && boardSTR[0][7] != "WR")
				return 0;
			if (isKingInCheck(1, 7) == 1 || isKingInCheck(2, 7) == 1 || isKingInCheck(3, 7) == 1)
				return 0;
		}
		else
		{
			if (boardSTR[6][7][0] != 'O' && boardSTR[5][7][0] != 'X' && boardSTR[0][7] != "WR")
				return 0;
			if (isKingInCheck(6, 7) == 1 || isKingInCheck(5, 7) == 1)
				return 0;
		}
	}

	// TODO CHECK

	if (kingside) {
		move_piece(kingX, kingY, kingX + 2, kingY, 'E');
		move_piece(rookX, rookY, rookX - 2, rookY, 'E');
	}
	else {
		move_piece(kingX, kingY, kingX - 2, kingY, 'E');
		move_piece(rookX, rookY, rookX + 3, rookY, 'E');
	}
}
