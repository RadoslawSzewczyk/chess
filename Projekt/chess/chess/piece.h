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

	virtual void move_piece(int Nx, int Ny) = 0; //a5b3

};

class pawn :public piece 
{
	bool isFirstMove = true;
public:
	pawn();
	pawn(int xC, int yC, bool isBlackC);

	virtual void move_piece(int Nx, int Ny)
	{
		if (x != Nx && Ny != y + 1)
			std::cout << "Illegal move";
		y = Nx;
	}
	//~pawn();
};
