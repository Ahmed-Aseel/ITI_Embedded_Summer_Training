#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Interface.h"
#include "INTR_Private.h"
#include "INTR_Interface.h"
#include "INTR_Config.h"
#include "avr/delay.h"

void INTR_voidInit(u8 Copy_u8INTR_ID, u8 Copy_u8INTR_Sense)
{
	// enable global interrupt
	set_bit(SREG_REG, GIE);

	switch(Copy_u8INTR_ID)
	{
	case INTR0_ID: // INTR0
	{
		// enable INTR0
		set_bit(GICR_REG, INTR0_BIT);
		switch(Copy_u8INTR_Sense)
		{
		case LOW_LEVEL   : clear_bit(MCUCR_REG, ISC01); clear_bit(MCUCR_REG, ISC00); break; // 00
		case ANY_CHANGE  : clear_bit(MCUCR_REG, ISC01); set_bit(MCUCR_REG, ISC00);   break; // 01
		case FALLING_EDGE: set_bit(MCUCR_REG, ISC01);   clear_bit(MCUCR_REG, ISC00); break; // 10
		case RISING_EDGE : set_bit(MCUCR_REG, ISC01);   set_bit(MCUCR_REG, ISC00);   break; // 11
		}

		break;
	}

	case INTR1_ID: // INTR1
	{
		// enable INTR1
		set_bit(GICR_REG, INTR1_BIT);
		switch(Copy_u8INTR_Sense)
		{
		case LOW_LEVEL   : clear_bit(MCUCR_REG, ISC11); clear_bit(MCUCR_REG, ISC10); break;  // 00
		case ANY_CHANGE  : clear_bit(MCUCR_REG, ISC11); set_bit(MCUCR_REG, ISC10);   break;  // 01
		case FALLING_EDGE: set_bit(MCUCR_REG, ISC11);   clear_bit(MCUCR_REG, ISC10); break;  // 10
		case RISING_EDGE : set_bit(MCUCR_REG, ISC11);   set_bit(MCUCR_REG, ISC10);   break;  // 11
		}

		break;
	}

	case INTR2_ID: // INTR2
	{
		// enable INTR2
		set_bit(GICR_REG, INTR2_BIT);
		switch(Copy_u8INTR_Sense)
		{
		/* there is two cases only in INTR2 falling & rising */
		case FALLING_EDGE: clear_bit(MCUCSR_REG, ISC2);  break;
		case RISING_EDGE : set_bit(MCUCSR_REG, ISC2);    break;
		}

		break;
	}
	}

	/* set all interrupt MC pins as direction input */
	DIO_voidSetPinDirection(PORTD_ID, INTR0_PIN, PIN_INPUT_ID);
	DIO_voidSetPinDirection(PORTD_ID, INTR1_PIN, PIN_INPUT_ID);
	DIO_voidSetPinDirection(PORTB_ID, INTR2_PIN, PIN_INPUT_ID);
}

void __vector_1()__attribute__((signal));
void __vector_1()
{
	DIO_voidSetPinValue(PORTA_ID, PIN0_ID, PIN_HIGH);
	_delay_ms(500);
}

void __vector_2()__attribute__((signal));
void __vector_2()
{
	DIO_voidSetPinValue(PORTA_ID, PIN1_ID, PIN_HIGH);
	_delay_ms(500);
}

void __vector_3()__attribute__((signal));
void __vector_3()
{
	DIO_voidSetPinValue(PORTA_ID, PIN2_ID, PIN_HIGH);
	_delay_ms(500);
}
