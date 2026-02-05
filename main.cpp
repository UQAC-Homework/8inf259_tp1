#include <algorithm>
#include <fstream>
#include <iostream>

#include "include/TrafficSystem.h"
#include "include/Factories/VehicleFactory.h"
#include "include/Intersections/FixedCycleIntersection.h"
#include "include/Intersections/FourStopIntersection.h"
#include "include/Intersections/Intersection.h"
#include "include/Intersections/PriorityIntersection.h"

void spreadEvenly(const std::vector<std::shared_ptr<Road>>& roads, const size_t totalCount)
{
	const size_t countPerRoad = totalCount / roads.size();

	for (const auto& road : roads)
	{
		for (size_t i = 0; i < countPerRoad; i++)
			road->addVehicle(VehicleFactory::create(road->getDirection()));
	}

	size_t remaining = totalCount - countPerRoad * roads.size();

	for (const auto& road : roads)
	{
		if (remaining == 0)
			break;

		road->addVehicle(VehicleFactory::create(road->getDirection()));
		remaining--;
	}
}

void spreadOnDirections(const std::vector<std::shared_ptr<Road>>& roads, const Direction directions, const size_t totalCount)
{
	size_t affectedRoadCount = 0;

	for (const auto& road : roads)
	{
		const auto direction = road->getDirection();

		if (direction & directions)
			affectedRoadCount++;
	}

	const size_t countPerRoad = totalCount / affectedRoadCount;

	for (const auto& road : roads)
	{
		const auto direction = road->getDirection();

		if (direction & directions)
		{
			for (size_t i = 0; i < countPerRoad; i++)
				road->addVehicle(VehicleFactory::create(road->getDirection()));
		}
	}
}

void spreadUnbalanced(const std::vector<std::shared_ptr<Road>>& roads, const size_t northSouthCount, const size_t eastWestCount)
{
	for (int i = 0; i < northSouthCount; i++)
	{
		for (const auto& road : roads)
		{
			const auto direction = road->getDirection();
			
			if (direction & (NORTH | SOUTH))
				road->addVehicle(VehicleFactory::create(road->getDirection()));
		}
	}
	
	for (int i = 0; i < eastWestCount; i++)
	{
		for (const auto& road : roads)
		{
			const auto direction = road->getDirection();
			
			if (direction & (EAST | WEST))
				road->addVehicle(VehicleFactory::create(road->getDirection()));
		}
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

	std::vector<std::shared_ptr<Road>> roads;
	roads.push_back(std::make_shared<Road>(northRoad));
	roads.push_back(std::make_shared<Road>(southRoad));
	roads.push_back(std::make_shared<Road>(eastRoad));
	roads.push_back(std::make_shared<Road>(westRoad));

	// Choose one of the following scenarios:
	// Scenario 1: Spread traffic evenly on all roads
	spreadEvenly(roads, 120);

	// Scenario 2: Spread traffic evenly on all roads in the given directions
	//spreadOnDirections(roads, NORTH | SOUTH, 120);

	// Scenario 3: Unbalanced traffic (50 vehicles N-S, 10 vehicles E-W = 120 total)
	//spreadUnbalanced(roads, 50, 10);

	// Create intersection - choose one type:
	// Type 1: Priority Light (dynamic based on traffic)
	PriorityIntersection intersection{
		"Intersection Principale",
		roads,
		2,
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