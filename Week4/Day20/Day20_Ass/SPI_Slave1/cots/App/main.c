/*
 * main.c
 *
 *  Created on: Aug 25, 2022
 *      Author: Ahmed Aseel
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Interface.h"
#include "GIE_Interface.h"
#include "Timer0_Config.h"
#include "Timer0_Interface.h"
#include "SPI_Interface.h"

void TIMER0_COMP_ISR(void)
{
	static u16 count = 0;
	// timer 1 sec
	if(count == 4000)
	{
		/* Toggle led every 1 sec */
		DIO_voidTogglePin(PORTA_ID, PIN0_ID);
		/* Load OCR0 again */
		TIMER0_voidSetOCR0Value(250);
		/* Clear count */
		count = 0;
	}
	else
	{
		count++;
	}
}

int main()
{
	u8 data;

	/* Enable Global Interrupt */
	Global_INTR_Enable();

	/* Select slave mode */
	SPI_voidInit(SLAVE);

	DIO_voidSetPinDirection(SPI_PORT, SS, PIN_INPUT_ID);
	DIO_voidSetPinDirection(SPI_PORT, MOSI, PIN_INPUT_ID);
	DIO_voidSetPinDirection(SPI_PORT, MISO, PIN_OUTPUT_ID);
	DIO_voidSetPinDirection(SPI_PORT, SCK, PIN_INPUT_ID);

	TIMER0_SetCallBack(TIMER0_COMP_ISR);

	DIO_voidSetPinDirection(PORTA_ID, PIN0_ID, PIN_OUTPUT_ID);
	DIO_voidSetPinValue(PORTA_ID, PIN0_ID, PIN_LOW);

	/* Send latter B and read received data */
	data = SPI_u8Transciever('B');

	/* Check if the received data = latter S */
	if(data == 'S')
	{
		TIMER0_voidInitCTC(OC0_DISCONNECTED, CLK_8);
		TIMER0_voidSetOCR0Value(250);
	}

	while(1);

	return 0;
}

