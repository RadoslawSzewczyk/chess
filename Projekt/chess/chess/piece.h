#pragma once
# include <string>
# include <iostream>

class piece
{

public:
	int x;
	int y;
	bool isBlack;

	std::string nameSTR;//WP, WB, WR, WN, WQ, WK, BP, BB, BR, BN, BQ, BK


	virtual void move_piece(int wasX,int wasY,int willX,int willY, int moveType, char promotion, std::vector<std::vector<std::string>>& board1) = 0; //a5-b3

};

class pawn :public piece 
{

public:
	bool isFirstMove = true;

	pawn(int xC, int yC, bool isBlackC);


	virtual void move_piece(int wasX, int wasY, int willX, int willY, int moveType, char promotion, std::vector<std::vector<std::string>>& board1)
	{

		if (isFirstMove && board1[willX][willY])
		{
			;
		}
		isFirstMove = false;
	}
	
	//~pawn();
};
