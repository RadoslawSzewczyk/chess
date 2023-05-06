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

int which(board& board1, moveFromPlayer newmove)
{
	for (int i = 0; i < board1.pieceTab.size(); i++)
	{
		if (newmove.wasX == board1.pieceTab[i]->x && newmove.wasY == board1.pieceTab[i]->y)
		{
			return i;
			break;
		}
	}
}



int main()
{
	board board1;

	board1.update_board();
	board1.draw_board();

	moveFromPlayer newmove;
	//exit if u want to leave
	newmove.get_move(board1);
	

	int whichT = which(board1, newmove);

	board1.pieceTab[whichT]->validate_move(board1.whoToMove, board1.pieceTab[whichT] -> colour, newmove.wasX, newmove.wasY, newmove.willX, newmove.willY, newmove.moveType,newmove.promotionCH, board1.boardSTR);

	board1.pieceTab[whichT]->move_piece(board1.whoToMove, board1.pieceTab[whichT]->colour, newmove.wasX, newmove.wasY, newmove.willX, newmove.willY, newmove.promotionCH, newmove.moveType, board1.boardSTR, board1.pieceTab, whichT);

	board1.update_board();
	board1.draw_board();

	while (true)
	{
		board1.update_board();
		board1.draw_board();

		moveFromPlayer newmove;

		newmove.get_move(board1);

	}
}
