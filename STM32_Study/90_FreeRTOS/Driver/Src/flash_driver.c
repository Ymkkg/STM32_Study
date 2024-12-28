#include "flash_driver.h"

FLASH_Reg_t *pFLASH = (FLASH_Reg_t*)FLASH_ADDR;

void Set_Flash_Latency(uint8_t sysclk)
{
	pFLASH->ACR |= sysclk;
}
