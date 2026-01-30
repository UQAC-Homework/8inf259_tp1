#ifndef INC_8INF259_TP1_PRIORITYINTERSECTION_H
#define INC_8INF259_TP1_PRIORITYINTERSECTION_H
#include <vector>

#include "Intersection.h"
#include "../Road.h"

#define MINIMAL_DURATION 2
#define MAXIMAL_DURATION 5

/// Intersection that uses road density to prioritize directions
class PriorityIntersection : public Intersection
{
	/// Every road processed by this intersection
	std::vector<Road*> roads;
	
	/// Directions allowed to cross
	Direction allowedDirections;
	
	/// Counter of the current duration
	int durationCounter;
public:
	explicit PriorityIntersection(const std::string& name, const std::vector<Road*>& roads);

	void process() override;
	
	[[nodiscard]] std::size_t count() const override;
};


#endif //INC_8INF259_TP1_PRIORITYINTERSECTION_H