#pragma once
# include <iostream>
# include <string>
# include <fstream>
# include <chrono>
#include <iomanip>
# include <sstream>
# include "chessDatabase.h"
# include "piece.h"
# include "gameMode.h"
# include "board.h"

class moveFromPlayer
{
public:
	//a5-a6
	//o-o
	//o-o-o
	//a7Qa8

	int wasX, wasY, willX, willY;

	int moveType = 5; //0 move 1 capture 2 promotion 3 castle 4 long castle

	char promotionCH = 'E';

	std::string rawInput = "";

	void get_move(board& board1, ChessDatabase& database);

	static void get_consent(board& board1, ChessDatabase& database);

	static void choose_game_mode();

	int which(board& board1);
};
