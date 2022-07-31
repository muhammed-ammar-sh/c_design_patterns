#include "logger.h"
#include <stdlib.h>
#include <time.h>

static logger_t single_instance;
static void Logger_Init(logger_t *logger);

static void Logger_Init(logger_t *logger)
{
	if (logger)
	{
		logger->file = fopen("log.txt", "a");
	}
}

logger_t *Logger_GetInstance(void)
{
	static logger_t *instance_ptr = NULL;
	// or static bool instance_initialized_before = false;
	// if (!instance_initialized_before)
	if (instance_ptr == NULL)
	{
		instance_ptr = &single_instance;
		// or
		// instance_ptr = malloc(sizeof(logger_t));
		Logger_Init(instance_ptr);
	}
	return instance_ptr;
}

void Logger_Write(logger_t *logger, char *str)
{
	if (logger)
	{
		time_t raw_time = time(NULL);
		struct tm tm = *localtime(&raw_time);

		fprintf(logger->file, "%02d-%02d-%d %02d:%02d:%02d\t\t%s\n",
				tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900,
				tm.tm_hour, tm.tm_min, tm.tm_sec,
				str);
	}
}