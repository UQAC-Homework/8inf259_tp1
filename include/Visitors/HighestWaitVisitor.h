#ifndef INC_8INF259_TP1_HIGHESTWAITVISITOR_H
#define INC_8INF259_TP1_HIGHESTWAITVISITOR_H

#include "Visitor.h"
#include "../Vehicule.h"

#define LOWEST_WAIT (-1)

/// Visitor that collects the vehicule with the highest wait time
class HighestWaitVisitor : public IVisitor<Vehicule>
{
	int highestWait = LOWEST_WAIT;
public:
	void clean() override;
	void visitElement(Vehicule& element) override;
	
	/// Returns the highest wait collected
	[[nodiscard]] int getHighestWait() const;
};

#endif //INC_8INF259_TP1_HIGHESTWAITVISITOR_H