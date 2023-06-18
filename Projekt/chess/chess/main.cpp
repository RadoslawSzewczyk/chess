# include <iostream>
# include "board.h"
# include <vector>
# include <string>
# include "moveFromPlayer.h"
# include "piece.h"
# include <fstream>
# include <sstream>
# include "functions.h"
# include "chessDatabase.h"

int main()
{
    board board1;
    ChessDatabase database;
    get_consent(board1, database);

    while (true)
    {
        board1.update_board();
        board1.draw_board();
        moveFromPlayer newmove;
        bool temp = false;
        bool temp2 = false;
        int temp3 = 0;

        do
        {
            temp = false;
            newmove.get_move(board1, database);
            int whichT = which(board1, newmove);
            temp3 = whichT;

            if (whichT == 99) // error code check
            {
                temp = true;
                std::cout << "That is illegal move" << std::endl;
                continue;
            }

            temp = board1.pieceTab[whichT]->validate_move(board1.whoToMove, board1.pieceTab[whichT]->colour, newmove.wasX, newmove.wasY, newmove.willX, newmove.willY, newmove.moveType, newmove.promotionCH, board1.boardSTR, whichT);

            if (board1.isKingInCheck())
            {
                std::cout << "Check! Your King is in check. Try again." << std::endl;
                temp = true;
            }

        } while (temp);


        move_piece(board1.whoToMove, board1.pieceTab[temp3]->colour, newmove.wasX, newmove.wasY, newmove.willX, newmove.willY, newmove.promotionCH, newmove.moveType, board1.boardSTR, board1.pieceTab, temp3);

        if (board1.isCheckmate())
        {
            std::cout << "Checkmate! " << board1.whoToMoveF() << " wins." << std::endl;
            break;
        }

        board1.whoToMove = !board1.whoToMove;

        system("cls");
    }

    database.savePositionsToFile();
}

