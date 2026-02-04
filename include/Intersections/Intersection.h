#ifndef INC_8INF259_TP1_INTERSECTION_H
#define INC_8INF259_TP1_INTERSECTION_H

#include <string>

#include "../Vehicle.h"

/// Class that represents a junction of roads
class Intersection
{
protected:
	std::string name;

public:
	explicit Intersection(const std::string& name)
	{
		this->name = name;
	}

	virtual ~Intersection() = default;

	/// Processes a turn of traffic
	virtual std::vector<Vehicle> process() = 0;

	/// Gets the amount of vehicles on this intersection
	[[nodiscard]] virtual std::size_t count() const = 0;
	
	/// Displays this intersection
	virtual void display(std::ostream& output) const = 0;
};

#endif //INC_8INF259_TP1_INTERSECTION_H