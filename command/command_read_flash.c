#include "command_read_flash.h"
#include "flash_controller.h"

static void CommandReadFlash_Execute(command_t* command);

void CommandReadFlash_Init(command_read_flash_t* command, uint32_t address)
{
	if (command)
	{
		command->super.execute = CommandReadFlash_Execute;
		command->address = address;
	}
}

static void CommandReadFlash_Execute(command_t* command)
{
	command_read_flash_t* cmd = (command_read_flash_t*) command;
	FlashController_Read(cmd->address);
}