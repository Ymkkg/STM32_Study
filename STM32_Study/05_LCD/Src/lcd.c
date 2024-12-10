#include "lcd.h"

void LCD_Init_4Bit_Interface(void)
{
    delay_ms(16);

    I2C_Send_Master_To_Slave((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, )

}

void LCD_Send_Master_To_LCD(void)
{
    I2C_Send_Master_To_Slave()
}