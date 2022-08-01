#ifndef COMMAND_WRITE_FLASH_H
#define COMMAND_WRITE_FLASH_H

#include "command.h"
#include <stdint.h>

/// write flash command implements command interface
typedef struct 
{
	command_t super;
	uint32_t address;
	uint32_t data;
}command_write_flash_t;

void CommandWriteFlash_Init(command_write_flash_t* command, uint32_t address, uint32_t data);


#endif