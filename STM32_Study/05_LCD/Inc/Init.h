#ifndef INIT_H
#define INIT_H

#include "rcc_driver.h"
#include "gpio_driver.h"
#include "timer_driver.h"
#include "flash_driver.h"
#include "i2c_driver.h"
#include "lcd_com.h"
#include "util.h"

void Init(void);
void Init_Sysclk(void);
void Init_GPIO(void);
void Init_PeriClk_Enable(void);
void Init_Timer(void);
void Init_Bus_Clock_Prescale(void);
void Init_I2C(void);

#endif
