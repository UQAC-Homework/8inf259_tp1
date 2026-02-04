#include "../../include/Intersections/FixedCycleIntersection.h"

#include <numeric>

#include "../../include/Visitors/IncreaseWaitVisitor.h"

void FixedCycleIntersection::updateCounter()
{
	this->cycleCounter++;

	if (this->cycleCounter >= NORTH_SOUTH_CYCLE + EAST_WEST_CYCLE)
		this->cycleCounter = 0;

	if (this->cycleCounter < NORTH_SOUTH_CYCLE)
		this->allowedDirections = NORTH | SOUTH;
	else
		this->allowedDirections = EAST | WEST;
}

FixedCycleIntersection::FixedCycleIntersection(const std::string& name, const std::vector<std::shared_ptr<Road>>& roads) : Intersection(
	name)
{
	this->roads = roads;
	this->allowedDirections = NONE;
}

std::vector<Vehicle> FixedCycleIntersection::process()
{
	this->updateCounter();

	std::vector<Vehicle> processedVehicles;
	IncreaseWaitVisitor visitor;

	for (const auto& road : this->roads)
	{
		const auto direction = road->getDirection();

		if (direction & this->allowedDirections)
		{
			const auto processedVehicle = road->process();

			if (processedVehicle.has_value())
				processedVehicles.push_back(processedVehicle.value());
		}

		visitor.clean();
		road->accept(visitor);
	}

	return processedVehicles;
}

std::size_t FixedCycleIntersection::count() const
{
	return std::accumulate(
		this->roads.begin(),
		this->roads.end(),
		0,
		[](const std::size_t& sum, const std::shared_ptr<Road>& road)
		{
			return sum + road->count();
		}
	);
}

void FixedCycleIntersection::display(std::ostream& output) const
{
	output << "Intersection \"" << this->name << "\":" << std::endl;
	
	for (const auto& road : this->roads)
		road->display(output);
}
