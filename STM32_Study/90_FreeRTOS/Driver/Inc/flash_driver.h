#ifndef	FLASH_DRIVER_H
#define FLASH_DRIVER_H

#include "stm32f4xx.h"

/*
 * User Define
 */
#define SYSCLK_UNDER_30		0
#define SYSCLK_UNDER_60		1
#define SYSCLK_UNDER_90		2
#define SYSCLK_UNDER_120	3
#define SYSCLK_UNDER_150	4
#define SYSCLK_UNDER_168	5

typedef struct
{
	volatile uint32_t ACR;
	volatile uint32_t KEYR;
	volatile uint32_t OPTKEYR;
	volatile uint32_t SR;
	volatile uint32_t CR;
	volatile uint32_t OPTCR;
} FLASH_Reg_t;

void Set_Flash_Latency(uint8_t sysclk);

#endif /* FLASH_DRIVER_H */
