#include "command.h"
#include "command_read_flash.h"
#include "command_write_flash.h"

/**
 * "The command pattern is a behavioral design pattern in which an object is used
 * to encapsulate all information needed to perform an action or trigger an event
 * at a later time."
 * Wikipedia - Command Pattern
 * 
 * In this example flash writing/reading commands are created and initialized
 * with the required information (address, data to write) then added to an
 * array/queue but not executed. Later, the commands are executed in order.
 *  
 */

int main(void)
{
	command_t *commands[4]; // or queue

	// in client, new command requests are received
	command_write_flash_t c1;
	CommandWriteFlash_Init(&c1, 0, 100);
	commands[0] = (command_t *)&c1; // or add to queue

	command_write_flash_t c2;
	CommandWriteFlash_Init(&c2, 3, 200);
	commands[1] = (command_t *)&c2; // or add to queue

	command_read_flash_t c3;
	CommandReadFlash_Init(&c3, 3);
	commands[2] = (command_t *)&c3; // or add to queue

	command_read_flash_t c4;
	CommandReadFlash_Init(&c4, 0);
	commands[3] = (command_t *)&c4; // or add to queue

	/*************************************************/

	// later in invoker
	for (int i = 0; i < 4; i++)
		Command_Execute(commands[i]);

	return 0;
}