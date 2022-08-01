#include "pizza_store_chicago.h"
#include "../pizza/pizza_chicago_style_cheese.h"
#include "../pizza/pizza_chicago_style_veggie.h"
#include "../pizza/pizza_chicago_style_clam.h"
#include <stddef.h>

pizza_t *PizzaStoreChicago_CreatePizza(pizza_type_t type)
{
	switch (type)
	{
	case PIZZA_TYPE_CHEESE:
		return PizzaChicagoStyleCheese_Create();

	case PIZZA_TYPE_VEGGIE:
		return PizzaChicagoStyleVeggie_Create();

	case PIZZA_TYPE_CLAM:
		return PizzaChicagoStyleClam_Create();

	default:
		return NULL;
	}
}
