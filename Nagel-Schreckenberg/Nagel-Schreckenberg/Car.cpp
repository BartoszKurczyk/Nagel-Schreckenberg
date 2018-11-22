#include "pch.h"
#include "Car.h"

Car::Car()
{
	car_lenght = 1;
	vmax = 5;
	v = (std::rand() % vmax) + 1;
}

Car::~Car()
{
}
