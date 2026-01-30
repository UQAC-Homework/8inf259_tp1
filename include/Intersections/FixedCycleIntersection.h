#ifndef INC_8INF259_TP1_FIXEDCYCLEINTERSECTION_H
#define INC_8INF259_TP1_FIXEDCYCLEINTERSECTION_H
#include <memory>
#include <vector>

#include "Intersection.h"
#include "../Direction.h"
#include "../Road.h"

#define NORTH_SOUTH_CYCLE 3
#define EAST_WEST_CYCLE 3

/// Intersection that uses a fixed cycle
class FixedCycleIntersection : public Intersection
{
	/// Every road processed by this intersection
	std::vector<std::shared_ptr<Road>> roads;

	/// Directions allowed to cross
	Direction allowedDirections;

	/// Counter of the current cycle
	int cycleCounter = -1;

	/// Updates the traffic lights based off the next cycle
	void updateCounter();

public:
	explicit FixedCycleIntersection(const std::string& name, const std::vector<std::shared_ptr<Road>>& roads);

	std::vector<Vehicule> process() override;

	[[nodiscard]] std::size_t count() const override;
};

#endif //INC_8INF259_TP1_FIXEDCYCLEINTERSECTION_H