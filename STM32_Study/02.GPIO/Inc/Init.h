#ifndef INIT_H
#define INIT_H

#include "rcc_driver.h"
#include "gpio_driver.h"

void Init(void);
void Init_Sysclk(void);
void Init_GPIO(void);
void Init_PeriClk_Enable(void);



#endif
