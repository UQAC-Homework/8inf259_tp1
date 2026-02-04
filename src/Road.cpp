#include "../include/Road.h"

#include "../include/Visitors/DisplayVehicleVisitor.h"

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

	// TODO: Check if this can be returned as a pointer
	return this->vehicles.dequeue();
}

void Road::accept(IVisitor<Vehicle>& visitor)
{
	vehicles.accept(visitor);
}

void Road::display(std::ostream& output) const
{
	output << "\tRoute \"" << this->name << "\":" << std::endl;

	DisplayVehicleVisitor visitor;
	
	visitor.clean();
	visitor.setOutput(output);
	this->vehicles.accept(visitor);
}
