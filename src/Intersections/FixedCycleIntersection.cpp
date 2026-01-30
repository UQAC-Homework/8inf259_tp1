#include "../../include/Intersections/FixedCycleIntersection.h"

#include "../../include/Road.h"

// NS
// NS
// NS
// EW
// EW
// EW
// NS
// NS
// NS
// ...

void FixedCycleIntersection::updateCounter()
{
	this->cycleCounter++;
	
	if (this->cycleCounter >= NORTH_SOUTH_CYCLE + EAST_WEST_CYCLE)
		this->cycleCounter = 0;
	
	if (this->cycleCounter < NORTH_SOUTH_CYCLE)
	{
		this->northSouthGoes = true;
		this->eastWestGoes = false;
	}
	else
	{
		this->northSouthGoes = false;
		this->eastWestGoes = true;
	}
}

FixedCycleIntersection::FixedCycleIntersection(const std::vector<Road*>& roads) : Intersection()
{
	this->roads = roads;
}

void FixedCycleIntersection::process()
{
	this->updateCounter();

	for (const auto road : this->roads)
	{
		// ReSharper disable once CppTooWideScopeInitStatement
		const auto direction = road->getDirection();
		
		if (northSouthGoes && direction & (NORTH | SOUTH))
			road->process();
		else if (eastWestGoes && direction & (EAST | WEST))
			road->process();
	}
}
