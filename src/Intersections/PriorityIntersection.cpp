#include "../../include/Intersections/PriorityIntersection.h"

Direction getDensestDirection(const std::vector<Road*>& roads)
{
	Direction densestDirection = NONE;
	std::size_t highestDensity = 0;
	
	for (const auto road : roads)
	{
		const auto density = road->count();
		
		if (density <= highestDensity)
			continue;
		
		densestDirection = road->getDirection();
		highestDensity = density;
	}
	
	return densestDirection;
}

PriorityIntersection::PriorityIntersection(const std::vector<Road*>& roads) : Intersection()
{
	this->roads = roads;
	this->allowedDirections = NONE;
	this->durationCounter = 0;
}

void PriorityIntersection::process()
{
	if (this->durationCounter >= MAXIMAL_DURATION)
	{
		const auto currentDensestDirection = getDensestDirection(this->roads);
		
		this->allowedDirections = currentDensestDirection;
		this->durationCounter = 0;
	}
	else if (this->durationCounter >= MINIMAL_DURATION)
	{
		// ReSharper disable once CppTooWideScopeInitStatement
		const auto currentDensestDirection = getDensestDirection(this->roads);
		
		if (currentDensestDirection != this->allowedDirections)
		{
			this->allowedDirections = currentDensestDirection;
			this->durationCounter = 0;
		}
	}
	else if (this->allowedDirections == NONE)
	{
		const auto currentDensestDirection = getDensestDirection(this->roads);
		
		this->allowedDirections = currentDensestDirection;
		this->durationCounter = 0;
	}

	for (const auto road : this->roads)
	{
		// ReSharper disable once CppTooWideScopeInitStatement
		const auto direction = road->getDirection();
		
		if (direction & this->allowedDirections)
			road->process();
	}
	
	this->durationCounter++;
}
