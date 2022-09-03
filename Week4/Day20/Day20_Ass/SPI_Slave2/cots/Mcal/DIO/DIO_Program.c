/*
 * DIO_Program.c
 *
 *  Created on: Aug 23, 2022
 *      Author: Ahmed Aseel
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Private.h"
#include "DIO_Interface.h"

/***************************** Functions Definition *****************************/

/*******************************************************************************/
void DIO_voidSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PINID, u8 Copy_u8PINDIR)
{
	if(Copy_u8PINDIR == PIN_OUTPUT_ID) // Output
	{
		switch(Copy_u8PortID)
		{
		case PORTA_ID: // port A
			Set_Bit(DDRA_REG, Copy_u8PINID);
			break;

		case PORTB_ID: // port B
			Set_Bit(DDRB_REG, Copy_u8PINID);
			break;

		case PORTC_ID: // port C
			Set_Bit(DDRC_REG, Copy_u8PINID);
			break;

		case PORTD_ID:	// port D
			Set_Bit(DDRD_REG, Copy_u8PINID);
			break;
		}
	}

	else if(Copy_u8PINDIR == PIN_INPUT_ID) // Input
	{
		switch(Copy_u8PortID)
		{
		case PORTA_ID: // port A
			Clr_Bit(DDRA_REG, Copy_u8PINID);
			break;

		case PORTB_ID: // port B
			Clr_Bit(DDRB_REG, Copy_u8PINID);
			break;

		case PORTC_ID: // port C
			Clr_Bit(DDRC_REG, Copy_u8PINID);
			break;

		case PORTD_ID:	// port D
			Clr_Bit(DDRD_REG, Copy_u8PINID);
			break;
		}		
	}
}

/*******************************************************************************/
void DIO_voidSetPinValue(u8 Copy_u8PortID, u8 Copy_u8PINID, u8 Copy_u8PINValue)
{
	if(Copy_u8PINValue == PIN_HIGH) // High
	{
		switch(Copy_u8PortID)
		{
		case PORTA_ID: // port A
			Set_Bit(PORTA_REG, Copy_u8PINID);
			break;

		case PORTB_ID: // port B
			Set_Bit(PORTB_REG, Copy_u8PINID);
			break;

		case PORTC_ID: // port C
			Set_Bit(PORTC_REG, Copy_u8PINID);
			break;

		case PORTD_ID:	// port D
			Set_Bit(PORTD_REG, Copy_u8PINID);
			break;
		}
	}

	else if(Copy_u8PINValue == PIN_LOW) // Low
	{
		switch(Copy_u8PortID)
		{
		case PORTA_ID: // port A
			Clr_Bit(PORTA_REG, Copy_u8PINID);
			break;

		case PORTB_ID: // port B
			Clr_Bit(PORTB_REG, Copy_u8PINID);
			break;

		case PORTC_ID: // port C
			Clr_Bit(PORTC_REG, Copy_u8PINID);
			break;

		case PORTD_ID:	// port D
			Clr_Bit(PORTD_REG, Copy_u8PINID);
			break;
		}		
	}	
}

/*******************************************************************************/
u8 DIO_u8GetPinValue(u8 Copy_u8PortID, u8 Copy_u8PINID)
{
	u8 PinVal;
	switch(Copy_u8PortID)
	{
	case PORTA_ID: // port A
		PinVal = Read_Bit(PINA_REG, Copy_u8PINID);
		break;

	case PORTB_ID: // port B
		PinVal = Read_Bit(PINB_REG, Copy_u8PINID);
		break;

	case PORTC_ID: // port C
		PinVal = Read_Bit(PINC_REG, Copy_u8PINID);
		break;

	case PORTD_ID:	// port D
		PinVal = Read_Bit(PIND_REG, Copy_u8PINID);
		break;
	}

	return PinVal;
}

/*******************************************************************************/
void DIO_voidTogglePin(u8 Copy_u8PortID, u8 Copy_u8PINID)
{
	switch(Copy_u8PortID)
	{
	case PORTA_ID: // port A
		Toggle_Bit(PORTA_REG, Copy_u8PINID);
		break;

	case PORTB_ID: // port B
		Toggle_Bit(PORTB_REG, Copy_u8PINID);
		break;

	case PORTC_ID: // port C
		Toggle_Bit(PORTC_REG, Copy_u8PINID);
		break;

	case PORTD_ID:	// port D
		Toggle_Bit(PORTD_REG, Copy_u8PINID);
		break;
	}
}

/*******************************************************************************/
void DIO_voidSetPortDirection(u8 Copy_u8PortID, u8 Copy_u8PORTDIR)
{
	switch(Copy_u8PortID)
	{
	case PORTA_ID: // port A
		DDRA_REG = Copy_u8PORTDIR;
		break;

	case PORTB_ID: // port B
		DDRB_REG = Copy_u8PORTDIR;
		break;

	case PORTC_ID: // port C
		DDRC_REG = Copy_u8PORTDIR;
		break;

	case PORTD_ID:	// port D
		DDRD_REG = Copy_u8PORTDIR;
		break;
	}
}

/*******************************************************************************/
void DIO_voidSetPortValue(u8 Copy_u8PortID, u8 Copy_u8PORTValue)
{
	switch(Copy_u8PortID)
	{
	case PORTA_ID: // port A
		PORTA_REG = Copy_u8PORTValue;
		break;

	case PORTB_ID: // port B
		PORTB_REG = Copy_u8PORTValue;
		break;

	case PORTC_ID: // port C
		PORTC_REG = Copy_u8PORTValue;
		break;

	case PORTD_ID:	// port D
		PORTD_REG = Copy_u8PORTValue;
		break;
	}
}
/*******************************************************************************/
