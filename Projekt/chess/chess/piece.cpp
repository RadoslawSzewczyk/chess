# include "piece.h"

pawn::pawn(int xC, int yC, bool isBlackC)
{
	x = yC;
	y = xC;
	if (isBlackC)
	{
		nameSTR = "BP";
	}
	else
	{
		nameSTR = "WP";
	}
}
