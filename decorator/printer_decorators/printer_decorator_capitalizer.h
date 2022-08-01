#ifndef PRINTER_DECORATOR_CAPITALIZER_H
#define PRINTER_DECORATOR_CAPITALIZER_H

#include "printer_decorator_interface.h"

/// decorator capitalizer implements printer decorator interface
typedef struct 
{
	printer_decorator_t decorator_super;
}printer_decorator_capitalizer_t;

void Printer_Decorator_Capitalizer_Init(printer_decorator_capitalizer_t *dec_cap, printer_t *wrapped_printer);

#endif
