#include "pizza.h"
#include <string.h>
#include <stdio.h>

static const pizza_methods_t pizza_methods = {
	.prepare = Pizza_Prepare,
	.bake = Pizza_Bake,
	.cut = Pizza_Cut,
	.box = Pizza_Box,
};

void Pizza_Init(pizza_t *pizza)
{
	if (pizza)
	{
		char empty_str[] = "";
		pizza->methods = &pizza_methods;
		pizza->name = empty_str;
		pizza->dough = empty_str;
		pizza->sauce = empty_str;
		pizza->toppings_count = 0;
	}
}

void Pizza_Prepare(pizza_t *pizza)
{
	if (pizza)
	{
		printf("Preparing %s pizza ...\n", pizza->name);
		printf("Tossing %s dough ...\n", pizza->dough);
		printf("Adding %s sauce ...\n", pizza->sauce);
		printf("Adding toppings ...\n");
		for (int i = 0; i < pizza->toppings_count; i++)
		{
			printf("\t%s\n", pizza->toppings[i]);
		}
	}
}

void Pizza_Bake(pizza_t *pizza)
{
	if (pizza)
	{
		printf("Baking %s pizza for 10 minutes at 250\n", pizza->name);
	}
}

void Pizza_Cut(pizza_t *pizza)
{
	if (pizza)
	{
		printf("Cutting %s pizza into diagonal slices\n", pizza->name);
	}
}

void Pizza_Box(pizza_t *pizza)
{
	if (pizza)
	{
		printf("Placing %s pizza in official pizza store box\n", pizza->name);
	}
}

void Pizza_AddTopping(pizza_t *pizza, char *topping)
{
	if (pizza && pizza->toppings_count < MAX_TOPPINGS_COUNT)
	{
		pizza->toppings[pizza->toppings_count++] = topping;
	}
}