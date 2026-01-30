#include "../../include/Visitors/HighestWaitVisitor.h"

void HighestWaitVisitor::clean()
{
	highestWait = LOWEST_WAIT;
}

void HighestWaitVisitor::visitElement(Vehicule& element)
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