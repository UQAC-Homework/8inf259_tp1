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
	explicit FourStopIntersection(const std::string& name, const std::vector<Road*>& roads);

	std::vector<Vehicule> process() override;

	[[nodiscard]] std::size_t count() const override;
};

#endif //INC_8INF259_TP1_FOURSTOPINTERSECTION_H