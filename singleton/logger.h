#include <stdio.h>

typedef struct
{
	FILE *file;
} logger_t;

logger_t *Logger_GetInstance(void);
void Logger_Write(logger_t *logger, char *str);
