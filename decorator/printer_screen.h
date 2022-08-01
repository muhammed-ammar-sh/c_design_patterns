#ifndef PRINTER_SCREEN_H
#define PRINTER_SCREEN_H

#include "printer_interface.h"

/// printer screen implements printer interface
typedef struct
{
	printer_t super;
} printer_screen_t;

void Printer_Screen_Init(printer_screen_t *printer);

#endif
