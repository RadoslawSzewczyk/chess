# include "piece.h"


king::king(int xC, int yC, bool colourC)
{
	x = xC;
	y = yC;
	colour = colourC;
	if (colourC)
	{
		nameSTR = "BK";
	}
	else
	{
		nameSTR = "WK";
	}
}


bool king::isKingInCheck(bool whoToMove, bool pieceColour, int kingX, int kingY, int newX, int newY, std::string board1[8][8]) 
{
    std::string originalPiece = board1[newX][newY];
    board1[newX][newY] = board1[kingX][kingY];
    board1[kingX][kingY] = "OO";

    bool isInCheck = isKingAttacked(whoToMove, pieceColour, newX, newY, board1);

    board1[kingX][kingY] = board1[newX][newY];
    board1[newX][newY] = originalPiece;

    return isInCheck;
}

bool king::isKingAttacked(bool whoToMove, bool pieceColour, int kingX, int kingY, std::string board1[8][8])
{


    int pawnDir = (pieceColour == whoToMove) ? -1 : 1;
    int pawnX1 = kingX - pawnDir;
    int pawnX2 = kingX + pawnDir;
    int pawnY1 = kingY - 1;
    int pawnY2 = kingY + 1;

    if (pawnX1 >= 0 && pawnX1 < 8 && pawnY1 >= 0 && pawnY1 < 8) {
        std::string pawnPiece = board1[pawnX1][pawnY1];
        if ((pieceColour != whoToMove) && (pawnPiece == "WP" || pawnPiece == "BP")) {
            return true; 
        }
    }

    if (pawnX2 >= 0 && pawnX2 < 8 && pawnY2 >= 0 && pawnY2 < 8) {
        std::string pawnPiece = board1[pawnX2][pawnY2];
        if ((pieceColour != whoToMove) && (pawnPiece == "WP" || pawnPiece == "BP")) {
            return true; 
        }
    }

    int bishopDirs[4][2] = { {1, 1}, {1, -1}, {-1, 1}, {-1, -1} }; 

    for (int i = 0; i < 4; i++) {
        int dirX = bishopDirs[i][0];
        int dirY = bishopDirs[i][1];

        int x = kingX + dirX;
        int y = kingY + dirY;

        while (x >= 0 && x < 8 && y >= 0 && y < 8) {
            std::string piece = board1[x][y];
            if (piece != "OO" && piece != "XX") {
                if ((pieceColour != whoToMove) && (piece == "WB" || piece == "BB" || piece == "WQ" || piece == "BQ")) {
                    return true; 
                }
                else {
                    break; 
                }
            }
            x += dirX;
            y += dirY;
        }
    }

    int rookDirs[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} }; 

    for (int i = 0; i < 4; i++) {
        int dirX = rookDirs[i][0];
        int dirY = rookDirs[i][1];

        int x = kingX + dirX;
        int y = kingY + dirY;

        while (x >= 0 && x < 8 && y >= 0 && y < 8) {
            std::string piece = board1[x][y];
            if (piece != "OO" && piece != "XX") {
                if ((pieceColour != whoToMove) && (piece == "WR" || piece == "BR" || piece == "WQ" || piece == "BQ")) {
                    return true; 
                }
                else {
                    break; 
                }
            }
            x += dirX;
            y += dirY;
        }
    }

    int knightDx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 }; 
    int knightDy[8] = { -1, 1, -2, 2, -2, 2, -1, 1 }; 

    for (int i = 0; i < 8; i++) {
        int x = kingX + knightDx[i];
        int y = kingY + knightDy[i];

        if (x >= 0 && x < 8 && y >= 0 && y < 8) {
            std::string piece = board1[x][y];
            if ((pieceColour != whoToMove) && (piece == "WN" || piece == "BN")) {
                return true; 
            }
        }
    }


    return false;
}


bool king::validate_move(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, int moveType, char promotion, std::string board1[8][8], int which)
{
	bool isLegal = true;

    std::string targetPiece = board1[willX][willY];
    if (targetPiece != "OO" && targetPiece != "XX" && (pieceColour == (targetPiece[0] == 'W'))) {
        return false;
    }

    int dx = abs(wasX - willX);
    int dy = abs(wasY - willY);
    if ((dx == 1 && dy == 0) || (dx == 0 && dy == 1) || (dx == 1 && dy == 1)) {

        if (isKingInCheck(whoToMove, pieceColour, wasX, wasY, willX, willY, board1)) {
            return false;
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}


void king::move_piece(bool whoToMove, bool pieceColour, int wasX, int wasY, int willX, int willY, char promotion, int moveType, std::string board1[8][8], std::vector <std::shared_ptr<piece>>& pieceTab, int which)
{
	if (moveType == 0)
	{
		pieceTab[which]->x = willX;
		pieceTab[which]->y = willY;
	}
	else if (moveType == 1)
	{
		int t;
		for (int i = 0; i < pieceTab.size(); i++)
		{
			if (pieceTab[i]->x == willX && pieceTab[i]->y == willY)
				t = i;
		}
		pieceTab[which]->x = willX;
		pieceTab[which]->y = willY;
		pieceTab.erase(next(begin(pieceTab), +t));
	}
}
king::~king(){}