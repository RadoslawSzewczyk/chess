#pragma once
# include <string>
# include <iostream>
# include <vector>

class piece
{

public:
	int x;
	int y;
	bool colour; //0 white // 1 black

	std::string nameSTR;//WP, WB, WR, WN, WQ, WK, BP, BB, BR, BN, BQ, BK

	//return 1 == illegal move // return 0 == legal
	virtual bool validate_move(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, int moveType, char promotion, std::string board1[8][8], int which) = 0;

	virtual void move_piece(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, char promotion,int moveType, std::string board1[8][8], std::vector <std::shared_ptr<piece>>& pieceTab, int which) = 0;
};

class pawn :public piece 
{

public:
	bool isFirstMove = true;

	pawn(int xC, int yC, bool colourC);

	virtual bool validate_move(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, int moveType, char promotion, std::string board1[8][8], int which);
	
	virtual void move_piece(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, char promotion,int moveType, std::string board1[8][8], std::vector <std::shared_ptr<piece>>& pieceTab, int which);

	~pawn();
};

class king : public piece
{
	king(int xC, int yC, bool colourC);
	//virtual int validate_move(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, int moveType, char promotion, std::string board1[8][8]);

	//virtual void move_piece(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, char promotion, int moveType, std::string board1[8][8], std::vector <std::shared_ptr<piece>>& pieceTab, int which);

};

class bishop : public piece
{
public:
	bishop(int xC, int yC, bool colourC);
	virtual bool validate_move(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, int moveType, char promotion, std::string board1[8][8], int which);

	virtual void move_piece(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, char promotion, int moveType, std::string board1[8][8], std::vector <std::shared_ptr<piece>>& pieceTab, int which);

};

class rook : public piece
{
public:
	rook(int xC, int yC, bool colourC);
	virtual bool validate_move(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, int moveType, char promotion, std::string board1[8][8], int which);

	virtual void move_piece(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, char promotion, int moveType, std::string board1[8][8], std::vector <std::shared_ptr<piece>>& pieceTab, int which);
};