#include "pizza_chicago_style_clam.h"
#include <stdlib.h>

pizza_t *PizzaChicagoStyleClam_Create(void)
{
	pizza_t *pizza = malloc(sizeof(pizza_t));
	if (pizza)
	{
		Pizza_Init(pizza);
		pizza->name = "Chicago Style Clam";
		pizza->dough = "Extra Thick Crust";
		pizza->sauce = "Calm sauce";
		Pizza_AddTopping(pizza, "Shredded Mozzarella Cheese");
		Pizza_AddTopping(pizza, "Red Pepper Flakes");
	}
	return pizza;
}