#ifndef PRINTER_DECORATOR_INTERFACE_H
#define PRINTER_DECORATOR_INTERFACE_H

#include "../printer_interface.h"

/// printer decorator inherits printer interface and has a pointer to the printer
/// that will be decorated (all operations to this object will be delegated)
typedef struct
{
	printer_t printer_super;
	printer_t *wrapped_printer;
} printer_decorator_t;


#endif