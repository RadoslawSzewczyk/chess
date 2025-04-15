#pragma once
# include <string>
# include <iostream>
# include <vector>
# include <memory>
# include <climits>
# include <limits>

struct validateMoveStruct
{
	bool whoToMove;
	bool pieceColour;
	int wasX;
	int wasY;
	int willX;
	int willY;
	std::string board[8][8];
	int whichT;
	bool print;
};

class Piece
{

public:
	int x;
	int y;
	bool colour; //0 white // 1 black

	std::string nameSTR;//WP, WB, WR, WN, WQ, WK, BP, BB, BR, BN, BQ, BK

	char typeChar;

	//return 1 == illegal move // return 0 == legal
	virtual bool validateMove(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, std::string board1[8][8], int which, bool print) = 0;
	virtual char typeCharF() = 0;

};

class Pawn :public Piece 
{

public:
	bool isFirstMove = true;
	char typeCharF();

	Pawn(int xC, int yC, bool colourC);

	virtual bool validateMove(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, std::string board1[8][8], int which, bool print);
	

	~Pawn();
};

class King : public Piece
{
public:
	char typeCharF();
	King(int xC, int yC, bool colourC);

	bool isKingInCheck(bool whoToMove, bool pieceColour, int kingX, int kingY, int newX, int newY, std::string board1[8][8]);

	bool isKingAttacked(bool whoToMove, bool pieceColour, int kingX, int kingY, std::string board1[8][8]);

	virtual bool validateMove(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, std::string board1[8][8], int which, bool print);


	~King();
};

class Bishop : public Piece
{
public:
	char typeCharF();
	Bishop(int xC, int yC, bool colourC);
	virtual bool validateMove(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, std::string board1[8][8], int which, bool print);

	~Bishop();
};

class Rook : public Piece
{
public:
	char typeCharF();
	Rook(int xC, int yC, bool colourC);
	virtual bool validateMove(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, std::string board1[8][8], int which, bool print);

	~Rook();
};

class Queen : public Piece
{
public:
	char typeCharF();
	Queen(int xC, int yC, bool colourC);
	virtual bool validateMove(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, std::string board1[8][8], int which, bool print);

	~Queen();
};

class Knight : public Piece
{
public:
	char typeCharF();
	Knight(int xC, int yC, bool colourC);
	virtual bool validateMove(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, std::string board1[8][8], int which, bool print);

	~Knight();
};