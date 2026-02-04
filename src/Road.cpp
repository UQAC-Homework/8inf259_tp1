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

void Road::addVehicle(const Vehicle vehicle)
{
	this->vehicles.enqueue(vehicle);
}

std::size_t Road::count() const
{
	return this->vehicles.size();
}

std::optional<Vehicle> Road::process()
{
	if (this->vehicles.empty())
		return {};

	return this->vehicules.dequeue();
	// TODO: Check if this can be returned as a pointer
	return this->vehicles.dequeue();
}

void Road::accept(IVisitor<Vehicle>& visitor)
{
	vehicles.accept(visitor);
}