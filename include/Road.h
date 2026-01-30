#ifndef INC_8INF259_TP1_ROAD_H
#define INC_8INF259_TP1_ROAD_H
#include <optional>
#include <string>

#include "Direction.h"
#include "Queue.h"
#include "Vehicule.h"

class Road
{
	std::string name;
	Queue<Vehicule> vehicules;
	Direction direction;

public:
	explicit Road(const std::string& name, Direction direction);

	/// Gets the direction of this road
	[[nodiscard]] Direction getDirection() const;

	/// Adds a new vehicule to this road
	void addVehicule(Vehicule vehicle);

	/// Gets the amount of vehicules on this road
	[[nodiscard]] std::size_t count() const;

	/// Processes a single vehicule
	std::optional<Vehicule> process();

	/// Accepts a visitor to visit every vehicule
	void accept(IVisitor<Vehicule>& visitor);
};

// TODO: Vehicle* getNextVehicle() : Retourne et retire le premier véhicule.
// TODO: void display() : Affiche l'état de la route.

#endif //INC_8INF259_TP1_ROAD_H