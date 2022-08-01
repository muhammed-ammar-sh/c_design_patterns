#ifndef PIZZA_H
#define PIZZA_H

#define MAX_TOPPINGS_COUNT 20

typedef struct pizza_st pizza_t;

typedef enum
{
	PIZZA_TYPE_CHEESE,
	PIZZA_TYPE_CLAM,
	PIZZA_TYPE_VEGGIE,
} pizza_type_t;

typedef struct
{
	void (*prepare)(pizza_t *pizza);
	void (*bake)(pizza_t *pizza);
	void (*cut)(pizza_t *pizza);
	void (*box)(pizza_t *pizza);
} pizza_methods_t;

struct pizza_st
{
	const pizza_methods_t *methods;
	char *name;
	char *dough;
	char *sauce;
	char *toppings[MAX_TOPPINGS_COUNT];
	int toppings_count;
};

void Pizza_Init(pizza_t *pizza);

void Pizza_Prepare(pizza_t *pizza);
void Pizza_Bake(pizza_t *pizza);
void Pizza_Cut(pizza_t *pizza);
void Pizza_Box(pizza_t *pizza);
void Pizza_AddTopping(pizza_t *pizza, char *topping);
void Pizza_PrintInfo(pizza_t *pizza);
#endif