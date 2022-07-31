#include "ui_internal.h"
#include <stdio.h>

static void State_Main_Init(state_t *state);
static void State_Main_GoUp(ui_t *ui, state_t *state);
static void State_Main_GoDown(ui_t *ui, state_t *state);
static void State_Main_Select(ui_t *ui, state_t *state);
static void State_Main_GoBack(ui_t *ui, state_t *state);

const static state_methods_t main_methods = {
	State_Main_Init,
	State_Main_GoUp,
	State_Main_GoDown,
	State_Main_Select,
	State_Main_GoBack,
};

state_t main_state = {
	.methods = &main_methods, // early binding
	.selected_item = 0,
};

enum MainMenuOptions
{
	OPTION_START = 0,
	OPTION_START_A_PROGRAM = OPTION_START,
	OPTION_CONNECT_WITH_BL,
	OPTION_CHANGE_UI_LANGUAGE,
	OPTION_END = OPTION_CHANGE_UI_LANGUAGE,
};

static const char *main_state_options[] = {
	"Start a program",
	"Connect with Bluetooth",
	"Change UI language",
};

static void State_Main_Init(state_t *state)
{
	state->selected_item = 0;
	State_PrintOptions(main_state_options, 3, state->selected_item);
}

///@brief main state reaction for go up events
static void State_Main_GoUp(ui_t *ui, state_t *state)
{
	// change the highlighted option
	if (state->selected_item == OPTION_START)
		state->selected_item = OPTION_END;
	else
		state->selected_item--;

	State_PrintOptions(main_state_options, ARRAY_SIZE(main_state_options),
					   state->selected_item);
}

///@brief main state reaction for go down events
static void State_Main_GoDown(ui_t *ui, state_t *state)
{
	// change the highlighted option
	if (state->selected_item == OPTION_END)
		state->selected_item = OPTION_START;
	else
		state->selected_item++;
	State_PrintOptions(main_state_options, ARRAY_SIZE(main_state_options),
					   state->selected_item);
}

///@brief main state reaction for select option events
static void State_Main_Select(ui_t *ui, state_t *state)
{
	state_t *new_state = NULL;
	switch (state->selected_item)
	{
	case OPTION_START_A_PROGRAM:
		new_state = &select_prog_state;
		break;

	case OPTION_CONNECT_WITH_BL:
		new_state = &connect_with_bl_state;
		break;

	case OPTION_CHANGE_UI_LANGUAGE:
		new_state = &change_lang_state;
		break;
	}
	UI_ChangeState(ui, new_state);
}

///@brief main state reaction for go back events
static void State_Main_GoBack(ui_t *ui, state_t *state)
{
	// nothing to go back to in main state, ignore event
	(void *)ui;	   // not used
	(void *)state; // not used
	return;
}

/*****************************************************************************/

///@brief Prints array of strings (options) in separate lines and puts a "<---" near the selected option
///@note This function is can be called from all states and not related to "state_main" only
void State_PrintOptions(const char *options[], size_t options_count, uint32_t highlighted_option)
{
	for (size_t i = 0; i < options_count; i++)
	{
		printf("%s\t\t%s\n", options[i], i == highlighted_option ? "<---" : "");
	}
}