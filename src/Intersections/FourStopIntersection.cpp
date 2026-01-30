#include "../../include/Intersections/FourStopIntersection.h"

#include "../../include/Visitors/HighestWaitVisitor.h"
#include "../../include/Visitors/IncreaseWaitVisitor.h"

/// Gets the road with the highest priority
std::optional<std::shared_ptr<Road>> getHighestPriority(const std::vector<std::shared_ptr<Road>>& roads)
{
	HighestWaitVisitor visitor;
	std::optional<std::shared_ptr<Road>> highestRoad = {};
	int highestPriority = -1;

	for (const auto road : roads)
	{
		visitor.clean();
		road->accept(visitor);

		// Get priority
		const int priority = visitor.getHighestWait();

		if (priority <= highestPriority)
			continue;

		highestRoad = road;
		highestPriority = priority;
	}

	return highestRoad;
}

FourStopIntersection::FourStopIntersection(const std::string& name, const std::vector<std::shared_ptr<Road>>& roads) :
	Intersection(
		name)
{
	this->roads = roads;
}

std::vector<Vehicule> FourStopIntersection::process()
{
	const std::optional<std::shared_ptr<Road>> highPriorityRoad = getHighestPriority(this->roads);
	IncreaseWaitVisitor visitor;
	std::vector<Vehicule> processedVehicules;

	for (const auto road : this->roads)
	{
		if (highPriorityRoad.has_value() && road == highPriorityRoad)
		{
			const auto processedVehicule = highPriorityRoad.value()->process();

			if (processedVehicule.has_value())
				processedVehicules.push_back(processedVehicule.value());
		}

		visitor.clean();
		road->accept(visitor);
	}

	return processedVehicules;
}

std::size_t FourStopIntersection::count() const
{
	size_t count = 0;

	for (const auto road : this->roads)
		count += road->count();

	return count;
}