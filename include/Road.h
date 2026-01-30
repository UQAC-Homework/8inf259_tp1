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
	
	/// Processes a single vehicule
	void process();
	
	/// Accepts a visitor to visit every vehicule
	void accept(IVisitor<Vehicule>& visitor) const;
};

#endif //INC_8INF259_TP1_ROAD_H