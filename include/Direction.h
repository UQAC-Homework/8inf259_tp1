#ifndef INC_8INF259_TP1_DIRECTION_H
#define INC_8INF259_TP1_DIRECTION_H

/// All possible cardinal directions
enum Direction : unsigned char
{
	NONE = 0,

	NORTH = 1 << 0,
	SOUTH = 1 << 1,
	EAST = 1 << 2,
	WEST = 1 << 3
};

/// Gets the opposite direction
Direction operator!(Direction dir);

#endif //INC_8INF259_TP1_DIRECTION_H
