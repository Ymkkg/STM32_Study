#include "lcd_com.h"

//LCD Character
uint8_t LCD_SPACE[2] = {0x2, 0x0};
uint8_t LCD_DiVIDE[2] = {0x2, 0xF};
uint8_t LCD_PERCENTAGE[2] = {0x2, 0x5};
uint8_t LCD_BLACK[2] = {0xF, 0xF};
uint8_t LCD_0[2] = {0x3, 0x0};
uint8_t LCD_1[2] = {0x3, 0x1};
uint8_t LCD_2[2] = {0x3, 0x2};
uint8_t LCD_3[2] = {0x3, 0x3};
uint8_t LCD_4[2] = {0x3, 0x4};
uint8_t LCD_5[2] = {0x3, 0x5};
uint8_t LCD_6[2] = {0x3, 0x6};
uint8_t LCD_7[2] = {0x3, 0x7};
uint8_t LCD_8[2] = {0x3, 0x8};
uint8_t LCD_9[2] = {0x3, 0x9};
uint8_t LCD_A[2] = {0x4, 0x1};
uint8_t LCD_B[2] = {0x4, 0x2};
uint8_t LCD_C[2] = {0x4, 0x3};
uint8_t LCD_D[2] = {0x4, 0x4};
uint8_t LCD_E[2] = {0x4, 0x5};
uint8_t LCD_F[2] = {0x4, 0x6};
uint8_t LCD_G[2] = {0x4, 0x7};
uint8_t LCD_H[2] = {0x4, 0x8};
uint8_t LCD_I[2] = {0x4, 0x9};
uint8_t LCD_J[2] = {0x4, 0xA};
uint8_t LCD_K[2] = {0x4, 0xB};
uint8_t LCD_L[2] = {0x4, 0xC};
uint8_t LCD_M[2] = {0x4, 0xD};
uint8_t LCD_N[2] = {0x4, 0xE};
uint8_t LCD_O[2] = {0x4, 0xF};
uint8_t LCD_P[2] = {0x5, 0x0};
uint8_t LCD_Q[2] = {0x5, 0x1};
uint8_t LCD_R[2] = {0x5, 0x2};
uint8_t LCD_S[2] = {0x5, 0x3};
uint8_t LCD_T[2] = {0x5, 0x4};
uint8_t LCD_U[2] = {0x5, 0x5};
uint8_t LCD_V[2] = {0x5, 0x6};
uint8_t LCD_W[2] = {0x5, 0x7};
uint8_t LCD_X[2] = {0x5, 0x8};
uint8_t LCD_Y[2] = {0x5, 0x9};
uint8_t LCD_Z[2] = {0x5, 0xA};
uint8_t LCD_a[2] = {0x6, 0x1};
uint8_t LCD_b[2] = {0x6, 0x2};
uint8_t LCD_c[2] = {0x6, 0x3};
uint8_t LCD_d[2] = {0x6, 0x4};
uint8_t LCD_e[2] = {0x6, 0x5};
uint8_t LCD_f[2] = {0x6, 0x6};
uint8_t LCD_g[2] = {0x6, 0x7};
uint8_t LCD_h[2] = {0x6, 0x8};
uint8_t LCD_i[2] = {0x6, 0x9};
uint8_t LCD_j[2] = {0x6, 0xA};
uint8_t LCD_k[2] = {0x6, 0xB};
uint8_t LCD_l[2] = {0x6, 0xC};
uint8_t LCD_m[2] = {0x6, 0xD};
uint8_t LCD_n[2] = {0x6, 0xE};
uint8_t LCD_o[2] = {0x6, 0xF};
uint8_t LCD_p[2] = {0x7, 0x0};
uint8_t LCD_q[2] = {0x7, 0x1};
uint8_t LCD_r[2] = {0x7, 0x2};
uint8_t LCD_s[2] = {0x7, 0x3};
uint8_t LCD_t[2] = {0x7, 0x4};
uint8_t LCD_u[2] = {0x7, 0x5};
uint8_t LCD_v[2] = {0x7, 0x6};
uint8_t LCD_w[2] = {0x7, 0x7};
uint8_t LCD_x[2] = {0x7, 0x8};
uint8_t LCD_y[2] = {0x7, 0x9};
uint8_t LCD_z[2] = {0x7, 0xA};

