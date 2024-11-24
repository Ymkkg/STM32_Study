#include "gpio_driver.h"

void Set_GPIO_Init_Config(GPIOx_Reg_t *pGPIOx, uint8_t pin_num, uint8_t mode, uint8_t type, uint8_t speed, uint8_t pupd)
{
	Set_GPIO_Mode(pGPIOx, mode, pin_num);
	Set_GPIO_Output_Type(pGPIOx, type, pin_num);
	Set_GPIO_Output_Speed(pGPIOx, speed, pin_num);
	Set_GPIO_PUPD(pGPIOx, pupd, pin_num);
}

void Set_GPIO_Mode(GPIOx_Reg_t *pGPIOx, uint8_t mode, uint8_t pin_num)
{
	pGPIOx->MODER |= (mode << (pin_num * 2));
}

void Set_GPIO_Output_Type(GPIOx_Reg_t *pGPIOx, uint8_t type, uint8_t pin_num)
{
	pGPIOx->OTYPER |= (type << pin_num);
}

void Set_GPIO_Output_Speed(GPIOx_Reg_t *pGPIOx, uint8_t speed, uint8_t pin_num)
{
	pGPIOx->OSPEEDR |= (speed << (pin_num * 2));
}

void Set_GPIO_PUPD(GPIOx_Reg_t *pGPIOx, uint8_t pupd, uint8_t pin_num)
{
	pGPIOx->PUPDR |= (pupd << (pin_num * 2));
}

void Set_GPIO_Output(GPIOx_Reg_t *pGPIOx, uint8_t output, uint8_t pin_num)
{
	if(output == OUTPUT_SET)
	{
		pGPIOx->BSRR |= 1 << pin_num;
	}
	else
	{
		//OUTPUT_RESET
		pGPIOx->BSRR |= 1 << (pin_num + 16);
	}

}
