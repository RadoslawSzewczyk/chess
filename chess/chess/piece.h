#pragma once
# include <string>
# include <iostream>
# include <vector>
# include <memory>
# include <climits>
# include <limits>

class piece
{

public:
	int x;
	int y;
	bool colour; //0 white // 1 black

	std::string nameSTR;//WP, WB, WR, WN, WQ, WK, BP, BB, BR, BN, BQ, BK

	char typeChar;

	//return 1 == illegal move // return 0 == legal
	virtual bool validate_move(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, int moveType, char promotion, std::string board1[8][8], int which, bool print) = 0;
	virtual char typeCharF() = 0;

};

class pawn :public piece 
{

public:
	bool isFirstMove = true;
	char typeCharF();

	pawn(int xC, int yC, bool colourC);

	virtual bool validate_move(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, int moveType, char promotion, std::string board1[8][8], int which, bool print);
	

	~pawn();
};

class king : public piece
{
public:
	char typeCharF();
	king(int xC, int yC, bool colourC);

	bool isKingInCheck(bool whoToMove, bool pieceColour, int kingX, int kingY, int newX, int newY, std::string board1[8][8]);

	bool isKingAttacked(bool whoToMove, bool pieceColour, int kingX, int kingY, std::string board1[8][8]);

	virtual bool validate_move(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, int moveType, char promotion, std::string board1[8][8], int which, bool print);


	~king();
};

class bishop : public piece
{
public:
	char typeCharF();
	bishop(int xC, int yC, bool colourC);
	virtual bool validate_move(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, int moveType, char promotion, std::string board1[8][8], int which, bool print);

	~bishop();
};

class rook : public piece
{
public:
	char typeCharF();
	rook(int xC, int yC, bool colourC);
	virtual bool validate_move(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, int moveType, char promotion, std::string board1[8][8], int which, bool print);

	~rook();
};

class queen : public piece
{
public:
	char typeCharF();
	queen(int xC, int yC, bool colourC);
	virtual bool validate_move(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, int moveType, char promotion, std::string board1[8][8], int which, bool print);

	~queen();
};

class knight : public piece
{
public:
	char typeCharF();
	knight(int xC, int yC, bool colourC);
	virtual bool validate_move(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, int moveType, char promotion, std::string board1[8][8], int which, bool print);

	~knight();
};