void LCD_Init_4Bit_Interface(void)
{
    //Set LCD Communication Protocol 8bit Mode to 4Bit Mode
    delay_ms(16);
    LCD_Write_One_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, 0x3);

    delay_ms(6);
    LCD_Write_One_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, 0x3);

    delay_ms(1);
    LCD_Write_One_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, 0x3);

    delay_ms(2);
    LCD_Write_One_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, 0x2);

    delay_ms(2);
    LCD_Write_One_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, 0x2);
    LCD_Write_One_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, 0xC);

    delay_ms(2);
    LCD_Write_One_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, 0x0);
    LCD_Write_One_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, 0x8);

    delay_ms(2);
    LCD_Write_One_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, 0x0);
    LCD_Write_One_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, 0x1);

    delay_ms(2);
    LCD_Write_One_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, 0x0);
    LCD_Write_One_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, 0x6);

    //Init LCD Screen
    delay_ms(2);
    LCD_Write_One_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, 0x0);
    LCD_Write_One_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, 0xC);

    LCD_Write_Multiple_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, LCD_S, sizeof(LCD_S));
    LCD_Write_Multiple_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, LCD_D, sizeof(LCD_D));
    LCD_Write_Multiple_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, LCD_c, sizeof(LCD_c));
    LCD_Write_Multiple_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, LCD_a, sizeof(LCD_a));
    LCD_Write_Multiple_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, LCD_r, sizeof(LCD_r));
    LCD_Write_Multiple_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, LCD_d, sizeof(LCD_d));

    LCD_Write_Multiple_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, LCD_SPACE, sizeof(LCD_SPACE));
    LCD_Write_Multiple_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, LCD_SPACE, sizeof(LCD_SPACE));


    LCD_Write_Multiple_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, LCD_0, sizeof(LCD_0));
    LCD_Write_Multiple_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, LCD_0, sizeof(LCD_0));
    LCD_Write_Multiple_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, LCD_DiVIDE, sizeof(LCD_DiVIDE));
    LCD_Write_Multiple_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, LCD_1, sizeof(LCD_1));
    LCD_Write_Multiple_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, LCD_0, sizeof(LCD_0));
    LCD_Write_Multiple_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, LCD_0, sizeof(LCD_0));
    LCD_Write_Multiple_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, LCD_PERCENTAGE, sizeof(LCD_PERCENTAGE));
}

/**
 * @brief Send One Data I2C Data From MCU to LCD
 * 
 * @param pI2Cx I2C 1~3
 * @param addr LCD Address
 * @param data Data value is DB7 ~ DB4, DB7~4 is shifted 4bit in function
 */
void LCD_Write_One_Data_Master_To_LCD(I2Cx_Reg_t *pI2Cx, uint8_t addr, uint8_t data)
{
    uint8_t data_temp;
    data_temp = data << 4 | BACKLIGHT | EN;
    I2C_Send_One_Data_Master_To_Slave(pI2Cx, addr, data_temp);
    data_temp &= ~(EN);
    I2C_Send_One_Data_Master_To_Slave(pI2Cx, addr, data_temp);
}

void LCD_Write_Multiple_Data_Master_To_LCD(I2Cx_Reg_t *pI2Cx, uint8_t addr, uint8_t *data, uint8_t length)
{
    uint8_t data_temp;

    while(length--)
    {
        data_temp = *data++ << 4 | BACKLIGHT | EN | 1 << 0;
        I2C_Send_One_Data_Master_To_Slave(pI2Cx, addr, data_temp);
        data_temp &= ~(EN);
        I2C_Send_One_Data_Master_To_Slave(pI2Cx, addr, data_temp);
    }
}

void Cal_SDcard_Usage(uint8_t one, uint8_t ten, uint8_t total)
{
    uint8_t* LCD_Char[10] = {LCD_0, LCD_1, LCD_2, LCD_3, LCD_4, LCD_5 ,LCD_6, LCD_7, LCD_8, LCD_9};
    uint8_t* LCD_Char2[2] = {LCD_SPACE, LCD_1};
    LCD_Write_One_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, 0x8);
    LCD_Write_One_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, 0x7);

    LCD_Write_Multiple_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, LCD_Char2[total/100], sizeof(LCD_0));
    LCD_Write_Multiple_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, LCD_Char[ten], sizeof(LCD_0));
    LCD_Write_Multiple_Data_Master_To_LCD((I2Cx_Reg_t*)I2C1_ADDR, LCD_ADDR, LCD_Char[one], sizeof(LCD_0));

}