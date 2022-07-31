#include "ui_internal.h"

static void State_ChangeLang_Init(state_t *state);
static void State_ChangeLang_GoUp(ui_t *ui, state_t *state);
static void State_ChangeLang_GoDown(ui_t *ui, state_t *state);
static void State_ChangeLang_Select(ui_t *ui, state_t *state);
static void State_ChangeLang_GoBack(ui_t *ui, state_t *state);

const static state_methods_t change_lang_methods = {
	State_ChangeLang_Init,
	State_ChangeLang_GoUp,
	State_ChangeLang_GoDown,
	State_ChangeLang_Select,
	State_ChangeLang_GoBack,
};

state_t change_lang_state = {
	.methods = &change_lang_methods, // early binding
	.selected_item = 0,
};

static const char *change_lang_state_options[] = {"English", "Turkish", "Arabic"};

static void State_ChangeLang_Init(state_t *state)
{
	state->selected_item = 0;
	State_PrintOptions(change_lang_state_options, 3, state->selected_item);
}

///@brief "change language" state reaction for go up events
static void State_ChangeLang_GoUp(ui_t *ui, state_t *state)
{
	// change the highlighted option
	if (state->selected_item == LANG_START)
		state->selected_item = LANG_END;
	else
		state->selected_item--;
	State_PrintOptions(change_lang_state_options, 3, state->selected_item);
}

///@brief "change language" state reaction for go down events
static void State_ChangeLang_GoDown(ui_t *ui, state_t *state)
{
	// change the highlighted option
	if (state->selected_item == LANG_END)
		state->selected_item = LANG_START;
	else
		state->selected_item++;
	State_PrintOptions(change_lang_state_options, 3, state->selected_item);
}

///@brief "change language" state reaction for select option events
static void State_ChangeLang_Select(ui_t *ui, state_t *state)
{
	UI_ChangeLanguage(ui, (language_t)state->selected_item);
	UI_ChangeState(ui, &main_state);
}

///@brief "change language" state reaction for go back events
static void State_ChangeLang_GoBack(ui_t *ui, state_t *state)
{
	(void *)state;
	UI_ChangeState(ui, &main_state);
}
