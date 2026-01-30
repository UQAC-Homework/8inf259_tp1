#ifndef INC_8INF259_TP1_FOURSTOPINTERSECTION_H
#define INC_8INF259_TP1_FOURSTOPINTERSECTION_H
#include <vector>

#include "Intersection.h"
#include "../Road.h"

/// Intersection that uses a 4-ways stop 
class FourStopIntersection : public Intersection
{
	/// Every road processed by this intersection
	std::vector<Road*> roads;
public:
	explicit FourStopIntersection(const std::vector<Road*>& roads) : Intersection()
	{
		this->roads = roads;
	}

	void process() override;
};

#endif //INC_8INF259_TP1_FOURSTOPINTERSECTION_H