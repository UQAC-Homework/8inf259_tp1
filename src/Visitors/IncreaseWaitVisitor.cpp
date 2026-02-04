#include "../../include/Visitors/IncreaseWaitVisitor.h"

void IncreaseWaitVisitor::clean()
{
}

void IncreaseWaitVisitor::visit(const Vehicule& element)
{
}

void IncreaseWaitVisitor::visit(Vehicule& element)
{
	element.waitTurn();
}
