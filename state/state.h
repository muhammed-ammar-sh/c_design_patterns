#ifndef STATE_H
#define STATE_H

#include "ui.h"
#include <stdint.h>

typedef struct state_st state_t;

typedef void (*state_init_t)(state_t *state);
typedef void (*state_go_up_t)(ui_t *, state_t *);
typedef void (*state_go_down_t)(ui_t *, state_t *);
typedef void (*state_select_t)(ui_t *, state_t *);
typedef void (*state_go_back_t)(ui_t *, state_t *);

typedef struct
{
	state_init_t init;
	state_go_up_t go_up;
	state_go_down_t go_down;
	state_select_t select;
	state_go_back_t go_back;
} state_methods_t;

struct state_st
{
	const state_methods_t *methods;
	uint32_t selected_item;
};

// Instead of creating the states in the heap at runtime using malloc when UI state is changed,
// I preferred to use static global state objects as this approach is more
// suitable with embedded systems (the field that I work with).
extern state_t main_state;
extern state_t select_prog_state;
extern state_t change_lang_state;
extern state_t connect_with_bl_state;

#endif