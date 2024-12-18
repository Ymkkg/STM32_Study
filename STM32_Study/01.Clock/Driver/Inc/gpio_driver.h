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

void Set_GPIO_Init_Config(GPIOx_Reg_t *pGPIOx, uint8_t pin_num, uint8_t mode, uint8_t type, uint8_t speed, uint8_t pupd);
void Set_GPIO_Mode(GPIOx_Reg_t *pGPIOx, uint8_t mode, uint8_t pin_num);
void Set_GPIO_Output_Type(GPIOx_Reg_t *pGPIOx, uint8_t type, uint8_t pin_num);
void Set_GPIO_Output_Speed(GPIOx_Reg_t *pGPIOx, uint8_t speed, uint8_t pin_num);
void Set_GPIO_PUPD(GPIOx_Reg_t *pGPIOx, uint8_t pupd, uint8_t pin_num);


#endif /* GPIO_DRIVER_H */
