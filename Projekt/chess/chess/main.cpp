# include <iostream>
# include "board.h"
# include <vector>
# include <string>
# include "moveFromPlayer.h"
# include "piece.h"
# include <fstream>
# include <sstream>
# include "functions.h"


int main()
{

	get_consent();
	board board1;


	while (true)
	{
		board1.update_board();
		board1.draw_board();
		moveFromPlayer newmove;
		bool temp = 0;
		bool temp2 = 0;
		int temp3 = 0;
		do
		{

			newmove.get_move(board1);

			int whichT = which(board1, newmove);

			temp3 = whichT;

			if (whichT == 99) //error code check
			{
				temp2 = 1;
				break;
			}
			

			temp = board1.pieceTab[whichT]->validate_move(board1.whoToMove, board1.pieceTab[whichT]->colour, newmove.wasX, newmove.wasY, newmove.willX, newmove.willY, newmove.moveType, newmove.promotionCH, board1.boardSTR, whichT);


			
		} while (temp);

		board1.pieceTab[temp3]->move_piece(board1.whoToMove, board1.pieceTab[temp3]->colour, newmove.wasX, newmove.wasY, newmove.willX, newmove.willY, newmove.promotionCH, newmove.moveType, board1.boardSTR, board1.pieceTab, temp3);

		if(temp2 == 0)
			board1.whoToMove = !board1.whoToMove;
		system("cls");
		
	}
}
