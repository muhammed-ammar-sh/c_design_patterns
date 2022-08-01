#include "command_write_flash.h"
#include "flash_controller.h"

static void CommandWriteFlash_Execute(command_t* command);

void CommandWriteFlash_Init(command_write_flash_t* command, uint32_t address, uint32_t data)
{
	if (command)
	{
		command->super.execute = CommandWriteFlash_Execute;
		command->address = address;
		command->data = data;
	}
}

static void CommandWriteFlash_Execute(command_t* command)
{
	command_write_flash_t* cmd = (command_write_flash_t*) command;
	FlashController_Write(cmd->address, cmd->data);
}
