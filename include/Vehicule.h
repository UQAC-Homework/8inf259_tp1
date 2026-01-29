#ifndef INC_8INF259_TP1_CAR_H
#define INC_8INF259_TP1_CAR_H
#include <string>

/// All possible types of a vehicule
enum VehiculeType
{
	CAR,
	TRUCK,
	MOTORCYCLE,
};

class Vehicule
{
	std::string id; // TODO: Implement
	std::string destination; // TODO: Implement

	/// Type of this vehicule
	VehiculeType type;
	
	/// Amount of turns that this vehicule has been waiting
	unsigned int waitTime;
public:
	Vehicule();
	
	/// Increases the wait time of this vehicule by 1
	void increaseWaitTime();

	void displayInformation(); // TODO: Implement
};


#endif //INC_8INF259_TP1_CAR_H