# include "Board.hpp"

Board::Board()
//Board for game start
{
	for (int i = 0; i < 8; i++)
	{
		std::shared_ptr<Pawn> Bpawn1 (new Pawn(i, 6, 1));
		std::shared_ptr<Pawn> Wpawn1(new Pawn(i, 1, 0));

		pieceTab.push_back(Bpawn1);
		pieceTab.push_back(Wpawn1);
	}
	//black
	std::shared_ptr<Bishop> Bbishop(new Bishop(2, 7, 1));
	pieceTab.push_back(Bbishop);

	std::shared_ptr<Bishop> Bbishop2(new Bishop(5, 7, 1));
	pieceTab.push_back(Bbishop2);

	std::shared_ptr<Rook> Brook(new Rook(7, 7, 1));
	pieceTab.push_back(Brook);

	std::shared_ptr<Rook> Brook2(new Rook(0, 7, 1));
	pieceTab.push_back(Brook2);
	
	std::shared_ptr<Queen> Bqueen(new Queen(4, 7, 1));
	pieceTab.push_back(Bqueen);

	std::shared_ptr<Knight> Bknight(new Knight(1, 7, 1));
	pieceTab.push_back(Bknight);

	std::shared_ptr<Knight> Bknight2(new Knight(6, 7, 1));
	pieceTab.push_back(Bknight2);

	std::shared_ptr<King> Bking(new King(3, 7, 1));
	pieceTab.push_back(Bking);

	//white
	std::shared_ptr<Bishop> Wbishop(new Bishop(2, 0, 0));
	pieceTab.push_back(Wbishop);

	std::shared_ptr<Bishop> Wbishop2(new Bishop(5, 0, 0));
	pieceTab.push_back(Wbishop2);

	std::shared_ptr<Rook> Wrook(new Rook(7, 0, 0));
	pieceTab.push_back(Wrook);

	std::shared_ptr<Rook> Wrook2(new Rook(0, 0, 0));
	pieceTab.push_back(Wrook2);

	std::shared_ptr<Queen> Wqueen(new Queen(4, 0, 0));
	pieceTab.push_back(Wqueen);

	std::shared_ptr<Knight> Wknight(new Knight(1, 0, 0));
	pieceTab.push_back(Wknight);

	std::shared_ptr<Knight> Wknight2(new Knight(6, 0, 0));
	pieceTab.push_back(Wknight2);

	std::shared_ptr<King> Wking(new King(3, 0, 0));
	pieceTab.push_back(Wking);
}

void Board::movePiece(int wasX, int wasY, int willX, int willY, char promotion)
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
				std::shared_ptr<Queen> Wqueen(new Queen(2, 7, 0));
				pieceTab.push_back(Wqueen);
			}
			else if (promotion == 'R')
			{
				std::shared_ptr<Rook> Wrook(new Rook(2, 7, 0));
				pieceTab.push_back(Wrook);
			}
			else if (promotion == 'N')
			{
				std::shared_ptr<Knight> Wknight(new Knight(2, 7, 0));
				pieceTab.push_back(Wknight);
			}
			else if (promotion == 'B')
			{
				std::shared_ptr<Bishop> Wbishop(new Bishop(2, 7, 0));
				pieceTab.push_back(Wbishop);
			}
		}
		else if (whoToMove = 1 && wasY == 1 && willY == 0)
		{
			if (promotion == 'Q')
			{
				std::shared_ptr<Queen> Bqueen(new Queen(2, 7, 1));
				pieceTab.push_back(Bqueen);
			}
			else if (promotion == 'R')
			{
				std::shared_ptr<Rook> Brook(new Rook(2, 7, 1));
				pieceTab.push_back(Brook);
			}
			else if (promotion == 'N')
			{
				std::shared_ptr<Knight> Bknight(new Knight(2, 7, 1));
				pieceTab.push_back(Bknight);
			}
			else if (promotion == 'B')
			{
				std::shared_ptr<Bishop> Bbishop(new Bishop(2, 7, 1));
				pieceTab.push_back(Bbishop);
			}
		}
	}
	else
	{
		pieceTab[which]->x = willX;
		pieceTab[which]->y = willY;
		pieceTab.erase(next(begin(pieceTab), +t));
	}


}

void Board::drawBoard()
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

void Board::updateBoard()
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

int Board::pieceCount()
{
	return int(pieceTab.size());
}

std::string Board::whoToMoveF()
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

bool Board::isKingInCheck(int kingX, int kingY)
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
		if (!pieceTab[i]->validateMove(whoToMove, pieceTab[i]->colour, pieceTab[i]->x, pieceTab[i]->y, kingX, kingY, 0, 'E', boardSTR, i,0))
		{
			return true;
		}

	}

	return false;
}

bool Board::isOpponentKingInCheck()
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
		if (!pieceTab[i]->validateMove(!whoToMove, pieceTab[i]->colour, pieceTab[i]->x, pieceTab[i]->y, kingX, kingY, 0, 'E', boardSTR, i, 0))
		{
			return true;
		}
	}

	return false;
}

