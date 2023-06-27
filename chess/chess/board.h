#pragma once
# include <iostream>
# include <vector>
# include "piece.h"

class board
{
public:

	bool whoToMove = 0; //0 white, 1 black
	bool whiteCastle = 0;
	bool blackCastle = 0;

	std::string whoToMoveSTR;

	std::string boardSTR[8][8];

	std::vector <std::shared_ptr<piece>> pieceTab;

	void draw_board();

	void update_board();

	void move_piece(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, char promotion, int moveType, std::string board1[8][8], std::vector<std::shared_ptr<piece>>& pieceTab, int which);

	std::string whoToMoveF();

	bool is_checkmate();

	bool isKingInCheck();

	bool isOpponentKingInCheck();

	int pieceCount();

	board();
	
};