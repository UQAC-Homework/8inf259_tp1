#include "../include/Road.h"

#include <iostream>
#include <ostream>

Road::Road(const Direction direction)
{
	this->direction = direction;
}

Direction Road::getDirection() const
{
	return this->direction;
}

void Road::addVehicule(const Vehicule vehicle)
{
	this->vehicules.enqueue(vehicle);
}

std::size_t Road::count() const
{
	return this->vehicules.size();
}

void Road::process()
{
	auto a = this->vehicules.dequeue();
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

void Road::accept(IVisitor<Vehicule>& visitor)
{
	vehicules.accept(visitor);
}
