#include "drink_juice.h"
#include "stdlib.h"

drink_t *DrinkJuice_Create(void)
{
	drink_t *drink = malloc(sizeof(drink_t));
	if (drink)
	{
		drink->name = "Juice";
		drink->calories = 55;
	}
	return drink;
}
