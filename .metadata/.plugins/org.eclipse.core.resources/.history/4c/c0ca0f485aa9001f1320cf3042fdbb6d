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

void Set_Clk_Output2(uint8_t mco2_source, uint8_t prescaler)
{
	pRCC->CFGR |= prescaler << MCO2_PRE;
	pRCC->CFGR |= mco2_source << MCO2;
}

void Set_PLLClk(uint8_t pll_src, uint8_t m, uint8_t n, uint8_t p)
{
	//clear reset value
	pRCC->PLLCFGR &= ~(0xffff);

	pRCC->PLLCFGR |= pll_src << PLLSRC;
	//4  -> 2MHz
	pRCC->PLLCFGR |= m << PLLM;
	//50 -> 100MHz
	pRCC->PLLCFGR |= n << PLLN;
	//1  -> 25MHz
	pRCC->PLLCFGR |= p << PLLP;
}