bool Board::is_checkmate()
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
	Board tempBoard;

	tempBoard.whoToMove = whoToMove;
	tempBoard.pieceTab = pieceTab;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			tempBoard.boardSTR[i][j] = boardSTR[i][j];
		}
	}


	if (!pieceTab[kingIndex]->validateMove(!whoToMove, pieceTab[kingIndex]->colour, kingX, kingY, kingX + 1, kingY + 1, 0, 'E', boardSTR, kingIndex, 0))
	{
		tempBoard.movePiece(kingX, kingY, kingX + 1, kingY + 1, 0);
		tempBoard.updateBoard();
		if(tempBoard.isOpponentKingInCheck())
			return false;
	}

	tempBoard.whoToMove = whoToMove;
	tempBoard.pieceTab = pieceTab;

	if (!pieceTab[kingIndex]->validateMove(!whoToMove, pieceTab[kingIndex]->colour, kingX, kingY, kingX + 1, kingY, 0, 'E', boardSTR, kingIndex, 0))
	{
		tempBoard.movePiece(kingX, kingY, kingX + 1, kingY + 1, 'E');
		tempBoard.updateBoard();
		if (tempBoard.isOpponentKingInCheck())
			return false;
	}


	tempBoard.whoToMove = whoToMove;
	tempBoard.pieceTab = pieceTab;
	if (!pieceTab[kingIndex]->validateMove(!whoToMove, pieceTab[kingIndex]->colour, kingX, kingY, kingX + 1, kingY - 1, 0, 'E', boardSTR, kingIndex, 0))
	{
		tempBoard.movePiece(kingX, kingY, kingX + 1, kingY - 1, 'E');
		tempBoard.updateBoard();
		if (tempBoard.isOpponentKingInCheck())
			return false;
	}


	tempBoard.whoToMove = whoToMove;
	tempBoard.pieceTab = pieceTab;
	if (!pieceTab[kingIndex]->validateMove(!whoToMove, pieceTab[kingIndex]->colour, kingX, kingY, kingX - 1, kingY - 1, 0, 'E', boardSTR, kingIndex, 0))
	{
		tempBoard.movePiece(kingX, kingY, kingX - 1, kingY - 1, 'E');
		tempBoard.updateBoard();
		if (tempBoard.isOpponentKingInCheck())
			return false;
	}


	tempBoard.whoToMove = whoToMove;
	tempBoard.pieceTab = pieceTab;
	if (!pieceTab[kingIndex]->validateMove(!whoToMove, pieceTab[kingIndex]->colour, kingX, kingY, kingX, kingY - 1, 0, 'E', boardSTR, kingIndex, 0))
	{
		tempBoard.movePiece(kingX, kingY, kingX, kingY - 1, 'E');
		tempBoard.updateBoard();
		if (tempBoard.isOpponentKingInCheck())
			return false;
	}


	tempBoard.whoToMove = whoToMove;
	tempBoard.pieceTab = pieceTab;
	if (!pieceTab[kingIndex]->validateMove(!whoToMove, pieceTab[kingIndex]->colour, kingX, kingY, kingX - 1, kingY, 0, 'E', boardSTR, kingIndex, 0))
	{
		tempBoard.movePiece(kingX, kingY, kingX - 1, kingY, 'E');
		tempBoard.updateBoard();
		if (tempBoard.isOpponentKingInCheck())
			return false;
	}


	tempBoard.whoToMove = whoToMove;
	tempBoard.pieceTab = pieceTab;
	if (!pieceTab[kingIndex]->validateMove(!whoToMove, pieceTab[kingIndex]->colour, kingX, kingY, kingX - 1, kingY + 1, 0, 'E', boardSTR, kingIndex, 0))
	{
		tempBoard.movePiece(kingX, kingY, kingX - 1, kingY + 1, 'E');
		tempBoard.updateBoard();
		if (tempBoard.isOpponentKingInCheck())
			return false;
	}


	tempBoard.whoToMove = whoToMove;
	tempBoard.pieceTab = pieceTab;
	if (!pieceTab[kingIndex]->validateMove(!whoToMove, pieceTab[kingIndex]->colour, kingX, kingY, kingX , kingY + 1, 0, 'E', boardSTR, kingIndex, 0))
	{
		tempBoard.movePiece(kingX, kingY, kingX, kingY + 1, 'E');
		tempBoard.updateBoard();
		if (tempBoard.isOpponentKingInCheck())
			return false;
	}

	return true;
}

bool Board::castle(bool kingside)
{
	if (boardSTR[4][0] == "WK" || boardSTR[4][7] == "BK")
		return 0;
	int kingX, kingY;
	int rookX, rookY;

	if (whoToMove == 0)
	{
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

	if (kingside)
	{
		movePiece(kingX, kingY, kingX + 2, kingY, 'E');
		movePiece(rookX, rookY, rookX - 2, rookY, 'E');
	}
	else {
		movePiece(kingX, kingY, kingX - 2, kingY, 'E');
		movePiece(rookX, rookY, rookX + 3, rookY, 'E');
	}
	return 1;
}
