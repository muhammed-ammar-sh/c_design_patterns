#include "pizza_ny_style_cheese.h"
#include <stdlib.h>

pizza_t *PizzaNYStyleCheese_Create(void)
{
	pizza_t *pizza = malloc(sizeof(pizza_t));
	if (pizza)
	{
		Pizza_Init(pizza);
		pizza->name = "NY Style Cheese";
		pizza->dough = "Thin Crust";
		pizza->sauce = "Marinara";
		Pizza_AddTopping(pizza, "Grated Reggiano Cheese");
	}
	return pizza;
}