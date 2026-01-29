#ifndef INC_8INF259_TP1_ROAD_H
#define INC_8INF259_TP1_ROAD_H
#include "Queue.h"
#include "Vehicule.h"

/// Class representing a collection of vehicules
class Road
{
private:
	std::string name; // TODO: Implement
	std::string direction; // TODO: Implement
	
	Queue<Vehicule> vehicules;
public:
	Road();
	
	/// Adds a vehicule on this road
	void addVehicule(const Vehicule& vehicule);
	
	/// Removes and returns the first vehicule
	[[nodiscard]] Vehicule* getNextVehicule();
	
	/// Gets the number of vehicules on this road
	[[nodiscard]] std::size_t size() const;
	
	void increaseAllWaitTimes(); // TODO: Implement
	
	void display(); // TODO: Implement
};

#endif //INC_8INF259_TP1_ROAD_H