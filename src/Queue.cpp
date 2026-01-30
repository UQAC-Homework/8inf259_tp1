#include "../include/Queue.h"

#include <stdexcept>

template <typename T>
Queue<T>::Queue()
{
	elements = std::list<T>();
}

template <typename T>
Queue<T>::~Queue() = default;

template <typename T>
void Queue<T>::enqueue(T element)
{
	elements.push_back(element);
}

template <typename T>
T Queue<T>::dequeue()
{
	if (isEmpty())
		throw std::logic_error("Tried to dequeue while empty.");
	
	const auto element = elements.front();
	elements.pop_front();
	
	return element;
}

template <typename T>
T Queue<T>::peek() const
{
	if (isEmpty())
		throw std::logic_error("Tried to peek while empty.");
	
	const auto element = elements.front();
	
	return element;
}

template <typename T>
std::size_t Queue<T>::size() const
{
	return elements.size();
}

template <typename T>
bool Queue<T>::isEmpty() const
{
	const auto size = this->size();
	
	return size == 0;
}

template <typename T>
void Queue<T>::accept(IVisitor<T>& visitor)
{
	for (auto& element : elements)
		visitor.visitElement(element);
}
