#pragma once
# include <iostream>
# include <vector>
# include "piece.h"

class board
{
public:
	//TODO
	//isCheck
	//turn
	//white, black castle
	//

	//int board
	//0 - brak
	//1 - pawn
	//2 - rook
	//3 - bishop
	//4 - knight
	//5 - queen
	//6 - king
	//black piece + 10

	std::string boardINT[8][8];

	//piece pawnTab[8];

	std::vector <piece> pieceTab;

	void draw_board();

	board();
	
};