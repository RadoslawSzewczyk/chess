#pragma once
# include <string>

class piece
{

public:
	int x;
	int y;
	int nameINT;
	bool isBlack;
	std::string nameSTR;//WP, WB, WR, WN, WQ, WK, BP, BB, BR, BN, BQ, BK

	//virtual void movie_piece() = 0;

};

class pawn :public piece 
{
public:
	pawn(int xC, int yC,bool isBlackC)
	{
		x = xC;
		y = yC;
		if (isBlackC)
		{
			nameINT = 10;
			nameSTR = "BP";
		}
		else
		{
			nameINT = 1;
			nameSTR = "WP";
		}
	}
};
