#ifndef PRINTER_DECORATOR_REPLACER_H
#define PRINTER_DECORATOR_REPLACER_H

#include "printer_decorator_interface.h"

/// decorator replacer implements printer decorator interface
typedef struct
{
	printer_decorator_t decorator_super;
	char old_char;
	char new_char;
} printer_decorator_replacer_t;

void Printer_Decorator_Replacer_Init(printer_decorator_replacer_t *dec_rep, printer_t *wrapped_printer,
										char old_char, char new_char);

#endif
