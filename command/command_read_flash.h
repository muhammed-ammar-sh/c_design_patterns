#ifndef COMMAND_READ_FLASH_H
#define COMMAND_READ_FLASH_H

#include "command.h"
#include <stdint.h>

/// read flash command implements command interface
typedef struct 
{
	command_t super;
	uint32_t address;
}command_read_flash_t;

void CommandReadFlash_Init(command_read_flash_t* command, uint32_t address);


#endif