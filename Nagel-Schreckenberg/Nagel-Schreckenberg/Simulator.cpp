#include "pch.h"
#include "Simulator.h"

Simulator::Simulator()
{
	
	probability = 80;
	timeOfSimulation = 50;
	road_lenght = 20;

	road = new Road*[2];

	for (int i = 0; i < 2; i++)
	{
		road[i] = new Road[road_lenght];
	}
	car = new Car*[2 * road_lenght+2];
}

Simulator::~Simulator()
{
	
}

void Simulator::Simulation()
{
	int k_tmp;
	int carIterator = 0;
	int distanceCounetr = 0;
	int randToMakeCarAliveSecond, randToMakeCarAliveFirst;
	bool flag = 1;
	for (int i = 0; i < timeOfSimulation; i++)
	{
		draw();
		randToMakeCarAliveFirst = (std::rand() % 100) + 1;
		randToMakeCarAliveSecond= (std::rand() % 100) + 1;
		
		
		for (int k = 0; k < road_lenght; k++)
		{
			
			if (road[0][k].CheckCar())
			{
				k_tmp = k - road[0][k].GetSpeed();
				if (k_tmp < 0)
				{
					road[0][k].DeleteCar();
				}
				else
				{
					for (int l = k - 1; l >= k - road[0][k].GetSpeed(); l--)
					{
						distanceCounetr++;
						if (road[0][l].CheckCar())//Przemieœci siê o odleg³oœæ i zmieni prêdkoœæ
						{
							road[0][k].setSpeed(distanceCounetr-1);
						}
						if (l == k - road[0][k].GetSpeed())
						{
							road[0][k].increaseSpeed();
							break;
						}
								
					}
					distanceCounetr = 0;
					k_tmp = k - road[0][k].GetSpeed();
					road[0][k_tmp].ReplaceCar(road[0][k].GetCar());
					road[0][k].CarSetToNULL();
				}
			}
			
		}
		for (int k = road_lenght - 1; k >= 0; k--)
		{
			
			if (road[1][k].CheckCar())
			{
				k_tmp = k + road[1][k].GetSpeed();
				if (k_tmp > road_lenght-1)
				{
					road[1][k].DeleteCar();
				}
				else
				{
					for (int l = k + 1; l <= k + road[1][k].GetSpeed(); l++)
					{
						distanceCounetr++;
						if (road[1][l].CheckCar())//Przemieœci siê o odleg³oœæ i zmieni prêdkoœæ
						{
							road[1][k].setSpeed(distanceCounetr - 1);
							break;
						}
						if (l == k + road[1][k].GetSpeed())
						{
							road[1][k].increaseSpeed();
							break;
						}

					}
					distanceCounetr = 0;
					k_tmp = k + road[1][k].GetSpeed();
					road[1][k_tmp].ReplaceCar(road[1][k].GetCar());
					road[1][k].CarSetToNULL();
				}
			}
			
		}
		
		if ((randToMakeCarAliveFirst >= 1 && randToMakeCarAliveFirst <= probability)/* || flag*/)
		{

			road[0][road_lenght - 1].AddCar(car[carIterator]);
			carIterator++;
			if (carIterator == (2 * road_lenght) + 1) carIterator = 0;
			flag = 0;

		}
		if (randToMakeCarAliveSecond >= 1 && randToMakeCarAliveSecond <= probability)
		{

			road[1][0].AddCar(car[carIterator]);
			if (carIterator == (2 * road_lenght) + 1) carIterator = 0;
			carIterator++;

		}
		Sleep(1000);
		//getchar();
	}

	

}

void Simulator::draw()
{
	system("CLS");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < road_lenght; j++)
		{
			if (road[i][j].CheckCar())
			{
				std::cout << "*  ";
			}
			else
			{
				std::cout << ".  ";
			}
		}
		std::cout << std::endl;
	}
}
