// Nagel-Schreckenberg.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include "Simulator.h"
#include <ctime>

int main()
{
	srand(time(NULL));
	Simulator *sim = new Simulator();


	sim->Simulation();

	delete sim;

	return 0;

}

