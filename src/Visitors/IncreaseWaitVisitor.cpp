#include "../../include/Visitors/IncreaseWaitVisitor.h"

void IncreaseWaitVisitor::clean()
{
}

void IncreaseWaitVisitor::visit(Vehicule& element)
{
	element.waitTurn();
}