#ifndef	TIMER_DRIVER_H
#define TIMER_DRIVER_H

#include "stm32f4xx.h"

/*
 * User Define
 */


/*
 * TIMx_CR1
 */
#define CEN 	0
#define UDIS	1
#define URS		2


typedef struct
{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t RESERVED1;
	volatile uint32_t DIER;
	volatile uint32_t SR;
	volatile uint32_t EGR;
	volatile uint32_t RESERVED2;
	volatile uint32_t RESERVED3;
	volatile uint32_t RESERVED4;
	volatile uint32_t CNT;
	volatile uint32_t PSC;
	volatile uint32_t ARR;
} TIMx_Reg_t;

void Start_Timer(TIMx_Reg_t *pTIMx);
void Stop_Timer(TIMx_Reg_t *pTIMx);
void Set_Timer_Prescaler(TIMx_Reg_t *pTIMx, uint16_t prescaler);
void Set_Timer_Auto_Reload(TIMx_Reg_t *pTIMx, uint16_t reload_value);
void delay_ms(uint32_t time);
void Set_Timer_DMA_Interrupt(TIMx_Reg_t *pTIMx, uint8_t mode);

#endif /* TIMER_DRIVER_H */
