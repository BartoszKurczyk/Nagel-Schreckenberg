#pragma once
#include "Car.h"
#include <iostream>

class Road
{
public:
	Road();
	~Road();
	void AddCar(Car * newCar);
	bool CheckCar();
	int GetSpeed();
	void DeleteCar();
	void ReplaceCar(Car * replacedCar);
	Car * GetCar();
	void CarSetToNULL();
	void setSpeed(int speed);
	void increaseSpeed();

private:
	Car * car;

};


