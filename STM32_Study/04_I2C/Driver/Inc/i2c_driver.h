#ifndef	i2C_DRIVER_H
#define i2C_DRIVER_H

#include "stm32f4xx.h"

/*
 * User Define
 */
#define I2C_SCL_CLOCK_100KHZ	100
#define I2C_SCL_CLOCK_200KHZ	200
#define I2C_SCL_CLOCK_400KHZ	400

#define TRANSMITTER_MODE		0
#define RECEIVER_MODE			1

/**
 * @brief I2C_CR1
 */
#define PE      0
#define START   8
#define STOP    9

/**
 * @brief I2C_CR2
 */
#define FREQ    0



typedef struct
{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t OAR1;
	volatile uint32_t OAR2;
	volatile uint32_t DR;
	volatile uint32_t SR1;
	volatile uint32_t SR2;
	volatile uint32_t CCR;
	volatile uint32_t TRISE;
	volatile uint32_t FLTR;
} I2Cx_Reg_t;

/**
 * Function
 */
void I2C_Set_Peri_Enable(I2Cx_Reg_t *pI2Cx , uint8_t en_di);
void I2C_Set_Peri_Clk(I2Cx_Reg_t *pI2Cx, uint8_t peri_clk);
void I2C_Set_SCL_Clk(I2Cx_Reg_t *pI2Cx, uint32_t scl_clk);
void I2C_Send_Master_To_Slave(I2Cx_Reg_t *pI2Cx, uint8_t addr, uint8_t *data, uint8_t length);


#endif /* i2C_DRIVER_H */
