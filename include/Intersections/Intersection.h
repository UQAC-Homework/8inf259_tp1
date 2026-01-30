#ifndef INC_8INF259_TP1_INTERSECTION_H
#define INC_8INF259_TP1_INTERSECTION_H

/// Class that represents a junction of roads
class Intersection
{
public:
	virtual ~Intersection() = default;

	/// Processes a turn of traffic
	virtual void process() = 0;
};

#endif //INC_8INF259_TP1_INTERSECTION_H