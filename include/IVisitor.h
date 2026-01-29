#ifndef INC_8INF259_TP1_IVISITOR_H
#define INC_8INF259_TP1_IVISITOR_H

/// Class that allows to visit every element in a collection
template <typename T>
class IIVisitor
{
public:
	virtual ~IIVisitor() = default;

	/// Visits the given element
	virtual void visitElement(const T& element) const = 0;
};

#endif //INC_8INF259_TP1_IVISITOR_H