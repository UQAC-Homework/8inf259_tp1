#include "../include/Vehicle.h"

Vehicle::Vehicle()
{
	this->turnsWaited = 0;
}

int Vehicle::getTurnsWaited() const
{
	return this->turnsWaited;
}

void Vehicle::waitTurn()
{
	this->turnsWaited++;
}

void Vehicle::display(std::ostream& output) const
{
	output << "\t\tVéhicule \"id\" (Type: type; Direction: direction; Attente: " << this->getTurnsWaited() << " tours)" << std::endl;
}
