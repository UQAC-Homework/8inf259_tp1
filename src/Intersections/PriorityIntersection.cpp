#include "../../include/Intersections/PriorityIntersection.h"

#include <numeric>

#include "../../include/Intersections/Intersection.h"
#include "../../include/Visitors/IncreaseWaitVisitor.h"

Direction getDensestDirection(const std::vector<std::shared_ptr<Road>>& roads)
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

void PriorityIntersection::updateCounter()
{
	if (this->durationCounter >= MAXIMAL_DURATION)
	{
		const auto currentDensestDirection = getDensestDirection(this->roads);

		this->allowedDirections = currentDensestDirection | !currentDensestDirection;
		this->durationCounter = 0;
	}
	else if (this->durationCounter >= MINIMAL_DURATION)
	{
		const auto currentDensestDirection = getDensestDirection(this->roads);

		if (currentDensestDirection != this->allowedDirections)
		{
			this->allowedDirections = currentDensestDirection | !currentDensestDirection;
			this->durationCounter = 0;
		}
	}
	else if (this->allowedDirections == NONE)
	{
		const auto currentDensestDirection = getDensestDirection(this->roads);

		this->allowedDirections = currentDensestDirection | !currentDensestDirection;
		this->durationCounter = 0;
	}
}

PriorityIntersection::PriorityIntersection(const std::string& name, const std::vector<std::shared_ptr<Road>>& roads) : Intersection(
	name)
{
	this->roads = roads;
	this->allowedDirections = NONE;
	this->durationCounter = 0;
}

std::vector<Vehicle> PriorityIntersection::process()
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

	this->durationCounter++;

	return processedVehicles;
}

std::size_t PriorityIntersection::count() const
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

void PriorityIntersection::display(std::ostream& output) const
{
	output << "Intersection \"" << this->name << "\":" << std::endl;
	
	for (const auto& road : this->roads)
		road->display(output);
}
