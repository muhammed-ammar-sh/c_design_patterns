#ifndef DRINK_H
#define DRINK_H

typedef struct 
{
	char * name;
	int calories;
}drink_t;

typedef enum
{
	DRINK_TYPE_SODA,
	DRINK_TYPE_JUICE,
}drink_type_t;

void Drink_Init(drink_t* drink);
void Drink_PrintInfo(drink_t* drink);

#endif
