#ifndef INC_8INF259_TP1_WAITTURNVISITOR_H
#define INC_8INF259_TP1_WAITTURNVISITOR_H
#include <vector>

#include "Visitor.h"
#include "../Vehicule.h"

/// Visitor that collects all remaining vehicules
class NextVehiculeVisitor : public IVisitor<Vehicule>
{
	std::vector<Vehicule*> remainingVehicules;
public:
	void clean() override;
	void visitElement(Vehicule& element) override;
	
	/// Returns the remaining vehicules
	[[nodiscard]] std::vector<Vehicule*> getRemainingVehicules() const;
};

#endif //INC_8INF259_TP1_WAITTURNVISITOR_H