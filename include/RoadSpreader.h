#ifndef INC_8INF259_TP1_ROADSPREADER_H
#define INC_8INF259_TP1_ROADSPREADER_H
#include <memory>

#include "Road.h"
#include "Factories/VehicleFactory.h"

inline void spreadEvenly(const std::vector<std::shared_ptr<Road>>& roads, const size_t totalCount)
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

inline void spreadOnDirections(const std::vector<std::shared_ptr<Road>>& roads, const Direction directions, const size_t totalCount)
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

inline void spreadUnbalanced(const std::vector<std::shared_ptr<Road>>& roads, const size_t northSouthCount, const size_t eastWestCount)
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

inline void spreadUnbalancedOnDirections(const std::vector<std::shared_ptr<Road>>& roads, const size_t northCount, const size_t westCount)
{
	for (int i = 0; i < northCount; i++)
	{
		for (const auto& road : roads)
		{
			const auto direction = road->getDirection();
			
			if (direction & NORTH)
				road->addVehicle(VehicleFactory::create(road->getDirection()));
		}
	}
	
	for (int i = 0; i < westCount; i++)
	{
		for (const auto& road : roads)
		{
			const auto direction = road->getDirection();
			
			if (direction & WEST)
				road->addVehicle(VehicleFactory::create(road->getDirection()));
		}
	}
}

#endif //INC_8INF259_TP1_ROADSPREADER_H