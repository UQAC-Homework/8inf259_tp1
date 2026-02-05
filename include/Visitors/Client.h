#ifndef INC_8INF259_TP1_CLIENT_H
#define INC_8INF259_TP1_CLIENT_H
#include "Visitor.h"

/// Class that allows a visitor to visit every element in its collection
template <typename T>
class IClient
{
public:
	virtual ~IClient() = default;
	
	/// Accepts a visitor that visits every object in the collection
	virtual void accept(IVisitor<T>& visitor) const = 0;
	
	/// Accepts a visitor that modifies every object in the collection
	virtual void accept(IVisitor<T>& visitor) = 0;
};

#endif //INC_8INF259_TP1_CLIENT_H