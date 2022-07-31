#include "ui_internal.h"
#include <stdio.h>

static void State_ConnectBL_Init(state_t *state);
static void State_ConnectBL_GoUp(ui_t *ui, state_t *state);
static void State_ConnectBL_GoDown(ui_t *ui, state_t *state);
static void State_ConnectBL_Select(ui_t *ui, state_t *state);
static void State_ConnectBL_GoBack(ui_t *ui, state_t *state);

static void ConnectToBL_PrintStepMessage(state_t *state, uint32_t step);

const static state_methods_t connect_bl_methods = {
	State_ConnectBL_Init,
	State_ConnectBL_GoUp,
	State_ConnectBL_GoDown,
	State_ConnectBL_Select,
	State_ConnectBL_GoBack,
};

state_t connect_with_bl_state = {
	.methods = &connect_bl_methods, // early binding
	.selected_item = 0,
};

static const char *connect_bl_state_steps_msg[] =
	{"Connect to this machine Bluetooth network ...",
	 "Enter pin number : 12345",
	 "Connected !!!"};

static void State_ConnectBL_Init(state_t *state)
{
	state->selected_item = 0;
	ConnectToBL_PrintStepMessage(state, state->selected_item);
}

///@brief "connect BL" state reaction for go up events
static void State_ConnectBL_GoUp(ui_t *ui, state_t *state)
{
	// nothing to go up to in this state, ignore the event
	(void *)ui;	   // not used
	(void *)state; // not used
	return;
}

///@brief "connect BL" state reaction for go down events
static void State_ConnectBL_GoDown(ui_t *ui, state_t *state)
{
	// nothing to go down to in this state, ignore the event
	(void *)ui;	   // not used
	(void *)state; // not used
	return;
}

///@brief "connect BL" state reaction for select option events
static void State_ConnectBL_Select(ui_t *ui, state_t *state)
{
	// here select button is used to processed with connecting
	// bluetooth steps
	state->selected_item++;
	ConnectToBL_PrintStepMessage(state, state->selected_item);
	if (state->selected_item == 2) // 2 is the last step in the procedure
		UI_ChangeState(ui, &main_state);
}

///@brief "connect BL" state reaction for go back events
static void State_ConnectBL_GoBack(ui_t *ui, state_t *state)
{
	// pressing go back in the first step of this state returns you to
	// the main state
	if (state->selected_item == 0)
		UI_ChangeState(ui, &main_state);
	else
	{
		state->selected_item--;
	}
}

///@brief Prints the message of a given step of "connect BL" state
static void ConnectToBL_PrintStepMessage(state_t *state, uint32_t step)
{
	printf("%s\n", connect_bl_state_steps_msg[step]);
}