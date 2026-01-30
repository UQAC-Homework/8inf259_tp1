#ifndef INC_8INF259_TP1_FOURSTOPINTERSECTION_H
#define INC_8INF259_TP1_FOURSTOPINTERSECTION_H
#include <vector>

#include "Intersection.h"
#include "../Road.h"
#include "../Visitors/HighestWaitVisitor.h"

/// Intersection that uses a 4-ways stop 
class FourStopIntersection : public Intersection
{
	/// Every road processed by this intersection
	std::vector<Road*> roads;
	
	/// Gets the road with the highest priority
	[[nodiscard]] Road* getHighestPriority() const
	{
		HighestWaitVisitor visitor;
		Road* highestRoad = nullptr;
		int highestPriority = -1;
		
		for (Road* road : roads)
		{
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
public:
	explicit FourStopIntersection(const std::vector<Road*>& roads) : Intersection()
	{
		this->roads = roads;
	}

	void process() override
	{
		Road* highPriorityRoad = this->getHighestPriority();
		
		if (highPriorityRoad == nullptr)
			return;

		highPriorityRoad->process();
	}
};

#endif //INC_8INF259_TP1_FOURSTOPINTERSECTION_H