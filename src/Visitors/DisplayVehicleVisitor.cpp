#include "../../include/Visitors/DisplayVehicleVisitor.h"

void DisplayVehicleVisitor::setOutput(std::ostream& output)
{
	this->_output = &output;
}

void DisplayVehicleVisitor::clean()
{
	this->_output = INVALID_OUTPUT;
}

void DisplayVehicleVisitor::visit(const Vehicle& element)
{
	if (this->_output == INVALID_OUTPUT)
		return;
	
	element.display(*this->_output);
}

void DisplayVehicleVisitor::visit(Vehicle& element)
{
}
