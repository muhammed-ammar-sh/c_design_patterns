#ifndef FILE_LOGGER_H
#define FILE_LOGGER_H

#include "logger_interface.h"
#include <stdio.h>

/// file logger implements logger interface
typedef struct
{
	logger_t super;
	FILE *file; // adaptee object
} file_logger_t;

void FileLogger_Init(file_logger_t *file_logger);

#endif