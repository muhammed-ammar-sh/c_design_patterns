#include "screen_logger.h"

static void ScreenLogger_Start(logger_t *logger);
static void ScreenLogger_Log(logger_t *logger, char *msg);

const logger_methods_t screen_logger_methods = {
	.start = ScreenLogger_Start,
	.log = ScreenLogger_Log,
};

void ScreenLogger_Init(screen_logger_t *screen_logger)
{
	if (screen_logger)
		screen_logger->super.methods = &screen_logger_methods;
}

static void ScreenLogger_Start(logger_t *logger)
{
	screen_logger_t *screen_logger = (screen_logger_t *)logger;
	printf("New screen logging session started ... \n");
}

static void ScreenLogger_Log(logger_t *logger, char *msg)
{
	screen_logger_t *screen_logger = (screen_logger_t *)logger;
	printf("%s\n", msg);
}
