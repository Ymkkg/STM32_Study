#ifndef	LCD_COM_H
#define LCD_COM_H

#include "timer_driver.h"
#include "i2c_driver.h"
#include "stm32f4xx.h"

/*
 * User Define
 */
#define LCD_ADDR    0x27

#define EN          1 << 2
#define BACKLIGHT   1 << 3





void LCD_Init_4Bit_Interface(void);
void LCD_Write_One_Data_Master_To_LCD(I2Cx_Reg_t *pI2Cx, uint8_t addr, uint8_t data);
void LCD_Write_Multiple_Data_Master_To_LCD(I2Cx_Reg_t *pI2Cx, uint8_t addr, uint8_t *data, uint8_t length);
void Cal_SDcard_Usage(uint8_t one, uint8_t ten, uint8_t total);

#endif /* LCD_COM_H */
