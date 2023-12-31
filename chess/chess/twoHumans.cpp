#include "gameMode.h"

void two_humans()
{

    board board1;
    ChessDatabase database;
    database.loadPositionsFromFile();
    moveFromPlayer::get_consent(board1, database);

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
            int whichT = newmove.which(board1);
            temp3 = whichT;

            if (whichT == 99)
            {
                temp = true;
                std::cout << "That is illegal move" << std::endl;
                continue;
            }
            if (newmove.rawInput == "o-o")
            {
                board1.castle(1);
                goto castleend;
            }
            if (newmove.rawInput == "o-o-o")
            {
                board1.castle(0);
                goto castleend;
            }

            temp = board1.pieceTab[whichT]->validate_move(board1.whoToMove, board1.pieceTab[whichT]->colour, newmove.wasX, newmove.wasY, newmove.willX, newmove.willY, newmove.moveType, newmove.promotionCH, board1.boardSTR, whichT, 1);

            if (board1.isKingInCheck())
            {
                std::cout << "Check! Your King is in check. Try again." << std::endl;
                temp = true;
            }

        } while (temp);


        board1.move_piece(newmove.wasX, newmove.wasY, newmove.willX, newmove.willY, newmove.promotionCH);
        board1.update_board();
    castleend:
        if (board1.is_checkmate())
        {
            std::cout << "Checkmate! " << board1.whoToMoveF() << " wins." << std::endl;
            break;
        }
        board1.whoToMove = !board1.whoToMove;

        system("cls");
    }

    database.savePositionsToFile();
    system("pause");
}