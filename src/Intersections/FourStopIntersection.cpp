#include "../../include/Intersections/FourStopIntersection.h"

#include "../../include/Visitors/HighestWaitVisitor.h"

/// Gets the road with the highest priority
Road* getHighestPriority(const std::vector<Road*>& roads)
{
	HighestWaitVisitor visitor;
	Road* highestRoad = nullptr;
	int highestPriority = -1;
		
	for (Road* road : roads)
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

void FourStopIntersection::process()
{
	Road* highPriorityRoad = getHighestPriority(this->roads);
		
	if (highPriorityRoad == nullptr)
		return;

	highPriorityRoad->process();
}
