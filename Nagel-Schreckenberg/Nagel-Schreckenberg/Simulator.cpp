#include "pch.h"
#include "Simulator.h"

Simulator::Simulator(int new_road_lenght, int newTimeOfSimulation, int newProbability, int newfFrtuitousEvent)
{
	
	probability = newProbability;
	timeOfSimulation = newTimeOfSimulation;
	road_lenght = new_road_lenght;
	fortuitousEvent = newfFrtuitousEvent;

	road = new Road*[2];

	for (int i = 0; i < 2; i++)
	{
		road[i] = new Road[road_lenght];
	}
	car = new Car*[2 * road_lenght+2];
}

Simulator::~Simulator()
{
	delete[] car;

	for (int i = 0; i < 2; i++)
	{
		delete[] road[i];
	}

	delete[] road;
	
}

void Simulator::Simulation()
{
	int k_tmp;
	int carIterator = 0;
	int distanceCounetr = 0;
	int randToMakeCarAliveSecond, randToMakeCarAliveFirst, randToMakeFortuitousEventFirst, randToMakeFortuitousEventSecond;
	bool flag = 1, speedIncreaseFlag = 1;
	for (int i = 0; i < timeOfSimulation; i++)
	{
		
		randToMakeCarAliveFirst = (std::rand() % 100) + 1;
		draw();
		randToMakeCarAliveSecond = (std::rand() % 100) + 1;
		randToMakeFortuitousEventFirst = (std::rand() % 100) + 1;
		randToMakeFortuitousEventSecond = (std::rand() % 100) + 1;
		

		for (int k = 0; k < road_lenght; k++)
		{
			if (road[0][k].CheckCar() && road[0][k - 1].CheckCar())
			{
				road[0][k].setNotIncrease(1);
			}
			else if(road[0][k].CheckCar() && !road[0][k - 1].CheckCar())
				road[0][k].setNotIncrease(0);
		}
		for (int k = road_lenght-1; k >= 0; k--)
		{
			if (road[1][k].CheckCar() && road[1][k + 1].CheckCar())
			{
				road[1][k].setNotIncrease(1);
			}
			else if (road[1][k].CheckCar() && !road[1][k + 1].CheckCar())
				road[1][k].setNotIncrease(0);
		}
		



		
		for (int k = 0; k < road_lenght; k++)
		{
			
			if (road[0][k].CheckCar())
			{
				flag = 1;
				speedIncreaseFlag = 1;
				if (randToMakeFortuitousEventFirst >= 1 && randToMakeFortuitousEventFirst <= fortuitousEvent)
				{
					road[0][k].decreaseSpeed();
					flag = 0;
				}
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
							if (distanceCounetr - 1 != 0)
							{
								road[0][k].setSpeed(distanceCounetr - 1);
							}
							speedIncreaseFlag = 0;
							break;
						}	
					}
					if (flag && speedIncreaseFlag && !road[0][k].getNotIncrease())
					{
						for (int z = k - 1; z >= k - road[0][k].GetSpeed() - 1; z--)
						{
							if (road[0][z].CheckCar()) break;
							else if (z == k - road[0][k].GetSpeed() - 1)
							{
								road[0][k].increaseSpeed();
								break;
							}
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
				flag = 1;
				speedIncreaseFlag = 1;
				if (randToMakeFortuitousEventSecond >= 1 && randToMakeFortuitousEventSecond <= fortuitousEvent)
				{
					road[1][k].decreaseSpeed();
					flag = 0;
				}
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
							if (distanceCounetr - 1 != 0)
							{
								road[1][k].setSpeed(distanceCounetr - 1);
							}
							speedIncreaseFlag = 0;
							break;
						}
						

					}
					if (flag && speedIncreaseFlag && !road[1][k].getNotIncrease())
					{
						for (int z = k+1; z <= k + road[1][k].GetSpeed() + 1; z++)
						{
							if (road[1][z].CheckCar()) break;
							else if (z == k + road[1][k].GetSpeed() + 1)
							{
								road[1][k].increaseSpeed();
								break;
							}
						}	
					}
					distanceCounetr = 0;
					k_tmp = k + road[1][k].GetSpeed();
					road[1][k_tmp].ReplaceCar(road[1][k].GetCar());
					road[1][k].CarSetToNULL();
				}
			}
			
		}
		
		if ((randToMakeCarAliveFirst >= 1 && randToMakeCarAliveFirst <= probability))
		{

			road[0][road_lenght - 1].AddCar(car[carIterator]);
			carIterator++;
			if (carIterator == (2 * road_lenght) + 1) carIterator = 0;
		}
		if (randToMakeCarAliveSecond >= 1 && randToMakeCarAliveSecond <= probability)
		{

			road[1][0].AddCar(car[carIterator]);
			if (carIterator == (2 * road_lenght) + 1) carIterator = 0;
			carIterator++;

		}
		Sleep(1000);
		flag = 1;
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
				std::cout << road[i][j].GetSpeed()<<"  ";
			}
			else
			{
				std::cout << ".  ";
			}
		}
		std::cout << std::endl;
	}
}
