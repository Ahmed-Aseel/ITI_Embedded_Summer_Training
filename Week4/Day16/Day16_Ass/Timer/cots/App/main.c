/*
 * main.c
 *
 *  Created on: Aug 16, 2022
 *      Author: Aseel
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Interface.h"
#include "GIE_Interface.h"
#include "Timer_Interface.h"
#include "avr/delay.h"

#define CLK_FREQ                1e6
#define TIK_TIME                1e-6
#define OVERFLOW_TIME           (256 * TIK_TIME)
#define OVERFLOW_NUM(req_time)  (req_time / (OVERFLOW_TIME))

void TIMER0_OVF_ISR(void)
{
	static u16 count = 0;
	// timer 1 sec
	if(count == 3097)
	{
		DIO_voidTogglePin(PORTA_ID, PIN0_ID);
		count = 0;
	}
	else
	{
		count++;
	}
}

void TIMER0_COMP_ISR(void)
{
	static u16 count = 0;
	// timer 1 sec
	if(count == 4000)
	{
		DIO_voidTogglePin(PORTB_ID, PIN3_ID);
		count = 0;
	}
	else
	{
		count++;
	}
}

int main()
{
/*
	u8 required_time = 1;
	f32 of_num = OVERFLOW_NUM(required_time);
	u8 preload = (of_num - (u32)of_num) * 256;
*/

	// enable global interrupt
	Global_INTR_Enable();
/*	TIMER0_voidInitNormal();
	TIMER0_voidPreload(preload);
	TIMER0_SetCallBack(TIMER0_OVF_ISR);
	DIO_voidSetPinDirection(PORTA_ID, PIN0_ID, PIN_OUTPUT_ID);*/

	TIMER0_voidInitCTC();
	TIMER0_voidSetOCR0Value(250);
	TIMER0_SetCallBack(TIMER0_COMP_ISR);
	DIO_voidSetPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT_ID);

	while(1);

	return 0;
}
