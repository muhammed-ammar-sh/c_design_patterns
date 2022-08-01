#include "pizza_ny_style_veggie.h"
#include <stdlib.h>

pizza_t *PizzaNYStyleVeggie_Create(void)
{
	pizza_t *pizza = malloc(sizeof(pizza_t));
	if (pizza)
	{
		Pizza_Init(pizza);
		pizza->name = "NY Style Veggie";
		pizza->dough = "Thin Crust";
		pizza->sauce = "Red Pasta";
		Pizza_AddTopping(pizza, "Olive");
		Pizza_AddTopping(pizza, "Green Pepper Flakes");
		Pizza_AddTopping(pizza, "Tomato Slices");
		Pizza_AddTopping(pizza, "Shredded Mozzarella Cheese");
	}
	return pizza;
}