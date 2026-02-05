#include "../include/Queue.h"

#include <stdexcept>

template <typename T>
void Queue<T>::enqueue(T element)
{
	Node node(element);
	
	const auto nodeRef = std::make_shared<Node>(node);
	
	if (this->empty())
	{
		this->tail = nodeRef;
		this->head = this->tail;
		return;
	}
	
	node.prev = this->tail;
	this->tail->next = nodeRef;
	this->tail = nodeRef;
}

template <typename T>
T Queue<T>::dequeue()
{
	if (this->empty())
		throw std::logic_error("Tried to dequeue while empty.");

	const auto node = this->head;
	this->head = this->head->next;

	return node->element;
}

template <typename T>
T Queue<T>::peek() const
{
	if (this->empty())
		throw std::logic_error("Tried to peek while empty.");

	return this->head->element;
}

template <typename T>
std::size_t Queue<T>::size() const
{
	int size = 0;
	
	auto current = this->head;
	
	while (current != nullptr)
	{
		size++;
		current = current->next;
	}
	
	return size;
}

template <typename T>
bool Queue<T>::empty() const
{
	const auto size = this->size();

	return size == 0;
}

template <typename T>
void Queue<T>::accept(IVisitor<T>& visitor) const
{
	auto current = this->head;
	
	while (current != nullptr)
	{
		visitor.visit(current->element);
		current = current->next;
	}
}

template <typename T>
void Queue<T>::accept(IVisitor<T>& visitor)
{
	auto current = this->head;
	
	while (current != nullptr)
	{
		visitor.visit(current->element);
		current = current->next;
	}
}
