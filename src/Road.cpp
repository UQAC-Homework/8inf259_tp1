#include "../include/Road.h"

Road::Road(const std::string& name, const Direction direction)
{
	this->name = name;
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

std::optional<Vehicule> Road::process()
{
	if (this->vehicules.empty())
		return {};

	return this->vehicules.dequeue();
}

void Road::accept(IVisitor<Vehicule>& visitor)
{
	vehicules.accept(visitor);
}