#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Private.h"
#include "DIO_Interface.h"

void DIO_voidSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PINID, u8 Copy_u8PINDIR)
{
	if(Copy_u8PINDIR == PIN_OUTPUT_ID) // Output
	{
		switch(Copy_u8PortID)
		{
		case PORTA_ID: // port A
		set_bit(DDRA_REG, Copy_u8PINID);
		break;

		case PORTB_ID: // port B
		set_bit(DDRB_REG, Copy_u8PINID);
		break;

		case PORTC_ID: // port C
		set_bit(DDRC_REG, Copy_u8PINID);
		break;

		case PORTD_ID:	// port D
		set_bit(DDRD_REG, Copy_u8PINID);
		break;

		}
	}

	else if(Copy_u8PINDIR == PIN_INPUT_ID) // Input
	{
		switch(Copy_u8PortID)
		{
		case PORTA_ID: // port A
		clear_bit(DDRA_REG, Copy_u8PINID);
		break;

		case PORTB_ID: // port B
		clear_bit(DDRB_REG, Copy_u8PINID);
		break;

		case PORTC_ID: // port C
		clear_bit(DDRC_REG, Copy_u8PINID);
		break;

		case PORTD_ID:	// port D
		clear_bit(DDRD_REG, Copy_u8PINID);
		break;

		}		
	}
}

void DIO_voidSetPinValue(u8 Copy_u8PortID, u8 Copy_u8PINID, u8 Copy_u8PINValue)
{
	if(Copy_u8PINValue == PIN_HIGH) // High
	{
		switch(Copy_u8PortID)
		{
		case PORTA_ID: // port A
		set_bit(PORTA_REG, Copy_u8PINID);
		break;

		case PORTB_ID: // port B
		set_bit(PORTB_REG, Copy_u8PINID);
		break;

		case PORTC_ID: // port C
		set_bit(PORTC_REG, Copy_u8PINID);
		break;

		case PORTD_ID:	// port D
		set_bit(PORTD_REG, Copy_u8PINID);
		break;

		}
	}

	else if(Copy_u8PINValue == PIN_LOW) // Low
	{
		switch(Copy_u8PortID)
		{
		case PORTA_ID: // port A
		clear_bit(PORTA_REG, Copy_u8PINID);
		break;

		case PORTB_ID: // port B
		clear_bit(PORTB_REG, Copy_u8PINID);
		break;

		case PORTC_ID: // port C
		clear_bit(PORTC_REG, Copy_u8PINID);
		break;

		case PORTD_ID:	// port D
		clear_bit(PORTD_REG, Copy_u8PINID);
		break;

		}		
	}	
}

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
