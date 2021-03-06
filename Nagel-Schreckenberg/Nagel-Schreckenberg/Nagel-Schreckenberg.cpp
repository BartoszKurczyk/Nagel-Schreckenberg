// Nagel-Schreckenberg.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include "Simulator.h"
#include <ctime>

void menu(int* road_lenght, int* timeOfSimulation, int* probability, int* fortuitousEvent)
{
	using namespace std;
	int cont;

	while (true)
	{
		cout << "Nagel-Schreckenberg Model Simulator" << endl;
		cout << "Set road lenght: ";
		cin >> *road_lenght;
		cout << "Set time of simulation: ";
		cin >> *timeOfSimulation;
		cout << "Set the probability of a new car appearing: ";
		cin >> *probability;
		cout << "Set probability of fortuitous events: ";
		cin >> *fortuitousEvent;

		cout << "If you want to continue write 1, if you want change settings write everythin else: ";
		cin >> cont;
		if (cont == 1)break;
	}


}

int main()
{
	srand(time(NULL));
	int road_lenght=30, timeOfSimulation=50, probability=80, fortuitousEvent=10;
	menu(&road_lenght, &timeOfSimulation, &probability, &fortuitousEvent);
	Simulator *sim = new Simulator(road_lenght, timeOfSimulation, probability, fortuitousEvent);


	sim->Simulation();

	delete sim;

	return 0;

}

