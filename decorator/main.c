#include "printer_screen.h"
#include "printer_decorators/printer_decorator_capitalizer.h"
#include "printer_decorators/printer_decorator_replacer.h"

/**
 * The decorator pattern allows us to "wrap" an object that provides core functionality
 * with other objects that alter this functionality. Any object that uses the decorated
 * object will interact with it in exactly the same way as if it were undecorated."
 * Python 3 Object-oriented Programming - Second Edition, Dusty Phillips.
 * 
 * In this example a printer screen object is wrapped with a capitalizer decorator so all
 * strings that are passed to the capitalizer object, all of its characters will be capitalized
 * first then will passed to the wrapped printer screen object.
 * 
 * Furthermore, capitalizer decorator object is also wrapped with a replacer decorator too,
 * so all strings that are passed to the replacer object will be modified by replacing 
 * some of its characters first, then they will be passed to the wrapped capitalizer object.
 * 
 */

int main(void)
{

	printer_screen_t printer1;
	Printer_Screen_Init(&printer1);

	printer_decorator_capitalizer_t dec1;
	Printer_Decorator_Capitalizer_Init(&dec1, (printer_t *)&printer1);

	printer_decorator_replacer_t dec2;
	Printer_Decorator_Replacer_Init(&dec2, (printer_t *)&dec1, ' ', '-'); //replaces white spaces with -

	Printer_Print((printer_t *)&dec2, "hello decorator pattern !!!");
	// HELLO-DECORATOR-PATTERN-!!!

	return 0;
}