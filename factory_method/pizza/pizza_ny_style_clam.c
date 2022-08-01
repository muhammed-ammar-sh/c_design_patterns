#include "pizza_ny_style_clam.h"
#include <stdlib.h>

pizza_t *PizzaNYStyleClam_Create(void)
{
	pizza_t *pizza = malloc(sizeof(pizza_t));
	if (pizza)
	{
		Pizza_Init(pizza);
		pizza->name = "NY Style Clam";
		pizza->dough = "Thin Crust";
		pizza->sauce = "Calm sauce";
		Pizza_AddTopping(pizza, "Grated Parmesan Cheese");
		Pizza_AddTopping(pizza, "Chopped Fresh Oregano");
	}
	return pizza;
}