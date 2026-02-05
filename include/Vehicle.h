#ifndef INC_8INF259_TP1_VEHICLE_H
#define INC_8INF259_TP1_VEHICLE_H
#include <ostream>

#include "Direction.h"

class Vehicle
{
	/// Identifier of this vehicle
	std::string id;
	
	/// Type of this vehicle
	std::string type;
	
	/// Direction of this vehicle
	Direction direction;

	/// Amount of turns this vehicle has waited at an intersection
	int turnsWaited;

public:
	Vehicle(const std::string& type, Direction direction);

	/// Returns the amount of turns this vehicle has waited at an intersection
	[[nodiscard]] int getTurnsWaited() const;

	/// Notifies this vehicle that it will have to wait a turn
	void waitTurn();
	
	/// Displays this vehicle
	void display(std::ostream& output) const;
};

#endif //INC_8INF259_TP1_VEHICLE_H