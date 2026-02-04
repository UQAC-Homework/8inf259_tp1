#ifndef INC_8INF259_TP1_TRAFFICSYSTEM_H
#define INC_8INF259_TP1_TRAFFICSYSTEM_H
#include <vector>

#include "Intersections/Intersection.h"

/// Class that orchestres every aspect of a traffic system
class TrafficSystem
{
	std::vector<Intersection*> intersections;
	std::vector<Vehicle> processedVehicles;

public:
	/// Adds an intersection to the system
	void addIntersection(Intersection* intersection);

	/// Processes every object in the system
	void process();

	/// Determines if the system has vehicles remaining
	[[nodiscard]] bool hasVehicles() const;

	/// Returns the number of processed vehicles
	[[nodiscard]] size_t getProcessedVehicles() const;

	/// Returns the total number of waited turns
	[[nodiscard]] size_t getTotalWaitTime() const;
	
	/// Displays this system
	void display(std::ostream& output) const;
};

#endif //INC_8INF259_TP1_TRAFFICSYSTEM_H