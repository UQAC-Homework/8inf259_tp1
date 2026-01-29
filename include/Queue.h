#ifndef INC_8INF259_TP1_QUEUE_H
#define INC_8INF259_TP1_QUEUE_H

#ifndef size_t
#define size_t unsigned int
#endif

/// Collection of objects as a first-in, first-out
template <typename T>
class Queue
{
public:
	/// Adds an object to the end of the collection
	void enqueue(T* item);
	
	/// Removes and returns the object at the beginning of the collection
	[[nodiscard]] T* dequeue();
	
	/// Returns the object at the beginning of the collection
	[[nodiscard]] T* peek() const;
	
	/// Gets the number of elements contained in the collection
	[[nodiscard]] size_t size() const;
	
	/// Determines if the collection is empty
	[[nodiscard]] bool isEmpty() const;
	
	void accept(); // TODO: Implement
};


#endif //INC_8INF259_TP1_QUEUE_H