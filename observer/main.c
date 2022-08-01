#include <stdio.h>
#include <stdint.h>
#include "observer.h"

typedef struct
{
	uint8_t led_state;
	//
	//
	observer_t temp_observer;
} ui_process_params_t;

typedef struct
{
	uint8_t heater_state;
	//
	observer_t temp_observer;
} heater_controller_process_params_t;

observer_core_t ob_core;

// in ui.c file
ui_process_params_t ui;
void UI_TempUpdatedEvent(void *obj, observer_data_t data)
{
	if (obj)
	{
		ui_process_params_t *ui = obj;
		printf("UI process:\t New temp data received %f\n", data);

		uint8_t new_led_state = data > 50.0;
		if (new_led_state != ui->led_state)
		{
			ui->led_state = new_led_state;
			printf("UI process:\t Led state is changed to %d\n", new_led_state);
		}
		printf("\n");
	}
}

// in heater_controller.c file
heater_controller_process_params_t heater_controller;
void HeaterController_TempUpdatedEvent(void *obj, observer_data_t data)
{
	if (obj)
	{
		heater_controller_process_params_t *hc = obj;
		printf("HC process:\t New temp data received %f\n", data);

		uint8_t new_heater_state = data <= 50.0;
		if (new_heater_state != hc->heater_state)
		{
			hc->heater_state = new_heater_state;
			printf("HC process:\t Heater state is changed to %d\n", new_heater_state);
		}
		printf("\n");
	}
}

void main(void)
{
	ObserverCore_Init(&ob_core);

	// in ui process
	ObserverCore_Attach(&ob_core, &ui.temp_observer, UI_TempUpdatedEvent, &ui);

	// in heater controller process
	ObserverCore_Attach(&ob_core, &heater_controller.temp_observer, HeaterController_TempUpdatedEvent, &heater_controller);

	int c = 5;	// remove heater observer after 5 times
	while (1)
	{
		// in ntc process
		// get new data
		float temp;
		scanf("%f", &temp);
		ObserverCore_Set(&ob_core, temp);
		c--;
		if (c == 0)
			ObserverCore_Remove(&ob_core, &heater_controller.temp_observer);
	}
}