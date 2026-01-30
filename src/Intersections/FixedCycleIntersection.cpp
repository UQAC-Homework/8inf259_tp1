#include "../../include/Intersections/FixedCycleIntersection.h"

void FixedCycleIntersection::updateCounter()
{
	this->cycleCounter++;
	
	if (this->cycleCounter >= NORTH_SOUTH_CYCLE + EAST_WEST_CYCLE)
		this->cycleCounter = 0;
	
	if (this->cycleCounter < NORTH_SOUTH_CYCLE)
		this->allowedDirections = static_cast<Direction>(NORTH | SOUTH);
	else
		this->allowedDirections = static_cast<Direction>(EAST | WEST);
}

FixedCycleIntersection::FixedCycleIntersection(const std::vector<Road*>& roads) : Intersection()
{
	this->roads = roads;
	this->allowedDirections = NONE;
}

void FixedCycleIntersection::process()
{
	this->updateCounter();

	for (const auto road : this->roads)
	{
		// ReSharper disable once CppTooWideScopeInitStatement
		const auto direction = road->getDirection();
		
		if (direction & this->allowedDirections)
			road->process();
	}
}
