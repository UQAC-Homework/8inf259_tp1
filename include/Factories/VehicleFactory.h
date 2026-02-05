#ifndef INC_8INF259_TP1_VEHICLEFACTORY_H
#define INC_8INF259_TP1_VEHICLEFACTORY_H

#include "../Direction.h"
#include "../Vehicle.h"

class Road;

/// Class responsible to create Vehicle
class VehicleFactory
{
public:
	/// Creates a new vehicle
	Vehicle static create(Direction direction);
};


#endif //INC_8INF259_TP1_VEHICLEFACTORY_H