/*
 * Timer0_Program.c
 *
 *  Created on: Aug 21, 2022
 *      Author: Ahmed Aseel
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "Timer0_Private.h"
#include "Timer0_Config.h"
#include "Timer0_Interface.h"

/* Global pointer to callback functions in App.c */
void (*TIMER0_ISR_Ptr)(void) = NULL;

/*********************************** Functions Definition ***********************************/

/*******************************************************************************************/
void TIMER0_voidInitNormal(u8 Copy_u8ClkSelect)
{
	/* Timer0 Overflow Interrupt Enable */
	Set_Bit(TIMSK_REG, TOIE0);
	/* enable normal mode clear bits 3,6 */
	Clr_Bit(TCCR0_REG, WGM01);
	Clr_Bit(TCCR0_REG, WGM00);

	/* clear bits 2:0
	 * store Copy_u8ClkSelect in bits 2:0
	 */
	Clr_Bit(TCCR0_REG, CS00);
	Clr_Bit(TCCR0_REG, CS01);
	Clr_Bit(TCCR0_REG, CS02);
	TCCR0_REG |= Copy_u8ClkSelect;
}

/*******************************************************************************************/
void TIMER0_voidPreload(u8 Copy_u8Value)
{
	/* store preload value in TCNT0 */
	TCNT0_REG = Copy_u8Value;
}

/*******************************************************************************************/
void TIMER0_voidInitCTC(u8 Copy_u8Mode, u8 Copy_u8ClkSelect)
{
	/* Timer0 Output Compare Match Interrupt Enable */
	Set_Bit(TIMSK_REG, OCIE0);
	/* enable CTC mode clear bit 6
	 * set bit 3
	 */
	Set_Bit(TCCR0_REG, WGM01);
	Clr_Bit(TCCR0_REG, WGM00);

	/* clear bits 5,4
	 * store Copy_u8Mode in bits 5,4
	 */
	Clr_Bit(TCCR0_REG, COM00);
	Clr_Bit(TCCR0_REG, COM01);
	TCCR0_REG |= (Copy_u8Mode << COM00);

	/* clear bits 2:0
	 * store Copy_u8ClkSelect in bits 2:0
	 */
	Clr_Bit(TCCR0_REG, CS00);
	Clr_Bit(TCCR0_REG, CS01);
	Clr_Bit(TCCR0_REG, CS02);
	TCCR0_REG |= Copy_u8ClkSelect;
}

/*******************************************************************************************/
void TIMER0_voidSetOCR0Value(u8 Copy_u8Value)
{
	/* store value in OCR0 */
	OCR0_REG = Copy_u8Value;
}

/*******************************************************************************************/
void TIMER0_SetCallBack(void (*fptr)(void))
{
	TIMER0_ISR_Ptr = fptr;
}

/*******************************************************************************************/
								 /**** TIMER0 COMP VECTOR ****/
void __vector_10()__attribute__((signal));
void __vector_10()
{
	if(TIMER0_ISR_Ptr != 0)
	{
		/* Call Timer0 ISR back using function pointer */
		TIMER0_ISR_Ptr();
	}
}

/*******************************************************************************************/
								 /**** TIMER0 OVF VECTOR ****/
void __vector_11()__attribute__((signal));
void __vector_11()
{
	if(TIMER0_ISR_Ptr != 0)
	{
		/* Call Timer0 ISR back using function pointer */
		TIMER0_ISR_Ptr();
	}
}
/*******************************************************************************************/
