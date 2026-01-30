#include "../include/Direction.h"

Direction operator!(const Direction dir)
{
	const int numDir = dir;
	int numOpposite = 0;

	if (numDir & NORTH)
		numOpposite |= SOUTH;

	if (numDir & SOUTH)
		numOpposite |= NORTH;

	if (numDir & EAST)
		numOpposite |= WEST;

	if (numDir & WEST)
		numOpposite |= EAST;

	return static_cast<Direction>(numOpposite);
}
