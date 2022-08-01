#include "pizza_chicago_style_cheese.h"
#include <stdlib.h>
#include <stdio.h>

static void PizzaChicagoStyleCheese_Cut(pizza_t *pizza);

const static pizza_methods_t chicago_cheese_pizza_methods = {
	.prepare = Pizza_Prepare,
	.bake = Pizza_Bake,
	.cut = PizzaChicagoStyleCheese_Cut,
	.box = Pizza_Box,
};

pizza_t *PizzaChicagoStyleCheese_Create(void)
{
	pizza_t *pizza = malloc(sizeof(pizza_t));
	if (pizza)
	{
		Pizza_Init(pizza);
		pizza->methods = &chicago_cheese_pizza_methods;
		pizza->name = "Chicago Style Cheese";
		pizza->dough = "Extra Thick Crust";
		pizza->sauce = "Plum Tomato";
		Pizza_AddTopping(pizza, "Shredded Mozzarella Cheese");
	}
	return pizza;
}

static void PizzaChicagoStyleCheese_Cut(pizza_t *pizza)
{
	if (pizza)
	{
		printf("Cutting %s pizza into square slices\n", pizza->name);
	}
}