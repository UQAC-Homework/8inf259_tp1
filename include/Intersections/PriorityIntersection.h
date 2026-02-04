#ifndef INC_8INF259_TP1_PRIORITYINTERSECTION_H
#define INC_8INF259_TP1_PRIORITYINTERSECTION_H
#include <memory>
#include <vector>

#include "Intersection.h"
#include "../Road.h"

#define MINIMAL_DURATION 2
#define MAXIMAL_DURATION 5

/// Intersection that uses road density to prioritize directions
class PriorityIntersection : public Intersection
{
	/// Every road processed by this intersection
	std::vector<std::shared_ptr<Road>> roads;

	/// Directions allowed to cross
	Direction allowedDirections;

	/// Counter of the current duration
	int durationCounter;

	/// Updates the traffic lights based off the next cycle
	void updateCounter();

public:
	explicit PriorityIntersection(const std::string& name, const std::vector<std::shared_ptr<Road>>& roads);

	std::vector<Vehicle> process() override;

	[[nodiscard]] std::size_t count() const override;
};


#endif //INC_8INF259_TP1_PRIORITYINTERSECTION_H