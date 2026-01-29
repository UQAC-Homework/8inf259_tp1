#include "../include/Queue.h"

#include <stdexcept>

template <typename T>
void Queue<T>::enqueue(T* item)
{
	throw std::logic_error("Not implemented");
}

template <typename T>
T* Queue<T>::dequeue()
{
	throw std::logic_error("Not implemented");
}

template <typename T>
T* Queue<T>::peek() const
{
	throw std::logic_error("Not implemented");
}

template <typename T>
unsigned int Queue<T>::size() const
{
	throw std::logic_error("Not implemented");
}

template <typename T>
bool Queue<T>::isEmpty() const
{
	throw std::logic_error("Not implemented");
}
