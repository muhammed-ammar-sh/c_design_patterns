#ifndef SCREEN_LOGGER_H
#define SCREEN_LOGGER_H

#include "logger_interface.h"
#include <stdio.h>

/// screen logger implements logger interface
typedef struct
{
	logger_t super;
	// no adaptee object because printf is used
} screen_logger_t;

void ScreenLogger_Init(screen_logger_t *screen_logger);

#endif