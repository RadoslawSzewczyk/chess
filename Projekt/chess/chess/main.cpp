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





int main()
{
	board board1;

	board1.update_board();
	board1.draw_board();

	moveFromPlayer newmove;

	newmove.get_move(board1);

	std::cout << board1.boardSTR[newmove.wasX][newmove.wasY];

	//trzeba zmienić na vecvec bo nie ma dostępu do odpowiednich klass można dodać pustą klasę pola białego i czarnego
}
