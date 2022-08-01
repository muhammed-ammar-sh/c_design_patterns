#ifndef LOGGER_INTERFACE_H
#define LOGGER_INTERFACE_H

#include <stdint.h>
#include <stdbool.h>

typedef struct logger_struct logger_t;

typedef struct
{
	void (*start)(logger_t *logger);
	void (*log)(logger_t *logger, char *msg);
} logger_methods_t;

struct logger_struct
{
	const logger_methods_t *methods;
};

static inline void Logger_Start(logger_t *logger)
{
	if (logger)
		logger->methods->start(logger);
}

static inline void Logger_Log(logger_t *logger, char *msg)
{
	if (logger)
		logger->methods->log(logger, msg);
}

#endif