#include <chrono>
#include <climits>
#include "gameMode.hpp"

int evaluatePosition(Board& board) {
	int score = 0;
	int pieceValues[] = { 100, 300, 300, 500, 900, 0 };

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			std::string Piece = board.boardSTR[i][j];
			if (Piece == "WP") score += pieceValues[0];
			else if (Piece == "WN") score += pieceValues[1];
			else if (Piece == "WB") score += pieceValues[2];
			else if (Piece == "WR") score += pieceValues[3];
			else if (Piece == "WQ") score += pieceValues[4];
			else if (Piece == "BP") score -= pieceValues[0];
			else if (Piece == "BN") score -= pieceValues[1];
			else if (Piece == "BB") score -= pieceValues[2];
			else if (Piece == "BR") score -= pieceValues[3];
			else if (Piece == "BQ") score -= pieceValues[4];
		}
	}

	return score;
}

std::vector <moveFromPlayer> all_legal_moves(Board& board)
{
	std::vector <moveFromPlayer> moves;
	Board boardT = board;
	for (int k = 0; k < boardT.pieceTab.size(); k++)
	{
		moveFromPlayer newmove;
		newmove.wasX = boardT.pieceTab[k]->x;
		newmove.wasY = boardT.pieceTab[k]->y;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				newmove.willX = i;
				newmove.willY = j;

				if (!boardT.pieceTab[k]->validateMove(boardT.whoToMove, boardT.pieceTab[k]->colour, newmove.wasX, newmove.wasY, newmove.willX, newmove.willY, 0, 'E', boardT.boardSTR, k, 0))
				{
					moves.push_back(newmove);
				}
			}
		}
	}
	return moves;
}

struct chessReturn
{
	moveFromPlayer bestMove;
	int eval;
};

chessReturn chessSearch(int depth, bool color, Board& board)
{
	if (depth == 0)
	{
		return { moveFromPlayer(), evaluatePosition(board) };
	}

	std::vector<moveFromPlayer> moves = all_legal_moves(board);
	moveFromPlayer bestMove;
	int bestScore = (color == 0) ? INT_MIN : INT_MAX;

	for (const auto& move : moves) {
		Board newBoard = board;
		newBoard.movePiece(move.wasX, move.wasY, move.willX, move.willY, move.promotionCH);

		chessReturn nextMove = chessSearch(depth - 1, !color, newBoard);
		int currentScore = nextMove.eval;

		if ((color == 0 && currentScore > bestScore) || (color == 1 && currentScore < bestScore))
		{
			bestScore = currentScore;
			bestMove = move;
		}
	}

	return { bestMove, bestScore };
}


void computer()
{
	bool computerColour;

	Board board;
	ChessDatabase database;
	database.loadPositionsFromFile();
	moveFromPlayer::getConsent(board, database);

	while (true)
	{
		int input;
		std::cout << "Choose your colour:\n 1. White\n 2. Black\n";
		std::cin >> input;
		if (input == 1)
		{
			computerColour = 1;
			break;
		}
		else if (input == 2)
		{
			computerColour = 0;
			break;
		}
	}

	while (true)
	{

		if (board.whoToMove == computerColour)
		{
			moveFromPlayer newmove = chessSearch(3, board.whoToMove, board).bestMove;
			int pieceInTabIndex = newmove.which(board);
			board.movePiece(newmove.wasX, newmove.wasY, newmove.willX, newmove.willY, newmove.promotionCH);
			board.whoToMove = !board.whoToMove;
			continue;
		}

		board.updateBoard();
		board.drawBoard();

		moveFromPlayer newmove;
		bool isMoveToBeReEntered = false;

		do
		{
			isMoveToBeReEntered = false;
			newmove.getMove(board, database);
			int pieceInTabIndex = newmove.which(board);

			if (pieceInTabIndex == 99)
			{
				isMoveToBeReEntered = true;
				std::cout << "That is illegal move" << std::endl;
				continue;
			}
			if (newmove.rawInput == "o-o")
			{
				board.castle(1);
				goto castleend;
			}
			if (newmove.rawInput == "o-o-o")
			{
				board.castle(0);
				goto castleend;
			}
			isMoveToBeReEntered = board.pieceTab[pieceInTabIndex]->validateMove(board.whoToMove, board.pieceTab[pieceInTabIndex]->colour, newmove.wasX, newmove.wasY, newmove.willX, newmove.willY, newmove.moveType, newmove.promotionCH, board.boardSTR, pieceInTabIndex, 1);

			if (board.isKingInCheck())
			{
				std::cout << "Check! Your King is in check. Try again." << std::endl;
				isMoveToBeReEntered = true;
			}

		} while (isMoveToBeReEntered);


		board.movePiece(newmove.wasX, newmove.wasY, newmove.willX, newmove.willY, newmove.promotionCH);
		board.updateBoard();
	castleend:
		if (board.is_checkmate())
		{
			std::cout << "Checkmate! " << board.whoToMoveF() << " wins." << std::endl;
			break;
		}

		board.whoToMove = !board.whoToMove;

		clearScreen();
	}

	database.savePositionsToFile();
	system("pause");

}