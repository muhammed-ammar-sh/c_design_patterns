#include "pizza_store_ny.h"
#include "../pizza/pizza_ny_style_cheese.h"
#include "../pizza/pizza_ny_style_veggie.h"
#include "../pizza/pizza_ny_style_clam.h"
#include "../drink/drink_soda.h"

#include <stddef.h>

static pizza_t *PizzaStoreNY_CreatePizza(pizza_type_t type);
static drink_t * PizzaStoreNY_CreateDrink(void);

const static pizza_store_methods_t ny_store_methods = {
	.create_pizza = PizzaStoreNY_CreatePizza,
	.create_drink = PizzaStoreNY_CreateDrink,
};

void PizzaStoreNY_Init(pizza_store_t *store)
{
	if (store)
	{
		store->methods = &ny_store_methods;
	}
}

static pizza_t *PizzaStoreNY_CreatePizza(pizza_type_t type)
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

static drink_t * PizzaStoreNY_CreateDrink(void)
{
	return DrinkSoda_Create();
}