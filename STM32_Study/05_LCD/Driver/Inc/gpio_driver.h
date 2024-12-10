#ifndef	GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include "stm32f4xx.h"

/*
 * User Define
 */
#define MODE_INPUT		0
#define MODE_OUTPUT		1
#define MODE_ALTER		2
#define MODE_ANALOG		3

#define TYPE_PUSH_PULL	0
#define TYPE_OPEN_DRAIN 1

#define OUTPUT_RESET	0
#define OUTPUT_SET		1

/*
 * Speed Max Value
 * LOW       -> 8MHz
 * MID       -> 50MHz
 * HIGH      -> 100MHz
 * VERY_HIGH -> 180MHZ
 */
#define SPEED_LOW		0
#define SPEED_MID		1
#define SPEED_HIGH		2
#define SPEED_VERY_HIGH 3

#define PUPD_NO			0
#define PUPD_PULL_UP	1
#define PUPD_PULL_DOWN	2

/**
 * @brief AFR Describe
 * AF0 (system)
 * AF1 (TIM1/TIM2)
 * AF2 (TIM3..5)
 * AF3 (TIM8..11)
 * AF4 (I2C1..3)
 * AF5 (SPI1/SPI2)
 * AF6 (SPI3)
 * AF7 (USART1..3)
 * AF8 (USART4..6)
 * AF9 (CAN1/CAN2, TIM12..14)
 * AF10 (OTG_FS, OTG_HS)
 * AF11 (ETH)
 * AF12 (FSMC, SDIO, OTG_HS(1) )
 * AF13 (DCMI)
 * AF14
 * AF15 (EVENTOUT)
 */
#define AF0		0
#define AF1		1
#define AF2		2
#define AF3		3
#define AF4		4
#define AF5		5
#define AF6		6
#define AF7		7
#define AF8		8
#define AF9		9
#define AF10	10
#define AF11	11
#define AF12	12
#define AF13	13
#define AF14	14
#define AF15	15



typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFRL;
	volatile uint32_t AFRH;
} GPIOx_Reg_t;

void Set_GPIO_Init_Config(GPIOx_Reg_t *pGPIOx, uint8_t pin_num, uint8_t mode, uint8_t type, uint8_t speed, uint8_t pupd, uint8_t afr);
void Set_GPIO_Mode(GPIOx_Reg_t *pGPIOx, uint8_t mode, uint8_t pin_num);
void Set_GPIO_Output_Type(GPIOx_Reg_t *pGPIOx, uint8_t type, uint8_t pin_num);
void Set_GPIO_Output_Speed(GPIOx_Reg_t *pGPIOx, uint8_t speed, uint8_t pin_num);
void Set_GPIO_PUPD(GPIOx_Reg_t *pGPIOx, uint8_t pupd, uint8_t pin_num);
void Set_GPIO_Output(GPIOx_Reg_t *pGPIOx, uint8_t output, uint8_t pin_num);
void GPIO_Set_AFR(GPIOx_Reg_t *pGPIOx, uint8_t pin, uint8_t AFR);

#endif /* GPIO_DRIVER_H */
