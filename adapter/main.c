#include "file_logger.h"
#include "screen_logger.h"

/**
 * The adapter pattern is a software design pattern that allows the interface of
 * an existing class to be used as another interface. It is often used to make
 * existing classes work with others without modifying their source code.
 *
 * In this example "Object adapter pattern" is implemented.
 */

void main(void)
{
	file_logger_t logger;
	FileLogger_Init(&logger);

	screen_logger_t logger2;
	ScreenLogger_Init(&logger2);

	// for different types of loggers, we use the same methods
	Logger_Start((logger_t *)&logger);
	Logger_Log((logger_t *)&logger, "Logging message to file");

	Logger_Start((logger_t *)&logger2);
	Logger_Log((logger_t *)&logger2, "Logging message to screen");
}
