#ifndef CAR_MODEL_FACTORY_H
#define CAR_MODEL_FACTORY_H

#include <stdint.h>
#include <stdbool.h>

#define MAX_MODELS_COUNT	50

typedef struct 
{
	char name [50];
	uint16_t tire_size;
	float tank_capacity;
	float fuel_consumption;
	bool usb_charger;
	bool fog_lights;
}car_model_t;

car_model_t* CarModelFactory_GetModel(char* name, uint16_t tire_size, float tank_capacity, float fuel_consumption, bool usb_charger, bool fog_lights);

#endif