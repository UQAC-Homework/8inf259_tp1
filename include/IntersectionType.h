#ifndef INC_8INF259_TP1_INTERSECTIONTYPE_H
#define INC_8INF259_TP1_INTERSECTIONTYPE_H

/// All possible types of an intersection
enum IntersectionType
{
	/// Intersection using priority
	PRIORITY_LIGHT,
	
	/// Intersection using a fixed cycle
	FIXED_LIGHT,
	
	/// Intersection using a 4-ways stop
	FOUR_WAY_STOP
};

#endif //INC_8INF259_TP1_INTERSECTIONTYPE_H