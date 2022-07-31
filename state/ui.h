#ifndef UI_H
#define UI_H

typedef struct ui_st ui_t;
#include "state.h"

typedef enum
{
	LANG_START = 0,
	LANG_ENGLISH = LANG_START,
	LANG_TURKISH,
	LANG_ARABIC,
	LANG_END = LANG_ARABIC,
} language_t;

typedef enum
{
	PROG_START = 0,
	PROG_NONE = PROG_START,
	PROG_1,
	PROG_2,
	PROG_END = PROG_2,
} program_t;

struct ui_st
{
	state_t *current_state;
	language_t selected_lang;
	program_t selected_prog;
};

void UI_Init(ui_t *ui);

static inline void UI_GoUp(ui_t *ui)
{
	if (ui && ui->current_state->methods->go_up)
		ui->current_state->methods->go_up(ui, ui->current_state);
}

static inline void UI_GoDown(ui_t *ui)
{
	if (ui && ui->current_state->methods->go_down)
		ui->current_state->methods->go_down(ui, ui->current_state);
}

static inline void UI_Select(ui_t *ui)
{
	if (ui && ui->current_state->methods->select)
		ui->current_state->methods->select(ui, ui->current_state);
}

static inline void UI_GoBack(ui_t *ui)
{
	if (ui && ui->current_state->methods->go_back)
		ui->current_state->methods->go_back(ui, ui->current_state);
}

#endif