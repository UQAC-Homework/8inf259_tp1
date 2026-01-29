#include "../include/Vehicule.h"

Vehicule::Vehicule()
{
	type = CAR;
	waitTime = 0;
}

void Vehicule::increaseWaitTime()
{
	waitTime++;
}
