#include "../../include/Intersections/PriorityIntersection.h"
#include "../../include/Intersections/Intersection.h"
#include "../../include/Visitors/IncreaseWaitVisitor.h"

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
		// ReSharper disable once CppTooWideScopeInitStatement
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

PriorityIntersection::PriorityIntersection(const std::string& name, const std::vector<Road*>& roads) : Intersection(
	name)
{
	this->roads = roads;
	this->allowedDirections = NONE;
	this->durationCounter = 0;
}

std::vector<Vehicule> PriorityIntersection::process()
{
	this->updateCounter();

	std::vector<Vehicule> processedVehicules;
	IncreaseWaitVisitor visitor;

	for (const auto road : this->roads)
	{
		// ReSharper disable once CppTooWideScopeInitStatement
		const auto direction = road->getDirection();

		if (direction & this->allowedDirections)
		{
			// ReSharper disable once CppTooWideScopeInitStatement
			const auto processedVehicule = road->process();

			if (processedVehicule.has_value())
				processedVehicules.push_back(processedVehicule.value());
		}

		visitor.clean();
		road->accept(visitor);
	}

	this->durationCounter++;

	return processedVehicules;
}

std::size_t PriorityIntersection::count() const
{
	size_t count = 0;

	for (const auto road : this->roads)
		count += road->count();

	return count;
}