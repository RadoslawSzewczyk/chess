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

	int boardINT[8][8]; 
	std::vector<piece> boardPiece; //moze cos takiego zamiast tych intow i dodac biale i czarne pola jako klase 

	//czy ja mam tutaj zkonstruowac wszystkie figury?? w semsie kazdy pionek ma byc osobna i ustawiac wszystko po kolei na planszy???

	void draw_board()
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				std::cout << boardINT[i][j];
			}
			std::cout << std::endl;
		}
	}

	board()
	//board for game start
	{
		//for (int i = 0; i < 8; i++)
		//{
		//	for (int j = 0; j < 8; j++)
		//	{
		//		pawn pawn1(i, j, 1);
		//		boardINT[i][j] = pawn1.nameINT;
		//	}
		//}
	}

};