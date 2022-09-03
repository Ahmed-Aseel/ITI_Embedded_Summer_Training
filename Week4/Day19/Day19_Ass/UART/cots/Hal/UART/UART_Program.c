/*
 * UART_Program.c
 *
 *  Created on: Aug 24, 2022
 *      Author: Ahmed Aseel
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "UART_Private.h"
#include "UART_Interface.h"

/*********************************** Functions Definition ***********************************/

/*******************************************************************************************/
void UART_voidInit()
{
	u8 Copy_u8Var;

	/* Transmitter Enable */
	Set_Bit(UCSRB_REG, TXEN);
	/* Receiver Enable */
	Set_Bit(UCSRB_REG, RXEN);

	/* This Copy_u8Var to store changes in UBRRH_UCSRC_REG */
	Copy_u8Var = UBRRH_UCSRC_REG;
	/* Selects accessing the UCSRC REG */
	Set_Bit(Copy_u8Var, URSEL);

	/* Asynchronous Operation Mode */
	Clr_Bit(Copy_u8Var, UMSEL);

	/* Disabled Parity Mode */
	Clr_Bit(Copy_u8Var, UPM1);
	Clr_Bit(Copy_u8Var, UPM0);

	/* Stop Bit Select 1-bit */
	Clr_Bit(Copy_u8Var, USBS);

	/* Character Size 8-bits */
	Clr_Bit(UCSRB_REG, UCSZ2);
	Set_Bit(Copy_u8Var, UCSZ1);
	Set_Bit(Copy_u8Var, UCSZ0);

	/* Accessing UBRRH_UCSRC_REG in one cycle */
	UBRRH_UCSRC_REG = Copy_u8Var;

	/* Selects accessing the UBRRH REG */
	Clr_Bit(UBRRH_UCSRC_REG, URSEL);
	/* Select 9600 baud rate when freq = 8MHz */
	UBRRL_REG = 51; /* Low byte of UBRR REG */
	UBRRH_UCSRC_REG = 0; /* High byte of UBRR REG */
}

/*******************************************************************************************/
void UART_voidSendData(u8 Copy_u8Data)
{
	UDR_REG = Copy_u8Data;
	while(Read_Bit(UCSRA_REG, TXC) == 0)
	{
		Set_Bit(UCSRA_REG, TXC);
	}
}

/*******************************************************************************************/
u8 UART_u8RecieveData()
{
	while(Read_Bit(UCSRA_REG, RXC) == 0);
	return UDR_REG;
}
/*******************************************************************************************/
