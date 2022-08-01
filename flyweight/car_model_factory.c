#include "car_model_factory.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static uint32_t models_count = 0;
static car_model_t *models[MAX_MODELS_COUNT];
// Instead of using array of pointers to dynamically allocated objects, we can
// use statically allocated array of objects with maximum number of elements???

car_model_t *CarModelFactory_GetModel(char *name, uint16_t tire_size, float tank_capacity,
									  float fuel_consumption, bool usb_charger,
									  bool fog_lights)
{
	for (uint16_t i = 0; i < models_count; i++)
	{
		// strcmp is used to find similar car model objects here, but in the real word a hashing
		// algorithm can be used, and the created objects can be held in a hash table (directory)
		if (strcmp(name, models[i]->name) == 0)
		{
			printf("Model %s is created before. No new model is created.\n", name);
			return models[i];
		}
	}

	if (models_count < MAX_MODELS_COUNT)
	{
		car_model_t *model = models[models_count++] = malloc(sizeof(car_model_t));
		strcpy(model->name, name);
		model->tire_size = tire_size;
		model->tank_capacity = tank_capacity;
		model->fuel_consumption = fuel_consumption;
		model->usb_charger = usb_charger;
		model->fog_lights = fog_lights;
		printf("Model %s is not created before. New model is created.\n", name);
		return model;
	}
}