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
      while((pRCC->CR & 1 << PLLRDY) == 1);
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


