#ifndef PRINTER_INTERFACE_H
#define PRINTER_INTERFACE_H

typedef struct printer_st printer_t;

struct printer_st
{
	void (*print_method)(printer_t *printer, const char *str);
};

static inline void Printer_Print(printer_t *printer, const char *str)
{
	if (printer && printer->print_method)
		printer->print_method(printer, str);
}

#endif
