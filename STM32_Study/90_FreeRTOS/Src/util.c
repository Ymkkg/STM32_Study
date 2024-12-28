#include "util.h"

void LED_Blink(void)
{
    Set_GPIO_Output((GPIOx_Reg_t*)GPIOD_ADDR, OUTPUT_SET, 12);
    delay_ms(100);
    Set_GPIO_Output((GPIOx_Reg_t*)GPIOD_ADDR, OUTPUT_RESET, 12);
    delay_ms(100);
    Set_GPIO_Output((GPIOx_Reg_t*)GPIOD_ADDR, OUTPUT_SET, 13);
    delay_ms(100);
    Set_GPIO_Output((GPIOx_Reg_t*)GPIOD_ADDR, OUTPUT_RESET, 13);
    delay_ms(100);
    Set_GPIO_Output((GPIOx_Reg_t*)GPIOD_ADDR, OUTPUT_SET, 14);
    delay_ms(100);
    Set_GPIO_Output((GPIOx_Reg_t*)GPIOD_ADDR, OUTPUT_RESET, 14);
    delay_ms(100);
    Set_GPIO_Output((GPIOx_Reg_t*)GPIOD_ADDR, OUTPUT_SET, 15);
    delay_ms(100);
    Set_GPIO_Output((GPIOx_Reg_t*)GPIOD_ADDR, OUTPUT_RESET, 15);
    delay_ms(100);
}