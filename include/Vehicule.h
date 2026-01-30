#ifndef INC_8INF259_TP1_VEHICULE_H
#define INC_8INF259_TP1_VEHICULE_H

class Vehicule
{
	/// Amount of turns this vehicule has waited at an intersection
	int turnsWaited;
public:
	Vehicule();

	/// Returns the amount of turns this vehicule has waited at an intersection
	[[nodiscard]] int getTurnsWaited() const;
	
	/// Notifies this vehicule that it will have to wait a turn
	void waitTurn();
};

// TODO: std::string id : Identifiant unique du véhicule (ex: "V001").
// TODO: std::string type : Type de véhicule ("Voiture", "Camion", "Moto").
// TODO: std::string destination : Direction de destination ("Nord", "Sud", "Est", "Ouest").
// TODO: Méthode pour afficher les informations du véhicule (display).

#endif //INC_8INF259_TP1_VEHICULE_H