#ifndef INC_8INF259_TP1_FIXEDCYCLEINTERSECTION_H
#define INC_8INF259_TP1_FIXEDCYCLEINTERSECTION_H
#include <vector>

#include "Intersection.h"

#define NORTH_SOUTH_CYCLE 3
#define EAST_WEST_CYCLE 3

class Road;

class FixedCycleIntersection : public Intersection
{
	/// Every road processed by this intersection
	std::vector<Road*> roads;
	
	bool northSouthGoes = false;
	bool eastWestGoes = false;
	
	/// Counter of the current cycle
	int cycleCounter = -1;
	
	/// Updates the traffic lights based off the next cycle
	void updateCounter();
public:
	explicit FixedCycleIntersection(const std::vector<Road*>& roads);
	
	void process() override;
};

#endif //INC_8INF259_TP1_FIXEDCYCLEINTERSECTION_H