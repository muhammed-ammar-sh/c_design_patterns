#include "logger.h"

/**
 * The singleton pattern is a software design pattern that restricts the 
 * instantiation of a class to one "single" instance. This is useful when 
 * exactly one object is needed to coordinate actions across the system.
 *
 * In this example, only one logger object should actually be initialized,
 * this is because the log file should be opened only once for writing, no
 * matter how many processes try to access it.
 * 
 */
int main(void)
{
	// In the first call a new logger instance is created / initialized
	logger_t *process_1_logger = Logger_GetInstance();
	Logger_Write(process_1_logger, "Process 1 started");

	// from another process, Logger_GetInstance return the
	// instance that is created before.
	logger_t *process_2_logger = Logger_GetInstance();
	Logger_Write(process_2_logger, "Process 2 started");

	return 0;
}