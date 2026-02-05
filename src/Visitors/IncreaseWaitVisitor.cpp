#include "../../include/Visitors/IncreaseWaitVisitor.h"

void IncreaseWaitVisitor::clean()
{
}

void IncreaseWaitVisitor::visit(const Vehicle& element)
{
}

void IncreaseWaitVisitor::visit(Vehicle& element)
{
	element.waitTurn();
}
