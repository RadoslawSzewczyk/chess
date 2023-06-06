# include <iostream>
# include "board.h"
# include <vector>
# include <string>
# include "moveFromPlayer.h"
# include "piece.h"
# include <fstream>
# include <sstream>
# include "functions.h"


//while (file1)
//{
//	file1 << i;
//	std::stringstream sstr(i);
//	std::vector<std::string> v;
//	while (sstr.good())
//	{
//		std::string substr;
//		getline(sstr, substr, ';');
//		v.push_back(substr);
//	}
//}

int main()
{

	get_consent();
	board board1;

	while (true)
	{
		board1.update_board();
		board1.draw_board();
		moveFromPlayer newmove;
		bool pom = 0;
		do
		{

			newmove.get_move(board1);

			int whichT = which(board1, newmove);

			pom = board1.pieceTab[whichT]->validate_move(board1.whoToMove, board1.pieceTab[whichT]->colour, newmove.wasX, newmove.wasY, newmove.willX, newmove.willY, newmove.moveType, newmove.promotionCH, board1.boardSTR, whichT);


			board1.pieceTab[whichT]->move_piece(board1.whoToMove, board1.pieceTab[whichT]->colour, newmove.wasX, newmove.wasY, newmove.willX, newmove.willY, newmove.promotionCH, newmove.moveType, board1.boardSTR, board1.pieceTab, whichT);

		} while (pom);
		
		board1.whoToMove = !board1.whoToMove;
		system("cls");
	}
}
