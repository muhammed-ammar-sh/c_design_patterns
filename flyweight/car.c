#include "car.h"
#include <string.h>
#include <stdio.h>

static char *getColorName(color_t color);

void Car_Init(car_t *car, char *serial_number, color_t color, car_model_t *model)
{
	if (car)
	{
		strcpy(car->serial_number, serial_number);
		car->color = color;
		car->model = model;
	}
}

void Car_PrintInfo(car_t *car)
{
	if (car)
	{
		printf("Car with \"%s\" serial number has the next info:\n ", car->serial_number);
		printf("\tColor : %s\n", getColorName(car->color));
		printf("\tModel : %s\n", car->model->name);
		printf("\tTire size : %d\n", car->model->tire_size);
		printf("\tTank capacity : %.2f\n", car->model->tank_capacity);
		printf("\tFuel consumption : %.2f\n", car->model->fuel_consumption);
		printf("\tUsb charger : %s\n", car->model->usb_charger ? "Yes" : "No");
		printf("\tFog lights : %s\n", car->model->fog_lights ? "Yes" : "No");
		printf("\n\n");
	}
}

static char *getColorName(color_t color)
{
	switch (color)
	{
	case BLACK:
		return "Black";

	case WHITE:
		return "White";

	case BLUE:
		return "Blue";

	case RED:
		return "Red";

	case GREEN:
		return "Green";

	default:
		return "Color undefined";
	}
}