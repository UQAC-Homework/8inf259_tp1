#ifndef INC_8INF259_TP1_ROAD_H
#define INC_8INF259_TP1_ROAD_H
#include <optional>
#include <string>

#include "Direction.h"
#include "Queue.h"
#include "Vehicle.h"

class Road
{
	std::string name;
	Queue<Vehicle> vehicles;
	Direction direction;

public:
	explicit Road(const std::string& name, Direction direction);

	/// Gets the direction of this road
	[[nodiscard]] Direction getDirection() const;

	/// Adds a new vehicle to this road
	void addVehicle(Vehicle vehicle);

	/// Gets the amount of vehicles on this road
	[[nodiscard]] std::size_t count() const;

	/// Processes a single vehicle
	std::optional<Vehicle> process();

	/// Accepts a visitor to visit every vehicule
	void accept(IVisitor<Vehicule>& visitor);
	/// Accepts a visitor to visit every vehicle
	void accept(IVisitor<Vehicle>& visitor);
};

// TODO: Vehicle* getNextVehicle() : Retourne et retire le premier véhicule.
// TODO: void display() : Affiche l'état de la route.

#endif //INC_8INF259_TP1_ROAD_H