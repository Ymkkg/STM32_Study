#include "Init.h"

void Init(void)
{
	Init_Sysclk();
	Init_GPIO();
	Init_Timer();
}

void Init_Sysclk(void)
{
	//Set PLL Clk
#if SYSCLK == PLL
	//Prevent Over Max BUS clock
	Init_Bus_Clock_Prescale();
	//168MHz
	Set_PLLClk(PLLSRC_HSE, 4, 168, 0);
	Enable_Sysclk_Input(HSE);
	Wait_Sysclk_Ready(HSE);

	//Set Flash Latency
	Set_Flash_Latency(SYSCLK_UNDER_168);
#endif

	//Set Sysclk
	Enable_Sysclk_Input(SYSCLK);
	Wait_Sysclk_Ready(SYSCLK);
	Set_Sysclk_Input(SYSCLK);

	//Set Peri Clk Enable
	Init_PeriClk_Enable();

	//Set Clock Output
//	Set_Clk_Output2(MCO2_SYSCLK, DIV_5);
}

void Init_PeriClk_Enable(void)
{
	Enable_AHB1_Peri_Clk(GPIOCEN, ENABLE);
	Enable_AHB1_Peri_Clk(GPIODEN, ENABLE);
	Enable_APB1_Peri_Clk(TIM6EN, ENABLE);
}

void Init_Bus_Clock_Prescale(void)
{
	Set_RCC_BUS_Frequency();
}

void Init_GPIO(void)
{
//	Set_GPIO_Init_Config((GPIOx_Reg_t*)GPIOC_ADDR, 9, MODE_ALTER, TYPE_PUSH_PULL, SPEED_LOW, PUPD_NO);
	Set_GPIO_Init_Config((GPIOx_Reg_t*)GPIOD_ADDR, 12, MODE_OUTPUT, TYPE_PUSH_PULL, SPEED_LOW, PUPD_NO);
	Set_GPIO_Init_Config((GPIOx_Reg_t*)GPIOD_ADDR, 13, MODE_OUTPUT, TYPE_PUSH_PULL, SPEED_LOW, PUPD_NO);
	Set_GPIO_Init_Config((GPIOx_Reg_t*)GPIOD_ADDR, 14, MODE_OUTPUT, TYPE_PUSH_PULL, SPEED_LOW, PUPD_NO);
	Set_GPIO_Init_Config((GPIOx_Reg_t*)GPIOD_ADDR, 15, MODE_OUTPUT, TYPE_PUSH_PULL, SPEED_LOW, PUPD_NO);
}

void Init_Timer(void)
{
//	Set_Timer_DMA_Interrupt((TIMx_Reg_t*)TIM6_ADDR, 1);
	//1MHz
	Set_Timer_Prescaler((TIMx_Reg_t*)TIM6_ADDR, 83);
	//1ms
	Set_Timer_Auto_Reload((TIMx_Reg_t*)TIM6_ADDR, 999);

}
