#include "pizza_chicago_style_veggie.h"
#include <stdlib.h>

pizza_t *PizzaChicagoStyleVeggie_Create(void)
{
	pizza_t *pizza = malloc(sizeof(pizza_t));
	if (pizza)
	{
		Pizza_Init(pizza);
		pizza->name = "Chicago Style Veggie";
		pizza->dough = "Extra Thick Crust";
		pizza->sauce = "Plum Tomato";
		Pizza_AddTopping(pizza, "Shredded Mozzarella Cheese");
		Pizza_AddTopping(pizza, "Roasted Red Peppers");
		Pizza_AddTopping(pizza, "Dried Oregano");
	}
	return pizza;
}