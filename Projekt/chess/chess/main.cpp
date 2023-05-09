# include <iostream>
# include "board.h"
# include <vector>
# include <string>
# include "moveFromPlayer.h"
# include "piece.h"

void get_consent()
{
	int input;
	std::cout << "Wanna play chess? \n Press 1 to start\n Press 2 to exit" << std::endl;
	std::cin >> input;
	if (input == 2)
	{
		exit(0);
	}
}


int which_piece_to_move(board& board1, moveFromPlayer newmove)
{
	for (int i = 0; i < board1.pieceTab.size(); i++)
	{
		if (newmove.wasX == board1.pieceTab[i]->x && newmove.wasY == board1.pieceTab[i]->y)
			return i;
	}
}


int main()
{
	board board1;

	board1.update_board();
	board1.draw_board();

	moveFromPlayer newmove;

	std::string whoToMove = board1.whoToMoveF();

	newmove.get_move(whoToMove);

	std::cout << board1.pieceTab[which_piece_to_move(board1, newmove)]->validate_move(newmove.wasX, newmove.wasY, newmove.willX, newmove.willY,newmove.moveType, newmove.promotionCH, board1.boardSTR);

}
