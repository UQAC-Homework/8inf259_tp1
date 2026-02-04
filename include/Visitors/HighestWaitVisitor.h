#ifndef INC_8INF259_TP1_HIGHESTWAITVISITOR_H
#define INC_8INF259_TP1_HIGHESTWAITVISITOR_H

#include "Visitor.h"
#include "../Vehicle.h"

#define LOWEST_WAIT (-1)

/// Visitor that finds the highest wait time of a vehicle
class HighestWaitVisitor : public IVisitor<Vehicle>
{
	int highestWait = LOWEST_WAIT;

public:
	void clean() override;
	void visit(Vehicle& element) override;
	void visit(const Vehicle& element) override;

	/// Returns the highest wait found
	[[nodiscard]] int getHighestWait() const;
};

#endif //INC_8INF259_TP1_HIGHESTWAITVISITOR_H