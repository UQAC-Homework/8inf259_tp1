#include "../../include/Visitors/NextVehiculeVisitor.h"

void NextVehiculeVisitor::clean()
{
	remainingVehicules.clear();
}

void NextVehiculeVisitor::visitElement(Vehicule& element)
{
	remainingVehicules.push_back(&element);
}

std::vector<Vehicule*> NextVehiculeVisitor::getRemainingVehicules() const
{
	return remainingVehicules;
}
