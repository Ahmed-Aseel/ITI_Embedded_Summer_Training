/*
 * Timer2_Program.c
 *
 *  Created on: Aug 24, 2022
 *      Author: Ahmed Aseel
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "Timer2_Private.h"
#include "Timer2_Config.h"
#include "Timer2_Interface.h"

/* Global pointer to callback functions in App.c */
void (*TIMER2_ISR_Ptr)(void) = NULL;

/*********************************** Functions Definition ***********************************/

/*******************************************************************************************/
void TIMER2_voidInitNormal(u8 Copy_u8ClkSelect)
{
	/* Timer2 Overflow Interrupt Enable */
	Set_Bit(TIMSK_REG, TOIE2);
	/* enable normal mode clear bits 3,6 */
	Clr_Bit(TCCR2_REG, WGM21);
	Clr_Bit(TCCR2_REG, WGM20);

	/* clear bits 2:0
	 * store Copy_u8ClkSelect in bits 2:0
	 */
	Clr_Bit(TCCR2_REG, CS20);
	Clr_Bit(TCCR2_REG, CS21);
	Clr_Bit(TCCR2_REG, CS22);
	TCCR2_REG |= Copy_u8ClkSelect;
}

/*******************************************************************************************/
void TIMER2_voidPreload(u8 Copy_u8Value)
{
	/* store preload value in TCNT2 */
	TCNT2_REG = Copy_u8Value;
}

/*******************************************************************************************/
void TIMER2_voidInitCTC(u8 Copy_u8Mode, u8 Copy_u8ClkSelect)
{
	/* Timer2 Output Compare Match Interrupt Enable */
	Set_Bit(TIMSK_REG, OCIE2);
	/* enable CTC mode clear bit 6
	 * set bit 3
	 */
	Set_Bit(TCCR2_REG, WGM21);
	Clr_Bit(TCCR2_REG, WGM20);

	/* clear bits 5,4
	 * store Copy_u8Mode in bits 5,4
	 */
	Clr_Bit(TCCR2_REG, COM20);
	Clr_Bit(TCCR2_REG, COM21);
	TCCR2_REG |= (Copy_u8Mode << COM20);

	/* clear bits 2:0
	 * store Copy_u8ClkSelect in bits 2:0
	 */
	Clr_Bit(TCCR2_REG, CS20);
	Clr_Bit(TCCR2_REG, CS21);
	Clr_Bit(TCCR2_REG, CS22);
	TCCR2_REG |= Copy_u8ClkSelect;

}

/*******************************************************************************************/
void TIMER0_voidSetOCR2Value(u8 Copy_u8Value)
{
	/* store value in OCR2 */
	OCR2_REG = Copy_u8Value;
}

/*******************************************************************************************/
void TIMER2_SetCallBack(void (*fptr)(void))
{
	TIMER2_ISR_Ptr = fptr;
}

/*******************************************************************************************/
								 /**** TIMER2 COMP VECTOR ****/
void __vector_4()__attribute__((signal));
void __vector_4()
{
	if(TIMER2_ISR_Ptr != 0)
	{
		/* Call Timer2 ISR back using function pointer */
		TIMER2_ISR_Ptr();
	}
}

/*******************************************************************************************/
								 /**** TIMER2 OVF VECTOR ****/
void __vector_5()__attribute__((signal));
void __vector_5()
{
	if(TIMER2_ISR_Ptr != 0)
	{
		/* Call Timer2 ISR back using function pointer */
		TIMER2_ISR_Ptr();
	}
}
/*******************************************************************************************/
