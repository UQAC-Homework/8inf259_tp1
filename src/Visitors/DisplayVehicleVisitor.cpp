#include "../../include/Visitors/DisplayVehicleVisitor.h"

void DisplayVehicleVisitor::setOutput(std::ostream& output)
{
	this->_output = &output;
}

void DisplayVehicleVisitor::clean()
{
	this->_output = nullptr;
}

void DisplayVehicleVisitor::visit(const Vehicle& element)
{
	if (this->_output == nullptr)
		return;
	
	element.display(*this->_output);
}

void DisplayVehicleVisitor::visit(Vehicle& element)
{
}
