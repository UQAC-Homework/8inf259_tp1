#ifndef INC_8INF259_TP1_FIXEDCYCLEINTERSECTION_H
#define INC_8INF259_TP1_FIXEDCYCLEINTERSECTION_H
#include <memory>
#include <vector>

#include "Intersection.h"
#include "../Direction.h"
#include "../Road.h"

/// Intersection that uses a fixed cycle
class FixedCycleIntersection : public Intersection
{
	/// Every road processed by this intersection
	std::vector<std::shared_ptr<Road>> roads;

	/// Directions allowed to cross
	Direction allowedDirections;

	/// Counter of the current cycle
	int cycleCounter = -1;
	
	/// Amount of cycle allowed for north and south
	size_t northSouthCycle;
	
	/// Amount of cycle allowed for east and west
	size_t eastWestCycle;

	/// Updates the traffic lights based off the next cycle
	void updateCounter();

public:
	explicit FixedCycleIntersection(const std::string& name,
		const std::vector<std::shared_ptr<Road>>& roads,
		size_t northSouthCycle,
		size_t eastWestCycle
	);
	
	std::vector<Vehicle> process() override;

	[[nodiscard]] std::size_t count() const override;
	
	void display(std::ostream& output) const override;
};

#endif //INC_8INF259_TP1_FIXEDCYCLEINTERSECTION_H