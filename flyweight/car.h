#ifndef CAR_H
#define CAR_H

#include "car_model_factory.h"

typedef enum 
{
	BLACK,
	WHITE,
	RED,
	GREEN,
	BLUE,
}color_t;

typedef struct 
{
	char serial_number[50];
	color_t color;
	car_model_t* model; /// pointer to car model object the shared state
}car_t;

void Car_Init(car_t *car, char *serial_number, color_t color, car_model_t *model);
void Car_PrintInfo(car_t *car);

#endif