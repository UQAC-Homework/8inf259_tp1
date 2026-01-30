#ifndef INC_8INF259_TP1_INCREASEWAITVISITO_H
#define INC_8INF259_TP1_INCREASEWAITVISITO_H
#include "Visitor.h"
#include "../Vehicule.h"

/// Visitor that increases the wait time of every vehicule
class IncreaseWaitVisitor : public IVisitor<Vehicule>
{
public:
	void clean() override;
	void visit(Vehicule& element) override;
};


#endif //INC_8INF259_TP1_INCREASEWAITVISITO_H