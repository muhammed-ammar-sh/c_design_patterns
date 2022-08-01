#include "car_model_factory.h"
#include "car.h"
/**
 * Flyweight is a structural design pattern that lets you fit more objects into
 * the available amount of RAM by sharing common parts of state between multiple
 * objects instead of keeping all of the data in each object.
 * Refactoring Guru - Flyweight
 * 
 */
int main(void)
{
	car_t *cars[4];
	
	car_model_t *m1 = CarModelFactory_GetModel("Toyota Corolla Hybrid", 195, 42.2, 3.5, true, false);
	// Model Toyota Corolla Hybrid is not created before. New model is created.

	car_t c1;
	Car_Init(&c1, "00000001", BLACK, m1);
	cars[0] = &c1;

	car_model_t *m2 = CarModelFactory_GetModel("Toyota Corolla Hybrid", 195, 42.2, 3.5, true, false);
	// Model Toyota Corolla Hybrid is created before. No new model is created.

	car_t c2;
	Car_Init(&c2, "00000002", WHITE, m2);
	cars[1] = &c2;

	car_model_t *m3 = CarModelFactory_GetModel("Hyundai Accent Mode", 175, 42.0, 5.5, true, true);
	// Model Hyundai Accent Mode is not created before. New model is created.

	car_t c3;
	Car_Init(&c3, "00000003", RED, m3);
	cars[2] = &c3;

	car_model_t *m4 = CarModelFactory_GetModel("Hyundai Accent Mode", 175, 42.0, 5.5, true, true);
	// Model Hyundai Accent Mode is created before. No new model is created.

	car_t c4;
	Car_Init(&c4, "00000004", BLACK, m4);
	cars[3] = &c4;


	for (int i = 0; i < 4; i++)
		Car_PrintInfo(cars[i]);

	return 0;
}