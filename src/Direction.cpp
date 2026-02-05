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

Direction operator|(const Direction direction1, const Direction direction2)
{
	const int numDir1 = direction1;
	const int numDir2 = direction2;

	return static_cast<Direction>(numDir1 | numDir2);
}