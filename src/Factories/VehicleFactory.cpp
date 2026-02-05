#include "../../include/Factories/VehicleFactory.h"

Vehicle VehicleFactory::create(const Direction direction)
{
	Vehicle vehicle("Car", direction);
	
	return vehicle;
}
