#ifndef Flash_CONTROLLER_H
#define Flash_CONTROLLER_H

#include <stdint.h>

void FlashController_Read(uint32_t address);
void FlashController_Write(uint32_t address, uint32_t data);

#endif