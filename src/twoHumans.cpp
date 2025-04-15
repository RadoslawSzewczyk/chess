#include "gameMode.hpp"

void twoHumans()
{
    Board board;
    ChessDatabase database;
    database.loadPositionsFromFile();
    moveFromPlayer::getConsent(board, database);

    while (true)
    {
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

            isMoveToBeReEntered = board.pieceTab[pieceInTabIndex]->validateMove(board.whoToMove, board.pieceTab[pieceInTabIndex]->colour, newmove.wasX, newmove.wasY, newmove.willX, newmove.willY, board.boardSTR, pieceInTabIndex, 1);

            if (board.isKingInCheck())
            {
                std::cout << "Check! Your King is in check. Try again." << std::endl;
                isMoveToBeReEntered = true;
            }

        } while (isMoveToBeReEntered);


        board.movePiece(newmove.wasX, newmove.wasY, newmove.willX, newmove.willY, newmove.promotionCH);
        board.updateBoard();
    castleend:
        if (board.isCheckmate())
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