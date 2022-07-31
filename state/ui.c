#include "ui_internal.h"
#include <stdio.h>

void UI_Init(ui_t *ui)
{
	if (ui)
	{
		ui->selected_lang = LANG_ENGLISH;
		ui->selected_prog = PROG_NONE;
		UI_ChangeState(ui, &main_state);
	}
}

void UI_ChangeLanguage(ui_t *ui, language_t lang)
{
	printf("UI Language is changed to %s\n",
		   lang == LANG_ENGLISH	  ? "English"
		   : lang == LANG_TURKISH ? "Turkish"
								  : "Arabic");
}

void UI_StartProgram(ui_t *ui, program_t prog)
{
	if (prog == PROG_NONE)
		printf("Machine is stopped\n");
	else
		printf("Machine started program %d\n", (uint32_t)prog);
}

void UI_ChangeState(ui_t *ui, state_t *state)
{
	if (ui && state)
	{
		ui->current_state = state;
		state->methods->init(state);
	}
}