#pragma once
#include <iostream>
#include "Car.h"
#include "Road.h"
#include <windows.h>


class Simulator
{
public:
	Simulator(int new_road_lenght, int newTimeOfSimulation, int newProbability, int newfFrtuitousEvent);
	~Simulator();
	void Simulation();
	void draw();

private:
	int road_lenght, delay_lenght,timeOfSimulation,probability, fortuitousEvent;
	Road** road;
	Car** car;

};

