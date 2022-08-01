#ifndef PIZZA_STORE_H
#define PIZZA_STORE_H

#include "..\pizza\pizza.h"

typedef struct pizza_store_st pizza_store_t;
	
typedef pizza_t *(*create_pizza_method_t)(pizza_type_t type);

struct pizza_store_st
{
	create_pizza_method_t create_pizza_method; // our factory method pointer
};

void PizzaStore_Init(pizza_store_t *store, create_pizza_method_t create_pizza_method);

pizza_t *PizzaStore_Order(pizza_store_t *store, pizza_type_t type);

#endif