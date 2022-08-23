/*
 * Timer0_Program.c
 *
 *  Created on: Aug 21, 2022
 *      Author: metro
 */
#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Interface.h"
#include "Timer0_Interface.h"
#include "Timer0_Private.h"

// global pointer to function in App.c
void (*gtimer0_ptr)(void) = 0;

void TIMER0_voidInitNormal()
{
	/* Timer0 Overflow Interrupt Enable */
	set_bit(TIMSK_REG, PIN0_ID);
	/* enable normal mode clear bits 6,3 */
	TCCR0_REG &= 0b10110111;
	/* clk select 1/8
	 * clear bits 2:0
	 * set bit 1
	 */
	TCCR0_REG &= 0xF1;
	TCCR0_REG |= 0x02;
}

void TIMER0_voidPreload(u8 Copy_u8Value)
{
	/* store preload value in TCNT0 */
	TCNT0_REG = Copy_u8Value;
}

void TIMER0_voidInitCTC()
{
	/* Timer0 Output Compare Match Interrupt Enable */
	set_bit(TIMSK_REG, PIN1_ID);
	/* enable CTC mode clear bit 6
	 * set bit 3
	 */
	TCCR0_REG &= 0b10110111;
	TCCR0_REG |= 0x08;

	/* non-PWM Mode Normal port operation, OC0 disconnected.
	 * clear bits 5, 4
	 */
	TCCR0_REG &= 0xCF;

	/* clk select 1/8
	 * clear bits 2:0
	 * set bit 1
	 */
	TCCR0_REG &= 0xF1;
	TCCR0_REG |= 0x02;
}

void TIMER0_voidSetOCR0Value(u8 Copy_u8Value)
{
	/* store value in OCR0 */
	OCR0_REG = Copy_u8Value;
}

void TIMER0_SetCallBack(void (*fptr)(void))
{
	gtimer0_ptr = fptr;
}

void __vector_10()__attribute__((signal));
void __vector_10()
{
	if(gtimer0_ptr != 0)
	{
		gtimer0_ptr();
	}
}

void __vector_11()__attribute__((signal));
void __vector_11()
{
	if(gtimer0_ptr != 0)
	{
		gtimer0_ptr();
	}
}
