#ifndef STM32F4XX_H
#define STM32F4XX_H

#include <stdint.h>
#include "rcc_driver.h"
#include "gpio_driver.h"

/*
 * User Define
 */
#define ON		1
#define OFF		0
#define ENABLE  1
#define DISABLE 0

#define SET_1BIT(pos)    |= 1 << pos 
#define RESET_1BIT(pos)  &= ~(1 << pos) 

/*
 * Bus Address
 */
#define AHB1_ADDR		0x40020000

#define APB1_ADDR		0x40000000

/*
 * Peripheral Address
 */
#define RCC_ADDR		(AHB1_ADDR + 0x3800)

#define GPIOA_ADDR		(AHB1_ADDR + 0x0000)
#define GPIOB_ADDR		(AHB1_ADDR + 0x0400)
#define GPIOC_ADDR		(AHB1_ADDR + 0x0800)
#define GPIOD_ADDR		(AHB1_ADDR + 0x0C00)

#define FLASH_ADDR		(AHB1_ADDR + 0x3C00)

#define TIM6_ADDR		(APB1_ADDR + 0x1000)
#define TIM7_ADDR		(APB1_ADDR + 0x1400)

#define I2C1_ADDR       (APB1_ADDR + 0x5400)















#endif
