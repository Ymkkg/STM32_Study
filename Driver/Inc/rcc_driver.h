#ifndef RCC_DRIVER_H
#define RCC_DRIVER_H

#include "stm32f4xx.h"

/*
 * User Define
 */
#define HSI		0
#define HSE		1
#define PLL		2

/*
 * RCC_CR
 */
#define HSION		0
#define HISRDY		1
#define HSEON		16
#define HSERDY		17
#define PLLON		24
#define PLLRDY		25

/*
 * RCC_CFGR
 */
#define SW		0
#define SWS		1



typedef struct
{
    volatile uint32_t	CR;
    volatile uint32_t	PLLCFGR;
    volatile uint32_t	CFGR;
    volatile uint32_t	CIR;
    volatile uint32_t	AHB1RSTR;
    volatile uint32_t	AHB2RSTR;
    volatile uint32_t	AHB3RSTR;
    volatile uint32_t	RESERVED1;
    volatile uint32_t	APB1RSTR;
    volatile uint32_t	APB2RSTR;
    volatile uint32_t	RESERVED2;
    volatile uint32_t	RESERVED3;
    volatile uint32_t	AHB1ENR;
    volatile uint32_t	AHB2ENR;
    volatile uint32_t	AHB3ENR;
    volatile uint32_t	RESERVED4;
    volatile uint32_t	APB1ENR;
    volatile uint32_t	APB2ENR;
    volatile uint32_t	RESERVED5;
    volatile uint32_t	RESERVED6;
    volatile uint32_t	AHB1LPENR;
    volatile uint32_t	AHB2LPENR;
    volatile uint32_t	AHB3LPENR;
    volatile uint32_t	RESERVED7;
    volatile uint32_t	APB1LPENR;
    volatile uint32_t	APB2LPENR;
    volatile uint32_t	RESERVED8;
    volatile uint32_t	RESERVED9;
    volatile uint32_t	BDCR;
    volatile uint32_t	CSR;
    volatile uint32_t	RESERVED10;
    volatile uint32_t	RESERVED11;
    volatile uint32_t	SSCGR;
    volatile uint32_t	PLLI2SCFGR;
    volatile uint32_t	PLLSAICFGR;
    volatile uint32_t	DCKCFGR;
} RCC_Reg_t;


void Enable_Sysclk_Input(uint8_t clk_source);
void Wait_Sysclk_Ready(uint8_t clk_source);
void Set_Sysclk_Input(uint8_t clk_source);

#endif	/* RCC_DRIVER_H */
