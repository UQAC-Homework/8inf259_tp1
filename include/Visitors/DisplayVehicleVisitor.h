#ifndef INC_8INF259_TP1_DISPLAYVEHICLEVISITOR_H
#define INC_8INF259_TP1_DISPLAYVEHICLEVISITOR_H
#include "Visitor.h"
#include "../Vehicle.h"

/// Visitor that displays every vehicle
class DisplayVehicleVisitor : public IVisitor<Vehicle>
{
	std::ostream* _output = nullptr;
public:
	/// Sets the output for every element
	void setOutput(std::ostream& output);
	void clean() override;
	void visit(const Vehicle& element) override;
	void visit(Vehicle& element) override;
};


#endif //INC_8INF259_TP1_DISPLAYVEHICLEVISITOR_H