#include "../include/TrafficSystem.h"

#include <algorithm>

void TrafficSystem::addIntersection(Intersection* intersection)
{
	this->intersections.push_back(intersection);
}

void TrafficSystem::process()
{
	for (const auto intersection : this->intersections)
	{
		const auto currentProcessedVehicles = intersection->process();

		for (auto currentVehicle : currentProcessedVehicles)
			this->processedVehicles.push_back(currentVehicle);
	}
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
	return this->processedVehicles.size();
}

size_t TrafficSystem::getTotalWaitTime() const
{
	size_t totalWaitTime = 0;

	for (auto vehicle : this->processedVehicles)
		totalWaitTime += vehicle.getTurnsWaited();

	return totalWaitTime;
}

void TrafficSystem::display(std::ostream& output) const
{
	for (const auto intersection : this->intersections)
		intersection->display(output);
}
