#include "file_logger.h"

static void FileLogger_Start(logger_t *logger);
static void FileLogger_Log(logger_t *logger, char *msg);

const logger_methods_t file_logger_methods = {
	.start = FileLogger_Start,
	.log = FileLogger_Log,
};

void FileLogger_Init(file_logger_t *file_logger)
{
	if (file_logger)
		file_logger->super.methods = &file_logger_methods;
}

static void FileLogger_Start(logger_t *logger)
{
	file_logger_t *file_logger = (file_logger_t *)logger;
	file_logger->file = fopen("log_file.txt", "a");
	fprintf(file_logger->file, "New file logging session started ... \n");
}

static void FileLogger_Log(logger_t *logger, char *msg)
{
	file_logger_t *file_logger = (file_logger_t *)logger;
	fprintf(file_logger->file, "%s\n", msg);
}
