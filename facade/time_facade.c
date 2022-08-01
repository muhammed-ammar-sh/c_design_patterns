#include <time.h>
#include "time_facade.h"

void TimeFacade_GetFormattedCurrentDateTime(char * str, size_t str_max_len)
{
	time_t raw_time = time(NULL);
	struct tm *local_time = localtime(&raw_time);
	// Format date and time according to Turkish locale
	size_t s = strftime(str, str_max_len, "%d.%m.%Y - %X", local_time);
}
