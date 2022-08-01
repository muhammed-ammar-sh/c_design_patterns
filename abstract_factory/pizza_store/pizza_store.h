#ifndef PIZZA_STORE_H
#define PIZZA_STORE_H

#include "stddef.h"
#include "..\pizza\pizza.h"
#include "..\drink\drink.h"

typedef struct pizza_store_st pizza_store_t;

typedef struct
{
	pizza_t *(*create_pizza)(pizza_type_t type);
	drink_t *(*create_drink)(void);
} pizza_store_methods_t;

struct pizza_store_st
{
	const pizza_store_methods_t *methods;
};


static inline pizza_t *PizzaStore_CreatePizza(pizza_store_t *store, pizza_type_t type)
{
	if (store && store->methods && store->methods->create_pizza)
		return store->methods->create_pizza(type);
	else
		return NULL;
}

static inline drink_t *PizzaStore_CreateDrink(pizza_store_t *store)
{
	if (store && store->methods && store->methods->create_drink)
		return store->methods->create_drink();
	else
		return NULL;
}

#endif