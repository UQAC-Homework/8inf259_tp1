#ifndef INC_8INF259_TP1_PRIORITYINTERSECTION_H
#define INC_8INF259_TP1_PRIORITYINTERSECTION_H
#include <memory>
#include <vector>

#include "Intersection.h"
#include "../Road.h"

/// Intersection that uses road density to prioritize directions
class PriorityIntersection : public Intersection
{
	/// Every road processed by this intersection
	std::vector<std::shared_ptr<Road>> roads;

	/// Directions allowed to cross
	Direction allowedDirections;

	/// Counter of the current duration
	int durationCounter;
	
	/// Minimal duration allowed
	size_t minimalDuration;
	
	/// Maximal duration allowed
	size_t maximalDuration;

	/// Updates the traffic lights based off the next cycle
	void updateCounter();

public:
	explicit PriorityIntersection(
		const std::string& name,
		const std::vector<std::shared_ptr<Road>>& roads,
		size_t minimalDuration,
		size_t maximalDuration
	);

	std::vector<Vehicle> process() override;

	[[nodiscard]] std::size_t count() const override;
	
	void display(std::ostream& output) const override;
};


#endif //INC_8INF259_TP1_PRIORITYINTERSECTION_H