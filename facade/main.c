#include <stdio.h>
#include "time_facade.h"

/**
 * Facade is a structural design pattern that provides a simplified interface 
 * to a library, a framework, or any other complex set of classes.
 * Refactoring Guru - Facade Pattern
 *  
 * In this example time_facade module provides a simplified interface to the
 * standard time.h library and implements a method that fills a string with
 * a formatted current date and time.
 */

int main(void)
{
	char str [50];
	TimeFacade_GetFormattedCurrentDateTime(str, sizeof str);
	printf("%s\n", str);

	return 0;
}