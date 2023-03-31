# include "piece.h"

pawn::pawn(int xC, int yC, bool isBlackC)
{
	x = xC;
	y = yC;
	if (isBlackC)
	{
		nameSTR = "BP";
	}
	else
	{
		nameSTR = "WP";
	}
}

pawn::pawn()
{
}

