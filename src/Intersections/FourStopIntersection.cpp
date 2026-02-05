#include "../../include/Intersections/FourStopIntersection.h"

#include <numeric>

#include "../../include/Visitors/HighestWaitVisitor.h"
#include "../../include/Visitors/IncreaseWaitVisitor.h"

/// Gets the road with the highest priority
std::optional<std::shared_ptr<Road>> getHighestPriority(const std::vector<std::shared_ptr<Road>>& roads)
{
	HighestWaitVisitor visitor;
	std::optional<std::shared_ptr<Road>> highestRoad = {};
	int highestPriority = -1;

	for (const auto& road : roads)
	{
		visitor.clean();
		const Road& r = *road;
		r.accept(visitor);

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

std::vector<Vehicle> FourStopIntersection::process()
{
	const std::optional<std::shared_ptr<Road>> highPriorityRoad = getHighestPriority(this->roads);
	IncreaseWaitVisitor visitor;
	std::vector<Vehicle> processedVehicles;

	for (const auto& road : this->roads)
	{
		if (highPriorityRoad.has_value() && road == highPriorityRoad)
		{
			const auto processedVehicle = highPriorityRoad.value()->process();

			if (processedVehicle.has_value())
				processedVehicles.push_back(processedVehicle.value());
		}

		visitor.clean();
		road->accept(visitor);
	}

	return processedVehicles;
}

std::size_t FourStopIntersection::count() const
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

void FourStopIntersection::display(std::ostream& output) const
{
	output << "Intersection \"" << this->name << "\":" << std::endl;
	
	for (const auto& road : this->roads)
		road->display(output);
}
