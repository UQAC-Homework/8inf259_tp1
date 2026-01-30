#ifndef INC_8INF259_TP1_INTERSECTION_H
#define INC_8INF259_TP1_INTERSECTION_H

#include <string>

#include "../Vehicule.h"

/// Class that represents a junction of roads
class Intersection
{
	std::string name;
public:
	explicit Intersection(const std::string& name)
	{
		this->name = name;
	};
	virtual ~Intersection() = default;

	/// Processes a turn of traffic
	virtual std::vector<Vehicule> process() = 0;
	
	/// Gets the amount of vehicules on this intersection
	[[nodiscard]] virtual std::size_t count() const = 0;
};

#endif //INC_8INF259_TP1_INTERSECTION_H