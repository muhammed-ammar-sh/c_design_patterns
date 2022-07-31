#include "ui_internal.h"

static void State_SelProg_Init(state_t *state);
static void State_SelProg_GoUp(ui_t *ui, state_t *state);
static void State_SelProg_GoDown(ui_t *ui, state_t *state);
static void State_SelProg_Select(ui_t *ui, state_t *state);
static void State_SelProg_GoBack(ui_t *ui, state_t *state);

const static state_methods_t sel_prog_methods = {
	State_SelProg_Init,
	State_SelProg_GoUp,
	State_SelProg_GoDown,
	State_SelProg_Select,
	State_SelProg_GoBack,
};

state_t select_prog_state = {
	.methods = &sel_prog_methods, // early binding
	.selected_item = 0,
};

static const char *sel_prog_state_options[] = {
	"Stop",
	"Program 1",
	"Program 2",
};

static void State_SelProg_Init(state_t *state)
{
	state->selected_item = 0;
	State_PrintOptions(sel_prog_state_options, 3, state->selected_item);
}

///@brief "select program" state reaction for go up events
static void State_SelProg_GoUp(ui_t *ui, state_t *state)
{
	// change the highlighted option
	if (state->selected_item == PROG_START)
		state->selected_item = PROG_END;
	else
		state->selected_item--;
	State_PrintOptions(sel_prog_state_options, 3, state->selected_item);
}

///@brief "select program" state reaction for go down events
static void State_SelProg_GoDown(ui_t *ui, state_t *state)
{
	// change the highlighted option
	if (state->selected_item == PROG_END)
		state->selected_item = PROG_START;
	else
		state->selected_item++;
	State_PrintOptions(sel_prog_state_options, 3, state->selected_item);
}

///@brief "select program" state reaction for select option events
static void State_SelProg_Select(ui_t *ui, state_t *state)
{
	UI_StartProgram(ui, (program_t)state->selected_item);
	UI_ChangeState(ui, &main_state);
}

///@brief "select program" state reaction for go back events
static void State_SelProg_GoBack(ui_t *ui, state_t *state)
{
	(void *)state;
	UI_ChangeState(ui, &main_state);
}
