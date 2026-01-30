#ifndef INC_8INF259_TP1_ROAD_H
#define INC_8INF259_TP1_ROAD_H
#include "Direction.h"
#include "Queue.h"
#include "Vehicule.h"

class Road
{
	Queue<Vehicule> vehicules;
	Direction direction;
public:
	explicit Road(Direction direction);
	
	/// Gets the direction of this road
	[[nodiscard]] Direction getDirection() const;
	
	/// Adds a new vehicule to this road
	void addVehicule(Vehicule vehicle);
	
	/// Gets the amount of vehicules on this road
	[[nodiscard]] std::size_t count() const;
	
	/// Processes a single vehicule
	void process();
	
	/// Accepts a visitor to visit every vehicule
	void accept(IVisitor<Vehicule>& visitor);
};

#endif //INC_8INF259_TP1_ROAD_H