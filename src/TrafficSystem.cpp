#include "../include/TrafficSystem.h"

#include <algorithm>
#include <numeric>

void TrafficSystem::addIntersection(Intersection* intersection)
{
	this->intersections.push_back(intersection);
}

void TrafficSystem::process()
{
	for (const auto intersection : this->intersections)
	{
		// ReSharper disable once CppTooWideScopeInitStatement
		const auto currentProcessedVehicles = intersection->process();

		for (auto currentVehicule : currentProcessedVehicles)
			this->processedVehicules.push_back(currentVehicule);
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
	return this->processedVehicules.size();
}

size_t TrafficSystem::getTotalWaitTime() const
{
	size_t totalWaitTime = 0;

	for (auto vehicule : this->processedVehicules)
		totalWaitTime += vehicule.getTurnsWaited();

	return totalWaitTime;
}