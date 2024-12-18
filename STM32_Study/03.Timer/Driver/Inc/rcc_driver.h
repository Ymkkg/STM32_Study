#ifndef RCC_DRIVER_H
#define RCC_DRIVER_H

#include "stm32f4xx.h"

/*
 * User Define
 */
#define SYSCLK		PLL

#define HSI			0
#define HSE			1
#define PLL			2

#define MCO2_SYSCLK	0
#define MCO2_PLLI2S	1
#define MCO2_HSE	2
#define MCO2_PLL	3

#define DIV_2		4
#define DIV_3		5
#define DIV_4		6
#define DIV_5		7

#define PLLSRC_HSI	0
#define PLLSRC_HSE	1

#define AHB_DIV_2	4
#define AHB_DIV_4	5
#define AHB_DIV_8	6
#define AHB_DIV_16	7

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
#define SW			0
#define SWS			1
#define PPRE1		10
#define PPRE2		13
#define MCO1		21
#define MCO1_PRE	24
#define MCO2_PRE	27
#define MCO2		30

/*
 * RCC_AHB1ENR
 */
#define GPIOAEN		0
#define GPIOBEN		1
#define GPIOCEN		2
#define GPIODEN		3

/*
 * RCC_APB1ENR
 */
#define TIM6EN		4
#define TIM7EN		5

/*
 * RCC_PLLCFGR
 */
#define PLLM		0
#define PLLN		6
#define PLLP		16
#define PLLSRC		22



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
void Enable_AHB1_Peri_Clk(uint8_t peri, uint8_t en_dis);
void Enable_APB1_Peri_Clk(uint8_t peri, uint8_t en_dis);
void Set_Clk_Output2(uint8_t mco2_source, uint8_t prescaler);
void Set_PLLClk(uint8_t pll_src, uint8_t div1, uint16_t mul, uint8_t div2);
void Set_RCC_BUS_Frequency(void);

#endif	/* RCC_DRIVER_H */
