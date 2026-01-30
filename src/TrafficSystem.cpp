#include "../include/TrafficSystem.h"

#include <algorithm>

void TrafficSystem::addIntersection(Intersection* intersection)
{
	this->intersections.push_back(intersection);
}

void TrafficSystem::process() const
{
	for (const auto intersection : this->intersections)
		intersection->process();
}

bool TrafficSystem::hasVehicles() const
{
	return std::ranges::any_of(
		this->intersections.begin(),
		this->intersections.end(),
		[](const auto intersection) { return intersection->count() != 0; }
	);
}

size_t TrafficSystem::getProcessedVehicles() const
{
}

size_t TrafficSystem::getTotalWaitTime() const
{
}
