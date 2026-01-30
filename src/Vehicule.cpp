#include "../include/Vehicule.h"

Vehicule::Vehicule()
{
	this->turnsWaited = 0;
}

int Vehicule::getTurnsWaited() const
{
	return this->turnsWaited;
}

void Vehicule::waitTurn()
{
	this->turnsWaited++;
}