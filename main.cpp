#include <iostream>

#include "include/TrafficSystem.h"
#include "include/Intersections/Intersection.h"
#include "include/Intersections/PriorityIntersection.h"

void addEqualVehicles(Road& road1, Road& road2, Road& road3, Road& road4, const int count)
{
	for (int i = 0; i < count; i++)
	{
		road1.addVehicule(Vehicule());
		road2.addVehicule(Vehicule());
		road3.addVehicule(Vehicule());
		road4.addVehicule(Vehicule());
	}
}

int main()
{
	TrafficSystem system;
	
	// Create roads
	Road northRoad{"Route Nord", NORTH};
	Road southRoad{"Route Sud", SOUTH};
	Road eastRoad{"Route Est", EAST};
	Road westRoad{"Route Ouest", WEST};
	
	// Choose one of the following scenarios:
	// Scenario 1: Equal traffic on all roads (30 vehicles each = 120 total)
	addEqualVehicles(northRoad, southRoad, eastRoad, westRoad, 30);
	
	// Scenario 2: Empty East-West axis (60 vehicles each on N-S = 120 total)
	// addEmptyAxis(northRoad, southRoad, eastRoad, westRoad, 60);
	
	// Scenario 3: Unbalanced traffic (50 vehicles N-S, 10 vehicles E-W = 120 total)
	// addUnbalancedVehicles(northRoad, southRoad, eastRoad, westRoad, 50, 10);
	
	// Create intersection - choose one type:
	// Type 1: Priority Light (dynamic based on traffic)
	std::vector<Road*> roads;
	roads.push_back(&northRoad);
	roads.push_back(&southRoad);
	roads.push_back(&eastRoad);
	roads.push_back(&westRoad);
	
	PriorityIntersection intersection1{
		"Intersection Principale",
		roads
	};
	
	// Type 2: Fixed Light (alternating cycle)
	/*FixedCycleIntersection intersection1{
		"Intersection Principale",
		roads
	};*/
	
	// Type 3: Four-Way Stop (one vehicle at a time)
	/*FourStopIntersection intersection1{
		"Intersection Principale",
		roads
	};*/
	
	system.addIntersection(&intersection1);
	
	// Simulation
	for (int turn = 1; system.hasVehicles(); turn++)
	{
		// Uncomment the following lines to see detailed simulation
		std::cout << "========== Tour " << turn << " ==========" << std::endl;
		// system.displayState();
		system.process();
		std::cout << std::endl;
	}

	std::cout << "========== Résultats finaux ==========" << std::endl;
	std::cout << "Véhicules traités: " << system.getProcessedVehicles() << std::endl;
	std::cout << "Temps d'attente total: " << system.getTotalWaitTime() << "tours" << std::endl;
	std::cout << "Temps d'attente moyen: " << (system.getProcessedVehicles() > 0 ? (float)system.getTotalWaitTime() / system.getProcessedVehicles() : 0) << " tours/véhicule" << std::endl;

	return 0;
}
