/*
 * INTR_Program.c
 *
 *  Created on: Aug 23, 2022
 *      Author: Ahmed Aseel
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "INTR_Private.h"
#include "INTR_Interface.h"
#include "INTR_Config.h"
#include "avr/delay.h"

/* Global pointer to callback functions in App.c */
void (*INTR0_ISR_Ptr)(void) = NULL;
void (*INTR1_ISR_Ptr)(void) = NULL;
void (*INTR2_ISR_Ptr)(void) = NULL;

/*********************************** Functions Definition ***********************************/

/*******************************************************************************************/
void INTR_voidInit(u8 Copy_u8INTR_ID, u8 Copy_u8INTR_Sense)
{
	switch(Copy_u8INTR_ID)
	{
	case INTR0_ID: // INTR0
	{
		// enable INTR0
		Set_Bit(GICR_REG, INT0);
		switch(Copy_u8INTR_Sense)
		{
		case LOW_LEVEL: // 00
			Clr_Bit(MCUCR_REG, ISC01);
			Clr_Bit(MCUCR_REG, ISC00);
			break;

		case ANY_CHANGE: // 01
			Clr_Bit(MCUCR_REG, ISC01);
			Set_Bit(MCUCR_REG, ISC00);
			break;

		case FALLING_EDGE: // 10
			Set_Bit(MCUCR_REG, ISC01);
			Clr_Bit(MCUCR_REG, ISC00);
			break;

		case RISING_EDGE: // 11
			Set_Bit(MCUCR_REG, ISC01);
			Set_Bit(MCUCR_REG, ISC00);
			break;
		}

		/* set intr0 pin as direction input */
		DIO_voidSetPinDirection(INTR0_PORT, INTR0_PIN, PIN_INPUT);
		break;
	}

	case INTR1_ID: // INTR1
	{
		// enable INTR1
		Set_Bit(GICR_REG, INT1);
		switch(Copy_u8INTR_Sense)
		{
		case LOW_LEVEL: // 00
			Clr_Bit(MCUCR_REG, ISC11);
			Clr_Bit(MCUCR_REG, ISC10);
			break;

		case ANY_CHANGE: // 01
			Clr_Bit(MCUCR_REG, ISC11);
			Set_Bit(MCUCR_REG, ISC10);
			break;

		case FALLING_EDGE: // 10
			Set_Bit(MCUCR_REG, ISC11);
			Clr_Bit(MCUCR_REG, ISC10);
			break;

		case RISING_EDGE : // 11
			Set_Bit(MCUCR_REG, ISC11);
			Set_Bit(MCUCR_REG, ISC10);
			break;
		}

		/* set intr1 pin as direction input */
		DIO_voidSetPinDirection(INTR1_PORT, INTR1_PIN, PIN_INPUT);
		break;
	}

	case INTR2_ID: // INTR2
	{
		// enable INTR2
		Set_Bit(GICR_REG, INT2);
		switch(Copy_u8INTR_Sense)
		{
		/* there is two cases only in INTR2 falling & rising */
		case FALLING_EDGE:
			Clr_Bit(MCUCSR_REG, ISC2);
			break;

		case RISING_EDGE :
			Set_Bit(MCUCSR_REG, ISC2);
			break;
		}

		/* set intr2 pin as direction input */
		DIO_voidSetPinDirection(INTR2_PORT, INTR2_PIN, PIN_INPUT);
		break;
	}
	}
}

/*******************************************************************************************/
void INTR0_SetCallBack(void (*fptr)(void))
{
	INTR0_ISR_Ptr = fptr;
}

/*******************************************************************************************/
								/**** INTR0 VECTOR ****/
void __vector_1()__attribute__((signal));
void __vector_1()
{
	if(INTR0_ISR_Ptr != NULL)
	{
		/* Call INTR0 ISR back using function pointer */
		INTR0_ISR_Ptr();
	}
}

/*******************************************************************************************/
void INTR1_SetCallBack(void (*fptr)(void))
{
	INTR1_ISR_Ptr = fptr;
}

/*******************************************************************************************/
								/**** INTR1 VECTOR ****/
void __vector_2()__attribute__((signal));
void __vector_2()
{
	if(INTR1_ISR_Ptr != NULL)
	{
		/* Call INTR1 ISR back using function pointer */
		INTR1_ISR_Ptr();
	}
}

/*******************************************************************************************/
void INTR2_SetCallBack(void (*fptr)(void))
{
	INTR2_ISR_Ptr = fptr;
}

/*******************************************************************************************/
								/**** INTR2 VECTOR ****/
void __vector_3()__attribute__((signal));
void __vector_3()
{
	if(INTR2_ISR_Ptr != NULL)
	{
		/* Call INTR2 ISR back using function pointer */
		INTR2_ISR_Ptr();
	}
}
/*******************************************************************************************/
