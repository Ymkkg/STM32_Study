#include "Init.h"

void Init(void)
{
	Init_Sysclk();
	Init_Timer();
	Init_I2C();
	Init_GPIO();
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
	//I2C
	Enable_AHB1_Peri_Clk(GPIOBEN, ENABLE);
	Enable_APB1_Peri_Clk(I2C1EN, ENABLE);

	Enable_AHB1_Peri_Clk(GPIOCEN, ENABLE);
	//LED
	Enable_AHB1_Peri_Clk(GPIODEN, ENABLE);
	//Delay
	Enable_APB1_Peri_Clk(TIM6EN, ENABLE);
}

void Init_Bus_Clock_Prescale(void)
{
	Set_RCC_BUS_Frequency();
}

void Init_GPIO(void)
{
//	Set_GPIO_Init_Config((GPIOx_Reg_t*)GPIOC_ADDR, 9, MODE_ALTER, TYPE_PUSH_PULL, SPEED_LOW, PUPD_NO);
	//LED
	Set_GPIO_Init_Config((GPIOx_Reg_t*)GPIOD_ADDR, 12, MODE_OUTPUT, TYPE_PUSH_PULL, SPEED_LOW, PUPD_NO, AF0);
	Set_GPIO_Init_Config((GPIOx_Reg_t*)GPIOD_ADDR, 13, MODE_OUTPUT, TYPE_PUSH_PULL, SPEED_LOW, PUPD_NO, AF0);
	Set_GPIO_Init_Config((GPIOx_Reg_t*)GPIOD_ADDR, 14, MODE_OUTPUT, TYPE_PUSH_PULL, SPEED_LOW, PUPD_NO, AF0);
	Set_GPIO_Init_Config((GPIOx_Reg_t*)GPIOD_ADDR, 15, MODE_OUTPUT, TYPE_PUSH_PULL, SPEED_LOW, PUPD_NO, AF0);

	/**
	 * PB7 -> I2C1_SDA
	 * PB8 -> I2C1_SCL
	 */
	Set_GPIO_Init_Config((GPIOx_Reg_t*)GPIOB_ADDR, 8, MODE_ALTER, TYPE_OPEN_DRAIN, SPEED_LOW, PUPD_PULL_UP, AF4);
	Set_GPIO_Init_Config((GPIOx_Reg_t*)GPIOB_ADDR, 7, MODE_ALTER, TYPE_OPEN_DRAIN, SPEED_LOW, PUPD_PULL_UP, AF4);
}

void Init_Timer(void)
{
//	Set_Timer_DMA_Interrupt((TIMx_Reg_t*)TIM6_ADDR, 1);
	//1MHz
	Set_Timer_Prescaler((TIMx_Reg_t*)TIM6_ADDR, 83);
	//1ms
	Set_Timer_Auto_Reload((TIMx_Reg_t*)TIM6_ADDR, 999);
}

void Init_I2C(void)
{
	// 1. Set Peripheral Input Clock
	I2C_Set_Peri_Clk((I2Cx_Reg_t*)I2C1_ADDR, 42);

	// 2. Configure Clock Control register and rise time register
	I2C_Set_SCL_Clk((I2Cx_Reg_t*)I2C1_ADDR, I2C_SCL_CLOCK_100KHZ);

	// 3. Enable I2C Peripheral
	I2C_Set_Peri_Enable((I2Cx_Reg_t*)I2C1_ADDR, ENABLE);
}