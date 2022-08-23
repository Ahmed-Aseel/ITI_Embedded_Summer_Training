/*
 * Timer1_Program.c
 *
 *  Created on: Aug 22, 2022
 *      Author: metro
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Interface.h"
#include "Timer1_Private.h"
#include "Timer1_Interface.h"

void TIMER1_voidInit()
{
	/* select Fast PWM mode */
	clear_bit(TCCR1A_REG, PIN0_ID);
	set_bit(TCCR1A_REG, PIN1_ID);
	set_bit(TCCR1B_REG, PIN3_ID);
	set_bit(TCCR1B_REG, PIN4_ID);

	/* select non inverting mode */
	clear_bit(TCCR1A_REG, PIN4_ID);
	clear_bit(TCCR1A_REG, PIN6_ID);
	set_bit(TCCR1A_REG, PIN5_ID);
	set_bit(TCCR1A_REG, PIN7_ID);

	/* prescaler 1/8 */
	clear_bit(TCCR1B_REG, PIN0_ID);
	set_bit(TCCR1B_REG, PIN1_ID);
	clear_bit(TCCR1B_REG, PIN2_ID);

	ICR1_REG = 20000;
}

void TIMER1_voidSetOCR1AValue(u16 Copy_u16Value)
{
	/* store value in OCR1A */
	OCR1A_REG = Copy_u16Value;
}
