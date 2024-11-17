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

/*
 * Bus Address
 */
#define AHB1_ADDR		0x40020000


/*
 * Peripheral Address
 */
#define RCC_ADDR		(RCC_Reg_t*)(AHB1_ADDR + 0x3800)

#define GPIOA_ADDR		(GPIOx_Reg_t*)(AHB1_ADDR + 0x0000)
#define GPIOB_ADDR		(GPIOx_Reg_t*)(AHB1_ADDR + 0x0400)
#define GPIOC_ADDR		(GPIOx_Reg_t*)(AHB1_ADDR + 0x0800)
#define GPIOD_ADDR		(GPIOx_Reg_t*)(AHB1_ADDR + 0x0C00)

















#endif
