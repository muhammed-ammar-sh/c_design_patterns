#include "pizza_store_chicago.h"
#include "../pizza/pizza_chicago_style_cheese.h"
#include "../pizza/pizza_chicago_style_veggie.h"
#include "../pizza/pizza_chicago_style_clam.h"
#include "../drink/drink_juice.h"

#include <stddef.h>

static pizza_t *PizzaStoreChicago_CreatePizza(pizza_type_t type);
static drink_t * PizzaStoreChicago_CreateDrink(void);

const static pizza_store_methods_t chicago_store_methods = {
	.create_pizza = PizzaStoreChicago_CreatePizza,
	.create_drink = PizzaStoreChicago_CreateDrink,
};

void PizzaStoreChicago_Init(pizza_store_t *store)
{
	if (store)
	{
		store->methods = &chicago_store_methods;
	}
}

static pizza_t *PizzaStoreChicago_CreatePizza(pizza_type_t type)
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


static drink_t * PizzaStoreChicago_CreateDrink(void)
{
	return DrinkJuice_Create();
}