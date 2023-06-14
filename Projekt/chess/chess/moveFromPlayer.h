#pragma once
# include <iostream>
# include <string>
# include "board.h"
# include <fstream>


class moveFromPlayer
{
public:
	//a5-a6
	//a5xa6
	//o-o
	//o-o-o
	//a7Qa8
	//

	int wasX, wasY, willX, willY;

	int moveType; //0 move 1 capture 2 promotion 3 castle 4 long castle

	char promotionCH = 'E';

	void get_move(board& board1);

	void savePositionToFile(board& board1, std::string file);

	
};