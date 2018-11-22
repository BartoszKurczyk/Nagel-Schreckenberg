#pragma once
#include <iostream>
#include "Car.h"
#include "Road.h"
#include <windows.h>


class Simulator
{
public:
	Simulator();
	~Simulator();
	void Simulation();
	void draw();

private:
	int road_lenght, delay_lenght,timeOfSimulation,probability;
	Road** road;
	Car** car;

};

