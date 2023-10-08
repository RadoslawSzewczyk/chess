# include "gameMode.h"

int evaluatePosition(board board1) {
    int score = 0;

    int pieceValues[] = { 100, 300, 300, 500, 900, 0 };
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            std::string piece = board1.boardSTR[i][j];
            if (piece == "WP") score += pieceValues[0];
            else if (piece == "WN") score += pieceValues[1];
            else if (piece == "WB") score += pieceValues[2];
            else if (piece == "WR") score += pieceValues[3];
            else if (piece == "WQ") score += pieceValues[4];
            else if (piece == "BP") score -= pieceValues[0];
            else if (piece == "BN") score -= pieceValues[1];
            else if (piece == "BB") score -= pieceValues[2];
            else if (piece == "BR") score -= pieceValues[3];
            else if (piece == "BQ") score -= pieceValues[4];
        }
    }
 
    return score;
}

std::vector <std::string> all_legal_moves()
{
    //TODO
    if (pieceTab[i]->validate_move(whoToMove, pieceTab[i]->colour, startX, startY, willX, willY, 0, 'E', boardSTR, i, 0)) {
        moves.push_back(move);
}

std::string chessSearch(int depth, char color) 
{
    const char WHITE = 'w';
    const char BLACK = 'b';

    std::string bestMove = "";
    int bestScore = (color == WHITE) ? INT_MIN : INT_MAX;

    if (depth == 0) 
    {
        // Evaluate the current position
        // (You need to implement an evaluation function)
        return bestMove;
    }

    std::vector<std::string> moves = generateMoves();

    for (const std::string& move : moves) {
        // Make the move on the chess board
        makeMove(move);

        // Recursively search the next position with decreased depth
        int score = chessSearch(depth - 1, (color == WHITE) ? BLACK : WHITE);

        // Undo the move to explore other possibilities
        undoMove(move);

        // Update the best move and score based on the current move
        if ((color == WHITE && score > bestScore) || (color == BLACK && score < bestScore)) {
            bestScore = score;
            bestMove = move;
        }
    }

    // Return the best move found at this depth
    return bestMove;
}

void computer()
{
    bool computerColour;

    board board1;
    ChessDatabase database;
    database.loadPositionsFromFile();
    moveFromPlayer::get_consent(board1, database);

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

        if (board1.whoToMove == computerColour)
        {
            //search function
            board1.whoToMove = !board1.whoToMove;
            continue;
        }

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


        board1.move_piece(newmove.wasX, newmove.wasY, newmove.willX, newmove.willY, newmove.promotionCH, temp3);
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