#include "../include/Vehicle.h"

#include "../include/uuid.h"

Vehicle::Vehicle()
{
	this->id = uuid::generate_uuid_v4();
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
	output << "\t\tVéhicule \"" << this->id << "\" (Type: type; Direction: direction; Attente: " << this->getTurnsWaited() << " tours)" << std::endl;
}
