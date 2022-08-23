#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Interface.h"
#include "INTR_Private.h"
#include "INTR_Interface.h"
#include "INTR_Config.h"
#include "avr/delay.h"

// global pointer to function in App.c
void (*gfun_ptr0)(void) = 0;
void (*gfun_ptr1)(void) = 0;
void (*gfun_ptr2)(void) = 0;

void INTR_voidInit(u8 Copy_u8INTR_ID, u8 Copy_u8INTR_Sense)
{
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

void EXTI0_SetCallBack(void (*fptr)(void))
{
	gfun_ptr0 = fptr;
}

void __vector_1()__attribute__((signal));
void __vector_1()
{
	if(gfun_ptr0 != 0)
	{
		gfun_ptr0();
	}
}

void EXTI1_SetCallBack(void (*fptr)(void))
{
	gfun_ptr1 = fptr;
}

void __vector_2()__attribute__((signal));
void __vector_2()
{
	if(gfun_ptr1 != 0)
	{
		gfun_ptr1();
	}
}

void EXTI2_SetCallBack(void (*fptr)(void))
{
	gfun_ptr2 = fptr;
}

void __vector_3()__attribute__((signal));
void __vector_3()
{
	if(gfun_ptr2 != 0)
	{
		gfun_ptr2();
	}
}
