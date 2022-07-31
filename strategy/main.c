#include <stdio.h>

#include "map.h"
#include "map_printer_ordinary.h"
#include "map_printer_reversed.h"
#include "map_printer_shifter.h"

/**
 * The strategy pattern is a behavioral software design pattern that enables
 * selecting an algorithm at runtime. Instead of implementing a single
 * algorithm directly, code receives run-time instructions as to which in a
 * family of algorithms to use."
 * Wikipedia - Strategy Pattern.
 *
 * In this example we have "map" class, that has "Map_SetPrinter" method to
 * change the printing strategy at run time.
 * Each printing strategy is implemented at a separate module and decoupled
 * from the map class implementation.
 */

int main(void)
{
	map_t my_map;

	point_t point_array[50];

	Map_Init(&my_map, point_array, 50);
	point_t p;

	// Add some points to the map
	p.x = 0;
	p.y = 0;
	Map_AddPoint(&my_map, p);

	p.x = 2;
	p.y = 2;
	Map_AddPoint(&my_map, p);

	p.x = 5;
	p.y = 5;
	Map_AddPoint(&my_map, p);

	p.x = 8;
	p.y = 8;
	Map_AddPoint(&my_map, p);

	// Select the strategy at run time
	Map_SetPrinter(&my_map, MapPrinter_Ordinary_Print);
	Map_Print(&my_map);
	puts("\n");
	/*
	point   X       Y
	0       0       0
	1       2       2
	2       5       5
	3       8       8
	*/

	// Switch to another strategy at run time
	Map_SetPrinter(&my_map, MapPrinter_Reversed_Print);
	Map_Print(&my_map);
	puts("\n");
	/*
	point   X       Y
	3       8       8
	2       5       5
	1       2       2
	0       0       0
	*/

	// Switch to another strategy at run time
	Map_SetPrinter(&my_map, MapPrinter_Shifter_Print);
	Map_Print(&my_map);
	puts("\n");
	/*
	point   X       Y
	0       2       0
	1       4       2
	2       7       5
	3       10      8
	*/

	return 0;
}