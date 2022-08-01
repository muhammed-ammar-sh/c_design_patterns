#include "drink.h"
#include <stdio.h>

void Drink_Init(drink_t* drink)
{
	if (drink)
	{
		drink->name = "";
		drink->calories = 0;
	}
}

void Drink_PrintInfo(drink_t* drink)
{
	if (drink)
	{
		printf("%s Drink Info : \n", drink->name);
		printf("\tCalories = %d\n", drink->calories);
	}
}