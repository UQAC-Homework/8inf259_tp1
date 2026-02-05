#include "../include/Vehicle.h"

#include "../include/uuid.h"

Vehicle::Vehicle(const std::string& type, const Direction direction)
{
	this->id = uuid::generate_uuid_v4();
	this->type = type;
	this->direction = direction;
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
	std::string directionStr;
	
	if (this->direction == NORTH)
		directionStr = "N";
	else if (this->direction == SOUTH)
		directionStr = "S";
	else if (this->direction == EAST)
		directionStr = "E";
	else if (this->direction == WEST)
		directionStr = "W";

	output << "\t\tVéhicule \"" << this->id << "\" (Type: " << this->type << "; Direction: " << directionStr <<"; Attente: " << this->getTurnsWaited() << " tours)" << std::endl;
}
