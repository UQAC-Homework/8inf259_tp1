#include "../include/Road.h"

#include <iostream>
#include <ostream>

Road::Road(const Direction direction)
{
	this->direction = direction;

	vehicules.enqueue(Vehicule());
	vehicules.enqueue(Vehicule());
	vehicules.enqueue(Vehicule());
}

Direction Road::getDirection() const
{
	return this->direction;
}

void Road::process()
{
	std::cout << "Road processing: ";

	switch (direction)
	{
	case NORTH:
		std::cout << "NORTH";
		break;
	case SOUTH:
		std::cout << "SOUTH";
		break;
	case EAST:
		std::cout << "EAST";
		break;
	case WEST:
		std::cout << "WEST";
		break;
	default: ;
	}

	std::cout << std::endl;
}

void Road::accept(IVisitor<Vehicule>& visitor) const
{
	vehicules.accept(visitor);
}
