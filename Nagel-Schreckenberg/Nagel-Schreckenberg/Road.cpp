#include "pch.h"
#include "Road.h"

Road::Road()
{
	car = NULL;
}

Road::~Road()
{
	if (car != NULL)
	{
		delete car;
	}
}


void Road::AddCar(Car * newCar)
{
	car = newCar;
	car = new Car;
}

bool Road::CheckCar()
{
	if (car == NULL)
	{
		return 0;
	}
	else return 1;
}

int Road::GetSpeed()
{
	return car->v;
}

void Road::DeleteCar()
{
	car = NULL;
}

void Road::ReplaceCar(Car * replacedCar)
{
	car = replacedCar;
}

Car * Road::GetCar()
{
	return car;
}

void Road::CarSetToNULL()
{
	car = NULL;
}

void Road::setSpeed(int speed)
{
	car->v = speed;
}

void Road::increaseSpeed()
{
	if (car->v < car->vmax)
	{
		car->v++;
	}
}

void Road::decreaseSpeed()
{
	if (car->v >1)
	{
		car->v--;
	}
}
