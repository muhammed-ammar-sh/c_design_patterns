#include "drink_soda.h"
#include "stdlib.h"

drink_t *DrinkSoda_Create(void)
{
	drink_t *drink = malloc(sizeof(drink_t));
	if (drink)
	{
		drink->name = "Soda";
		drink->calories = 30;
	}
	return drink;
}
