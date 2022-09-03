/*
 * Timer1_Program.c
 *
 *  Created on: Aug 23, 2022
 *      Author: Ahmed Aseel
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "Timer1_Private.h"
#include "Timer1_Config.h"
#include "Timer1_Interface.h"

/*********************************** Functions Definition ***********************************/

/*******************************************************************************************/
void TIMER1_voidInit()
{
	/* select Fast PWM mode */
	Clr_Bit(TCCR1A_REG, WGM10);
	Set_Bit(TCCR1A_REG, WGM11);
	Set_Bit(TCCR1B_REG, WGM12);
	Set_Bit(TCCR1B_REG, WGM13);

	/* select non inverting mode */
	Clr_Bit(TCCR1A_REG, COM1B0);
	Clr_Bit(TCCR1A_REG, COM1A0);
	Set_Bit(TCCR1A_REG, COM1B1);
	Set_Bit(TCCR1A_REG, COM1A1);

	/* prescaler 1/8 */
	Clr_Bit(TCCR1B_REG, CS10);
	Set_Bit(TCCR1B_REG, CS11);
	Clr_Bit(TCCR1B_REG, CS12);

	ICR1_REG = 20000;
}

/*******************************************************************************************/
void TIMER1_voidSetOCR1AValue(u16 Copy_u16Value)
{
	/* store value in OCR1A */
	OCR1A_REG = Copy_u16Value;
}
/*******************************************************************************************/
