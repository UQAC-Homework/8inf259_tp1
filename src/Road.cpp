#include "../include/Road.h"

#include "../include/Visitors/NextVehiculeVisitor.h"

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

	const auto processedVehicule = this->vehicules.dequeue();

	NextVehiculeVisitor visitor;
	visitor.clean();
	this->accept(visitor);

	// ReSharper disable once CppTooWideScopeInitStatement
	const auto remainingVehicules = visitor.getRemainingVehicules();

	for (const auto vehicule : remainingVehicules)
		vehicule->waitTurn();
	
	return processedVehicule;
}

void Road::accept(IVisitor<Vehicule>& visitor)
{
	vehicules.accept(visitor);
}
