#include "pizza_store.h"
#include <stddef.h>


void PizzaStore_Init(pizza_store_t *store, create_pizza_method_t create_pizza_method)
{
	if (store)
	{
		store->create_pizza_method = create_pizza_method;
	}
}

pizza_t *PizzaStore_Order(pizza_store_t *store, pizza_type_t type)
{
	if (store && store->create_pizza_method)
	{
		pizza_t *pizza = store->create_pizza_method(type);
		if (pizza)
		{
			pizza->methods->prepare(pizza);
			pizza->methods->bake(pizza);
			pizza->methods->cut(pizza);
			pizza->methods->box(pizza);
		}
		return pizza;
	}
}