#include "../../include/Visitors/IncreaseWaitVisitor.h"

void IncreaseWaitVisitor::clean()
{
}

void IncreaseWaitVisitor::visitElement(Vehicule& element)
{
	element.waitTurn();
}