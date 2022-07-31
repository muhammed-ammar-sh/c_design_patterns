#ifndef UI_INTERNAL_H
#define UI_INTERNAL_H

#include "ui.h"
#include "state.h"

void UI_ChangeLanguage(ui_t *ui, language_t lang);
void UI_StartProgram(ui_t *ui, program_t prog);
void UI_ChangeState(ui_t *ui, state_t *state);
void State_PrintOptions(const char *options[], size_t options_count, uint32_t highlighted_option);

#define ARRAY_SIZE(arr)  (sizeof(arr) / sizeof (arr[0]))

#endif