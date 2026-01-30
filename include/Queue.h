#ifndef INC_8INF259_TP1_QUEUE_H
#define INC_8INF259_TP1_QUEUE_H

#include <list>

#include "Vehicule.h"
#include "Visitors/Visitor.h"

/// Collection of objects as a first-in, first-out
template <typename T>
class Queue
{
private:
	/// Underlying collection of objects
	std::list<T> elements;

public:
	/// Adds an object to the end of the collection
	void enqueue(T element);

	/// Removes and returns the object at the beginning of the collection
	[[nodiscard]] T dequeue();

	/// Returns the object at the beginning of the collection
	[[nodiscard]] T peek() const;

	/// Gets the number of elements contained in the collection
	[[nodiscard]] std::size_t size() const;

	/// Determines if the collection is empty
	[[nodiscard]] bool empty() const;

	/// Accepts a visitor to visit every object in the collection
	void accept(IVisitor<T>& visitor);
};

template class Queue<Vehicule>;

#endif //INC_8INF259_TP1_QUEUE_H