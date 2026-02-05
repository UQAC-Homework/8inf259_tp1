#include "../../include/Visitors/HighestWaitVisitor.h"

void HighestWaitVisitor::clean()
{
	highestWait = -1;
}

void HighestWaitVisitor::visit(Vehicle& element)
{
}

void HighestWaitVisitor::visit(const Vehicle& element)
{
	const auto currentWait = element.getTurnsWaited();

	if (currentWait <= highestWait)
		return;

	highestWait = currentWait;
}

int HighestWaitVisitor::getHighestWait() const
{
	return highestWait;
}
