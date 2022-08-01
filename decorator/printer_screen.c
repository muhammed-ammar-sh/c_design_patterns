#include <stdio.h>
#include "printer_screen.h"

static void Printer_Screen_Print(printer_t *printer, const char *str);

void Printer_Screen_Init(printer_screen_t *printer)
{
	if (printer)
	{
		printer->super.print_method = Printer_Screen_Print;
	}
}

static void Printer_Screen_Print(printer_t *printer, const char *str)
{
	(void *)printer; // unused argument
	printf("%s\n", str);
}