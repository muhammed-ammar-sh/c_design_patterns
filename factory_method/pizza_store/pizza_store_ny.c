#include "pizza_store_ny.h"
#include "../pizza/pizza_ny_style_cheese.h"
#include "../pizza/pizza_ny_style_veggie.h"
#include "../pizza/pizza_ny_style_clam.h"
#include <stddef.h>

pizza_t *PizzaStoreNY_CreatePizza(pizza_type_t type)
{
	switch (type)
	{
	case PIZZA_TYPE_CHEESE:
		return PizzaNYStyleCheese_Create();

	case PIZZA_TYPE_VEGGIE:
		return PizzaNYStyleVeggie_Create();

	case PIZZA_TYPE_CLAM:
		return PizzaNYStyleClam_Create();

	default:
		return NULL;
	}
}
