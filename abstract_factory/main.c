#include "pizza/pizza.h"
#include "drink/drink.h"
#include "pizza_store/pizza_store_ny.h"
#include "pizza_store/pizza_store_chicago.h"
#include <stdio.h>

/**
 * "The abstract factory pattern provides a way to encapsulate a group of individual
 * factories that have a common theme without specifying their concrete classes."
 * Wikipedia - Abstract Factory Pattern
 * 
 * The idea of this example is derived from "Head first - Design Patters" book by
 * Eric Freeman, Elisabeth Freeman, Bert Bates, Kathy Sierra.
 */

int main(void)
{

	pizza_store_t ny_store;
	PizzaStoreNY_Init(&ny_store);

	pizza_t *p1 = PizzaStore_CreatePizza(&ny_store, PIZZA_TYPE_CHEESE);
	Pizza_PrintInfo(p1);
	puts("\n");

	drink_t* d1 = PizzaStore_CreateDrink(&ny_store);
	Drink_PrintInfo(d1);
	puts("\n\n\n");

	pizza_store_t chicago_store;
	PizzaStoreChicago_Init(&chicago_store);

	pizza_t *p2 = PizzaStore_CreatePizza(&chicago_store, PIZZA_TYPE_CHEESE);
	Pizza_PrintInfo(p2);
	puts("\n");

	drink_t* d2 = PizzaStore_CreateDrink(&chicago_store);
	Drink_PrintInfo(d2);
	puts("\n\n\n");

	return 0;
}