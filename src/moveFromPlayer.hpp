#pragma once
# include <iostream>
# include <string>
# include <fstream>
# include <chrono>
# include <iomanip>
# include <sstream>
# include <memory>
# include "ChessDatabase.hpp"
# include "pieces/Piece.hpp"
# include "gameMode.hpp"
# include "Board.hpp"
#include "common/systemCls.hpp"

class moveFromPlayer
{
public:
	//a5-a6
	//o-o
	//o-o-o
	//a7Qa8

	int wasX, wasY, willX, willY;

	char promotionCH = 'E';

	std::string rawInput = "";

	void getMove(Board& board1, ChessDatabase& database);

	static void getConsent(Board& board1, ChessDatabase& database);

	static void chooseGameMode();

	int which(const Board& board);
};
