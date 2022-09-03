/*
 * SPI_Program.c
 *
 *  Created on: Aug 25, 2022
 *      Author: Ahmed Aseel
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "SPI_Private.h"
#include "SPI_Interface.h"

/*********************************** Functions Definition ***********************************/

/*******************************************************************************************/
void SPI_voidInit(u8 Copy_u8SPIMode)
{
	/* SPI Enable */
	Set_Bit(SPCR_REG, SPE);

	/* The LSB of the data word is transmitted first */
	Set_Bit(SPCR_REG, DORD);

	/* Select SPI Mode */
	switch(Copy_u8SPIMode)
	{
	case SLAVE: // slave mode
		Clr_Bit(SPCR_REG, MSTR);
		break;

	case MASTER: // master mode
		Set_Bit(SPCR_REG, MSTR);
		break;
	}

	/* Rising ---> Leading , Falling ---> Trailing */
	Clr_Bit(SPCR_REG, CPOL);

	/* Sample First Setup Last */
	Clr_Bit(SPCR_REG, CPHA);

	/* Select SCK freq = 1/8 * Fosc */
	Set_Bit(SPCR_REG, SPR0);
	Clr_Bit(SPCR_REG, SPR1);
	Set_Bit(SPSR_REG, SPI2X);
}

/*******************************************************************************************/
/* This function used to send and
 * receive data at the same time
 */
u8 SPI_u8Transciever(u8 Copy_u8Data)
{
	/* To send data load data
	 * in SPI Data Register
	 */
	SPDR_REG = Copy_u8Data;

	/* To read received data
	 * return SPI Data Register
	 */
	while(Read_Bit(SPSR_REG, SPIF) == 0);
	return SPDR_REG;
}
/*******************************************************************************************/
