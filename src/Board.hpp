#pragma once
# include <iostream>
# include <vector>
# include "pieces/Piece.hpp"

class Board
{
public:

	bool whoToMove = 0; //0 white, 1 black
	bool whiteCastle = 0;
	bool blackCastle = 0;

	std::string whoToMoveSTR;

	std::string boardSTR[8][8];

	std::vector <std::shared_ptr<Piece>> pieceTab;

	void drawBoard();

	void updateBoard();

	void movePiece(int wasX, int wasY, int willX, int willY, char promotion);

	std::string whoToMoveF();

	bool isCheckmate();

	bool isKingInCheck(int kingX = -1, int kingY = -1);

	bool isOpponentKingInCheck();

	int pieceCount();

	bool castle(bool kingside);

	Board();
	
};