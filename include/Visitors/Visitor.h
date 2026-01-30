#ifndef INC_8INF259_TP1_IVISITOR_H
#define INC_8INF259_TP1_IVISITOR_H

/// Class that allows to visit every element in a collection
template <typename T>
class IVisitor
{
public:
	virtual ~IVisitor() = default;
	
	/// Cleans this visitor of the collected data
	virtual void clean() = 0;
	
	/// Visits the given element
	virtual void visitElement(T& element) = 0;
};

#endif //INC_8INF259_TP1_IVISITOR_H