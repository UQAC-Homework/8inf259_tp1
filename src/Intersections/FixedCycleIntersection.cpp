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

FixedCycleIntersection::FixedCycleIntersection(const std::string& name, const std::vector<Road*>& roads) : Intersection(name)
{
	this->roads = roads;
	this->allowedDirections = NONE;
}

std::vector<Vehicule> FixedCycleIntersection::process()
{
	this->updateCounter();
	
	std::vector<Vehicule> processedVehicules;

	for (const auto road : this->roads)
	{
		// ReSharper disable once CppTooWideScopeInitStatement
		const auto direction = road->getDirection();
		
		if (direction & this->allowedDirections)
		{
			const auto processedVehicule = road->process();
			processedVehicules.push_back(processedVehicule);
		}
	}
	
	return processedVehicules;
}

std::size_t FixedCycleIntersection::count() const
{
	size_t count = 0;

	for (const auto road : this->roads)
		count += road->count();
	
	return count;
}
