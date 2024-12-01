#include "rcc_driver.h"

RCC_Reg_t *pRCC = (RCC_Reg_t*)RCC_ADDR;


/*
 * clk_source = HSI, HSE, PLL
 */
void Enable_Sysclk_Input(uint8_t clk_source)
{

  switch(clk_source)
  {
    case HSI:
      pRCC->CR |= ON << HSION;
      break;

    case HSE:
      pRCC->CR |= ON << HSEON;
      break;

    case PLL:
      pRCC->CR |= ON << PLLON;
      break;

    default:
      break;
  }
}

/*
 * clk_source = HSI, HSE, PLL
 */
void Wait_Sysclk_Ready(uint8_t clk_source)
{
  switch(clk_source)
  {
    case HSI:
      while((pRCC->CR & 1 << HISRDY) == 0);
      break;

    case HSE:
      while((pRCC->CR & 1 << HSERDY) == 0);
      break;

    case PLL:
      while((pRCC->CR & 1 << PLLRDY) == 0);
      break;

    default:
      break;
  }
}

/*
 * clk_source = HSI, HSE, PLL
 */
void Set_Sysclk_Input(uint8_t clk_source)
{
  pRCC->CFGR |= clk_source << SW;

  while(((pRCC->CFGR & 0x0C) >> 2) != clk_source);
}

void Enable_AHB1_Peri_Clk(uint8_t peri, uint8_t en_dis)
{
	if(en_dis == ENABLE)
	{
		pRCC->AHB1ENR |= 1 << peri;
	}
	else
	{
		pRCC->AHB1ENR &= ~(1 << peri);
	}
}

void Enable_APB1_Peri_Clk(uint8_t peri, uint8_t en_dis)
{
	if(en_dis == ENABLE)
	{
		pRCC->APB1ENR |= 1 << peri;
	}
	else
	{
		pRCC->APB1ENR &= ~(1 << peri);
	}
}

void Set_Clk_Output2(uint8_t mco2_source, uint8_t prescaler)
{
	pRCC->CFGR |= prescaler << MCO2_PRE;
	pRCC->CFGR |= mco2_source << MCO2;
}

void Set_PLLClk(uint8_t pll_src, uint8_t div1, uint16_t mul, uint8_t div2)
{
	//clear reset value
	pRCC->PLLCFGR &= ~(0xffffffff);

	pRCC->PLLCFGR |= pll_src << PLLSRC;
	//4  -> 2MHz
	pRCC->PLLCFGR |= div1 << PLLM;
	//50 -> 100MHz
	pRCC->PLLCFGR |= mul << PLLN;
	//1  -> 25MHz
	pRCC->PLLCFGR |= div2 << PLLP;

//	pRCC->PLLCFGR |= 7 << 24;
}

/*
 * SYSCLK = 168MHz
 * APB1 <= 84MHz
 * APB2 <= 42MHz
 */
void Set_RCC_BUS_Frequency(void)
{
	//APB2 Max Clock 84MHz
	pRCC->CFGR |= AHB_DIV_2 << PPRE2;
	//APB1 Max Clock 42MHz
	pRCC->CFGR |= AHB_DIV_4 << PPRE1;
}

