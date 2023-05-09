#pragma once
# include <string>
# include <iostream>
# include <vector>


class piece
{

public:
	int x;
	int y;
	bool isBlack;

	std::string nameSTR;//WP, WB, WR, WN, WQ, WK, BP, BB, BR, BN, BQ, BK


	//virtual int move_piece(int wasX,int wasY,int willX,int willY, int moveType, char promotion, std::string board1[8][8]) = 0; //a5-b3

	//return 1 == illegal move // return 0 == legal
	virtual int validate_move(int wasX, int wasY, int willX, int willY, int moveType, char promotion, std::string board1[8][8]) = 0;
};

class pawn :public piece 
{

public:
	bool isFirstMove = true;

	pawn(int xC, int yC, bool isBlackC);




	virtual int validate_move(int wasX, int wasY, int willX, int willY, int moveType, char promotion, std::string board1[8][8])
	{
		bool isLegal = true;

		if (!isFirstMove)
		{
			if (!(willY - wasY == 1 && wasX == willX && (board1[wasX][wasX + 1] == "OO" || board1[wasX][wasX + 1] == "XX")))
				isLegal = false;
		}
		else if (!(willY - wasY == 2 && wasX == willX && (board1[willX][willY] == "OO" || board1[willX][willY] == "XX")))
			isLegal = false;

		if (!isLegal)
		{
			std::cout << "That is illegal move" << std::endl;
			return 1;
		}


		isFirstMove = false;
	}
	
	//~pawn();
};
