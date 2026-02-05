#include <algorithm>
#include <fstream>
#include <iostream>

#include "include/RoadSpreader.h"
#include "include/TrafficSystem.h"
#include "include/Factories/VehicleFactory.h"
#include "include/Intersections/FixedCycleIntersection.h"
#include "include/Intersections/FourStopIntersection.h"
#include "include/Intersections/Intersection.h"
#include "include/Intersections/PriorityIntersection.h"

int main()
{
	TrafficSystem system;

	// Create roads
	Road northRoad{"Route Nord", NORTH};
	Road southRoad{"Route Sud", SOUTH};
	Road eastRoad{"Route Est", EAST};
	Road westRoad{"Route Ouest", WEST};

	std::vector<std::shared_ptr<Road>> roads;
	roads.push_back(std::make_shared<Road>(northRoad));
	roads.push_back(std::make_shared<Road>(southRoad));
	roads.push_back(std::make_shared<Road>(eastRoad));
	roads.push_back(std::make_shared<Road>(westRoad));

	// Choose one of the following scenarios:
	// Scenario 1: Spread traffic evenly on all roads
	//spreadEvenly(roads, 120);

	// Scenario 2: Spread traffic evenly on all roads in the given directions
	spreadOnDirections(roads, NORTH | SOUTH, 120);

	// Scenario 3: Unbalanced traffic (50 vehicles N-S, 10 vehicles E-W = 120 total)
	//spreadUnbalanced(roads, 50, 10);
	
	// Scenario 4: Unbalanced traffic (60 vehicles N, 60 vehicles W)
	//spreadUnbalancedOnDirections(roads, 60, 60);

	// Create intersection - choose one type:
	// Type 1: Priority Light (dynamic based on traffic)
	PriorityIntersection intersection{
		"Intersection Principale",
		roads,
		3,
		5
	};

	// Type 2: Fixed Light (alternating cycle)
	/*FixedCycleIntersection intersection{
		"Intersection Principale",
		roads,
		3,
		3
	};*/

	// Type 3: Four-Way Stop (one vehicle at a time)
	/*FourStopIntersection intersection{
		"Intersection Principale",
		roads
	};*/

	system.addIntersection(&intersection);

	// Simulation
	for (int turn = 1; system.hasVehicles(); turn++)
	{
		// Uncomment the following lines to see detailed simulation
		//std::cout << "========== Tour " << turn << " ==========" << std::endl;
		//system.display(std::cout);
		system.process();
		//std::cout << std::endl;
	}

	const auto processedCount = system.getProcessedVehicles();
	const auto totalWaitTime = system.getTotalWaitTime();

	std::cout << "========== Résultats finaux ==========" << std::endl;
	std::cout << "Véhicules traités: " << processedCount << std::endl;
	std::cout << "Temps d'attente total: " << totalWaitTime << " tours" << std::endl;
	std::cout << "Temps d'attente moyen: ";

	if (processedCount > 0)
		std::cout << static_cast<float>(totalWaitTime) / static_cast<float>(processedCount);
	else
		std::cout << 0;
	std::cout << " tours / véhicule" << std::endl;
	
	return 0;
}