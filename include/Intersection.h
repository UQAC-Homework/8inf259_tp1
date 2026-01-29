#ifndef INC_8INF259_TP1_INTERSECTION_H
#define INC_8INF259_TP1_INTERSECTION_H
#include <map>
#include <string>

#include "IntersectionType.h"
#include "Road.h"

/// Class that represents an intersection of roads
class Intersection
{
private:
	std::string name; // TODO: Implement
	IntersectionType type; // TODO: Implement
	std::map<std::string, Road*> roads; // TODO: Implement
	int cycleCounter; // TODO: Implement
	int greenDuration; // TODO: Implement
	int maxGreenDuration; // TODO: Implement
public:
	void processTurn(); // TODO: Implement
	void updateLights(); // TODO: Implement
	void display(); // TODO: Implement
};


#endif //INC_8INF259_TP1_INTERSECTION_H