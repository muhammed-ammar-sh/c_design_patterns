#include <stdlib.h>
#include <string.h>
#include "printer_decorator_replacer.h"

static void Printer_Decorator_Replacer_Print(printer_t *printer, const char *str);

void Printer_Decorator_Replacer_Init(printer_decorator_replacer_t *dec_rep, printer_t *wrapped_printer,
									 char old_char, char new_char)
{
	if (dec_rep)
	{
		dec_rep->decorator_super.printer_super.print_method = Printer_Decorator_Replacer_Print;
		dec_rep->decorator_super.wrapped_printer = wrapped_printer;
		dec_rep->old_char = old_char;
		dec_rep->new_char = new_char;
	}
}

///@brief replaces some characters in the received string then passes it to the wrapped printer
static void Printer_Decorator_Replacer_Print(printer_t *printer, const char *str)
{
	if (printer)
	{
		printer_decorator_replacer_t *dec_rep = (printer_decorator_replacer_t *)printer;
		if (dec_rep->decorator_super.wrapped_printer)
		{
			char *new_str = malloc(strlen(str) + 1 /*for '\0'*/);
			strcpy(new_str, str);

			for (size_t i = 0; new_str[i] != '\0'; i++)
			{
				if (new_str[i] == dec_rep->old_char)
				{
					new_str[i] = dec_rep->new_char;
				}
			}

			Printer_Print(dec_rep->decorator_super.wrapped_printer, new_str);
			free(new_str);
		}
	}
}