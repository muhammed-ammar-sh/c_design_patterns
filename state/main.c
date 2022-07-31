#include <stdio.h>
#include "ui.h"

/**
 * The state pattern is a behavioral software design pattern that allows an 
 * object to alter its behavior when its internal state changes. This pattern
 * is close to the concept of finite-state machines.
 * 
 * In this example a UI interface of an embedded system is simulated.
 * The user can go up / down / back, and select an item from the UI.
 * An interaction with UI may lead to change the current state or some settings 
 * on the UI.
 * Each state is implemented in a separate module and its code is decoupled from
 * the UI code and the other states codes.
 * 
 */


int main(void)
{
	ui_t ui;
	UI_Init(&ui);
	while (1)
	{
		char c = getchar();
		switch (c)
		{
		case 'u':
		case 'U':
			UI_GoUp(&ui);
			break;

		case 'd':
		case 'D':
			UI_GoDown(&ui);
			break;

		case 'b':
		case 'B':
			UI_GoBack(&ui);
			break;

		case 's':
		case 'S':
			UI_Select(&ui);
			break;
		}
	}

	return 0;
}
