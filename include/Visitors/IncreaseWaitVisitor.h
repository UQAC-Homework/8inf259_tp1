#ifndef INC_8INF259_TP1_INCREASEWAITVISITO_H
#define INC_8INF259_TP1_INCREASEWAITVISITO_H
#include "Visitor.h"
#include "../Vehicle.h"

/// Visitor that increases the wait time of every vehicle
class IncreaseWaitVisitor : public IVisitor<Vehicle>
{
public:
	void clean() override;
	void visit(const Vehicle& element) override;
	void visit(Vehicle& element) override;
};


#endif //INC_8INF259_TP1_INCREASEWAITVISITO_H