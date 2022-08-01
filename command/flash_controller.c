#include "flash_controller.h"
#include <stdio.h>

#define MAX_LINE_SIZE	50

/** Flash is emulated as a text file where each line represents a specific address **/

///@brief a write a unsigned integer data to a specific address in the flash
void FlashController_Write(uint32_t address, uint32_t data)
{
	// use address as line number
	FILE *file = fopen("FLASH.txt", "r");
	FILE *temp_file = fopen("FLASH_temp.txt", "w");
	char line[MAX_LINE_SIZE];

	for(uint32_t i = 0; i < address; i++)
	{
		if (fgets(line, MAX_LINE_SIZE, file) == NULL)
		{
			line[0] = '\n';
			line[1] = '\0';
		}
		fputs(line, temp_file);
	}
	fprintf(temp_file, "%d\n", data);
	fgets(line, MAX_LINE_SIZE, file);
	while(fgets(line, MAX_LINE_SIZE, file) != NULL)
	{
		fputs(line, temp_file);
	}
	fclose(file);
	fclose(temp_file);
	remove("FLASH.txt");
	rename("FLASH_temp.txt", "Flash.txt");
}

void FlashController_Read(uint32_t address)
{
	// use address as line number
	FILE *file = fopen("FLASH.txt", "r");
	char line[MAX_LINE_SIZE];
	uint32_t line_counter = 0;
	while (fgets(line, MAX_LINE_SIZE, file) != NULL)
	{
		if (line_counter == address)
		{
			printf("Flash data in address 0x%x is: %s\n", address, line);
			fclose(file);
			return;
		}
		line_counter++;
	}
	fclose(file);
}