#include "pch.h"
#include "Car.h"

Car::Car()
{
	car_lenght = 1;
	vmax = 5;
	v = (std::rand() % vmax) + 1;
	notToIncreaseSpeed = 0;
}

Car::~Car()
{
}

void Car::setTrueNotToIncreaseSpeed()
{
	notToIncreaseSpeed = 1;//nie mo¿na zwiêkszyæ prêdkoœci
}

void Car::setFalseNotToIncreaseSpeed()
{
	notToIncreaseSpeed = 0;//Mo¿na zwiêkszyæ prêdkoœæ
}

bool Car::getNotToIncreaseSpeed()
{
	return notToIncreaseSpeed;
}
