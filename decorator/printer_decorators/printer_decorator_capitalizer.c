#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "printer_decorator_capitalizer.h"

static void Printer_Decorator_Capitalizer_Print(printer_t *printer, const char *str);

void Printer_Decorator_Capitalizer_Init(printer_decorator_capitalizer_t *dec_cap, printer_t *wrapped_printer)
{
	if (dec_cap)
	{
		dec_cap->decorator_super.printer_super.print_method = Printer_Decorator_Capitalizer_Print;
		dec_cap->decorator_super.wrapped_printer = wrapped_printer;
	}
}

///@brief capitalizes all characters in the received string then passes it to the wrapped printer
static void Printer_Decorator_Capitalizer_Print(printer_t *printer, const char *str)
{
	if (printer)
	{
		printer_decorator_capitalizer_t *dec_cap = (printer_decorator_capitalizer_t *)printer;
		if (dec_cap->decorator_super.wrapped_printer)
		{
			char * new_str = malloc(strlen(str) + 1 /*for '\0'*/);
			strcpy(new_str, str);

			for (size_t i = 0; new_str[i] != '\0'; i++)
			{
				new_str[i] = toupper(new_str[i]);
			}

			Printer_Print(dec_cap->decorator_super.wrapped_printer, new_str);
			free(new_str);
		}
	}
}