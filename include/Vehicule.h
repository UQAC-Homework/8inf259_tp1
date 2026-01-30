#ifndef INC_8INF259_TP1_VEHICULE_H
#define INC_8INF259_TP1_VEHICULE_H
#include <string>

class Vehicule
{
	/// Amount of turns this vehicule has waited at an intersection
	int turnsWaited;
	
	//std::string id;
	//std::string direction;
	//std::string type;
public:
	Vehicule();

	/// Returns the amount of turns this vehicule has waited at an intersection
	[[nodiscard]] int getTurnsWaited() const;
	
	/// Notifies this vehicule that it will have to wait a turn
	void waitTurn();
	
	// void display() const;
};

#endif //INC_8INF259_TP1_VEHICULE_H