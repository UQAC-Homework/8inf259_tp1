#ifndef INC_8INF259_TP1_VEHICLE_H
#define INC_8INF259_TP1_VEHICLE_H
#include <iosfwd>

class Vehicle
{
	/// Amount of turns this vehicle has waited at an intersection
	int turnsWaited;

public:
	Vehicle();

	/// Returns the amount of turns this vehicle has waited at an intersection
	[[nodiscard]] int getTurnsWaited() const;

	/// Notifies this vehicle that it will have to wait a turn
	void waitTurn();
	
	/// Displays this vehicle
	void display(std::ostream& output) const;
};

// TODO: std::string id : Identifiant unique du véhicule (ex: "V001").
// TODO: std::string type : Type de véhicule ("Voiture", "Camion", "Moto").
// TODO: std::string destination : Direction de destination ("Nord", "Sud", "Est", "Ouest").

#endif //INC_8INF259_TP1_VEHICLE_H