#include "Init.h"

void Init(void)
{
	Init_Sysclk();
	Init_GPIO();
}

void Init_Sysclk(void)
{
	//Set PLL Clk
#if SYSCLK == PLL
	Set_PLLClk(PLLSRC_HSE, 4, 80, 3);
	Enable_Sysclk_Input(HSE);
	Wait_Sysclk_Ready(HSE);
#endif

	//Set Sysclk
	Enable_Sysclk_Input(SYSCLK);
	Wait_Sysclk_Ready(SYSCLK);
	Set_Sysclk_Input(SYSCLK);

	//Set Peri Clk Enable
	Init_PeriClk_Enable();

	//Set Clock Output
	Set_Clk_Output2(MCO2_SYSCLK, DIV_5);
}

void Init_PeriClk_Enable(void)
{
	Enable_AHB1_Peri_Clk(GPIOCEN, ENABLE);
}

void Init_GPIO(void)
{
	Set_GPIO_Init_Config(GPIOC_ADDR, 9, MODE_ALTER, TYPE_PUSH_PULL, SPEED_LOW, PUPD_NO);
}
