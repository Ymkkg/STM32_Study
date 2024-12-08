#include "i2c_driver.h"

/**
 * @brief I2C Peripheral Enable or Disable
 * 
 * @param pI2Cx I2C Module 1 ~ 3
 * @param en_di Enable or Disable
 */
void I2C_Set_Peri_Enable(I2Cx_Reg_t *pI2Cx , uint8_t en_di)
{
	if(en_di == ENABLE)
	{
		pI2Cx->CR1 |= 1 << PE;
	}
	else
	{
		pI2Cx->CR1 &= ~(1 << PE);
	}
}

/**
 * @brief Set I2C Peripheral Bus Clock
 * 
 * @param pI2Cx     I2C Module 1 ~ 3
 * @param peri_clk  2 ~ 50 MHz
 */
void I2C_Set_Peri_Clk(I2Cx_Reg_t *pI2Cx, uint8_t peri_clk)
{
	//Minimum Frequency is 2MHz, Maximum Frequency is 50MHz
	if(peri_clk <= 1)
	{
		peri_clk = 2;
	}
	else if(peri_clk >= 50)
	{
		peri_clk = 50;
	}

	pI2Cx->CR2 |= peri_clk << FREQ;
}

/**
 * @brief Set I2C Communication Clock
 * 
 * @param pI2Cx 	I2C Module 1 ~ 3
 * @param scl_clk 	100, 200, 400KHz
 */
void I2C_Set_SCL_Clk(I2Cx_Reg_t *pI2Cx, uint32_t scl_clk)
{
	uint32_t peri_clk = pI2Cx->CR2 & 0x3F;
	uint32_t ccr = (peri_clk * 500) / scl_clk;
	uint32_t trise = 0;

	pI2Cx->CCR |= ccr << 0;

	trise = peri_clk + 1;

	pI2Cx->TRISE = trise;
}

/**
 * @brief I2C Send Master to Slave
 * 
 * @param pI2Cx 	I2C Module 1 ~ 3
 * @param addr 		Slave Address
 * @param data 		Data
 * @param length 	Data Length
 */
void I2C_Send_Master_To_Slave(I2Cx_Reg_t *pI2Cx, uint8_t addr, uint8_t *data, uint8_t length)
{
	//1. Start Generation
	pI2Cx->CR1 |= 1 << START;
	while((pI2Cx->SR1 & (1 << SB)) == 0);

	//2. clear start bit and write address
	pI2Cx->SR1;
	pI2Cx->DR = ((addr << 1) | TRANSMITTER_MODE);
	while((pI2Cx->SR1 & (1 << ADDR)) == 0);

	//3. read SR1 and SR2 to clear addr bit
	pI2Cx->SR1;
	pI2Cx->SR2;

	//4. write data
	while(length--)
	{
		while((pI2Cx->SR1 & (1 << TXE)) == 0);
		pI2Cx->DR = *data++;
	}

	//5. close communication
	while((pI2Cx->SR1 & (1 << TXE)) == 0);
	while((pI2Cx->SR1 & (1 << BTF)) == 0);
	pI2Cx->CR1 |= 1 << STOP;
}

// void set_I2C_ACK_Enable(I2Cx_Reg_t *pI2Cx , uint8_t enordi)
// {
// 	if(enordi == ENABLE)
// 	{
// 		pI2Cx->CR1 |= 1 << ACK;
// 	}
// 	else
// 	{
// 		pI2Cx->CR1 &= ~(1 << ACK);
// 	}
// }

// void read_master_to_slave(I2Cx_Reg_t *pI2Cx, uint8_t addr, uint8_t *data, uint8_t length)
// {
// 	//1. Start Generation
// 	pI2Cx->CR1 |= 1 << START;
// 	while((pI2Cx->SR1 & 0x01) == 0);

// 	//2. clear start bit and write address
// 	pI2Cx->SR1;
// 	pI2Cx->DR = ((addr << 1) + RECEIVER_MODE);
// 	while((pI2Cx->SR1 & 0x02) == 0);
// 	//3. read SR1 and SR2 to clear addr bit
// 	pI2Cx->SR1;
// 	pI2Cx->SR2;
// //	while(pI2Cx->SR1 & 0x01 == 1);
// 	//4. write data
// 	while(length != 0)
// 	{
// 		pI2Cx->DR = *data;
// 		data++;
// 		length--;
// 		while((pI2Cx->SR1 & 0x80) == 0);
// 	}

// 	//5. close communication
// 	pI2Cx->CR1 |= 1 << STOP;
// }
// void send_master_to_LCD(I2Cx_Reg_t *pI2Cx, uint8_t addr, uint8_t *data, uint8_t length)
// {
// 	delay_ms(1);
// 	//1. Start Generation
// 	pI2Cx->CR1 |= 1 << START;
// 	while((pI2Cx->SR1 & 0x01) == 0);

// 	//2. clear start bit and write address
// 	pI2Cx->SR1;
// 	pI2Cx->DR = ((addr << 1) + WRITE);
// 	while((pI2Cx->SR1 & 0x02) == 0);
// 	//3. read SR1 and SR2 to clear addr bit
// 	pI2Cx->SR1;
// 	pI2Cx->SR2;
// //	while(pI2Cx->SR1 & 0x01 == 1);
// 	//4. write data
// 	//enable

// 	while(length != 0)
// 	{
// 		pI2Cx->DR = (*data | 0x0C);
// //		if(length > 1)
// //		{
// //			pI2Cx->DR = (*data | 0x0C);
// //		}
// //		else
// //		{
// //			pI2Cx->DR = (*data | 0x08);
// //		}
// 		data++;
// 		length--;
// 		while((pI2Cx->SR1 & 0x80) == 0);
// 		pI2Cx->DR = (*data | 0x08);
// 		while((pI2Cx->SR1 & 0x80) == 0);
// 	}
// //	pI2Cx->DR = (*data | 0x08);
// //	while((pI2Cx->SR1 & 0x80) == 0);
// 	//5. close communication
// 	pI2Cx->CR1 |= 1 << STOP;
// }

