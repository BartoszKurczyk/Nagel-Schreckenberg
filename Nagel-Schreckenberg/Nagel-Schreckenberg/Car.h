#pragma once
#include <iostream>

class Car
{
public:
	
	Car();
	~Car();
	int car_lenght,v,vmax;
	bool notToIncreaseSpeed;
	void setTrueNotToIncreaseSpeed();
	void setFalseNotToIncreaseSpeed();
	bool getNotToIncreaseSpeed();
};


