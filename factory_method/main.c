#include <stdio.h>
#include "pizza/pizza.h"
#include "pizza_store/pizza_store_ny.h"
#include "pizza_store/pizza_store_chicago.h"

/**
 * Factory Method is a creational design pattern that provides an interface for
 * creating objects in a superclass, but allows subclasses to alter the type of
 * objects that will be created.
 * Refactoring Guru - Factory Method
 *
 * The idea of this example is taken from "Head first - Design Patters" book by
 * Eric Freeman, Elisabeth Freeman, Bert Bates, Kathy Sierra.
 */

int main(void)
{

	// Initialize a store and select its factory method
	pizza_store_t ny_store;
	PizzaStore_Init(&ny_store, PizzaStoreNY_CreatePizza);

	pizza_t *p1 = PizzaStore_Order(&ny_store, PIZZA_TYPE_CHEESE);
	puts("\n");

	pizza_t *p2 = PizzaStore_Order(&ny_store, PIZZA_TYPE_VEGGIE);
	puts("\n");

	pizza_t *p3 = PizzaStore_Order(&ny_store, PIZZA_TYPE_CLAM);
	puts("\n");

	/******************************/

	// Initialize a store and select its factory method
	pizza_store_t chicago_store;
	PizzaStore_Init(&chicago_store, PizzaStoreChicago_CreatePizza);

	pizza_t *p4 = PizzaStore_Order(&chicago_store, PIZZA_TYPE_CHEESE);
	puts("\n");

	pizza_t *p5 = PizzaStore_Order(&chicago_store, PIZZA_TYPE_VEGGIE);
	puts("\n");

	pizza_t *p6 = PizzaStore_Order(&chicago_store, PIZZA_TYPE_CLAM);
	puts("\n");

	return 0;
}