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
	bool whoToMove = 0; //0 white, 1 black

	std::string boardSTR[8][8];

	std::vector <std::shared_ptr<piece>> pieceTab;

	void draw_board();

	board();
	
};