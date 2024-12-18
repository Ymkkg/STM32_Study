#include "timer_driver.h"

TIMx_Reg_t *pTIM6 = (TIMx_Reg_t*)TIM6_ADDR;

void Start_Timer(TIMx_Reg_t *pTIMx)
{
	pTIMx->CNT = 0;
	pTIMx->CR1 |= 1 << CEN;
}

void Stop_Timer(TIMx_Reg_t *pTIMx)
{
	pTIMx->CR1 &= ~(1 << CEN);
}

void Set_Timer_Prescaler(TIMx_Reg_t *pTIMx, uint16_t prescaler)
{
	pTIMx->PSC = prescaler;
}

void Set_Timer_Auto_Reload(TIMx_Reg_t *pTIMx, uint16_t reload_value)
{
	pTIMx->ARR = reload_value;
}

void delay_ms(uint32_t time)
{
	Start_Timer(pTIM6);
	for(uint32_t i=0; i<time; i++)
	{
		pTIM6->SR &= ~(1 << 0);
		while((pTIM6->SR & 0x01) == 0);
	}
	Stop_Timer(pTIM6);
}

void Set_Timer_DMA_Interrupt(TIMx_Reg_t *pTIMx, uint8_t mode)
{
	pTIMx->DIER |= 1 << 0;
}
