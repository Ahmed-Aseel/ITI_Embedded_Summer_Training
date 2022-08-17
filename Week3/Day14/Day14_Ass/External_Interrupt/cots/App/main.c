/*
 * main.c
 *
 *  Created on: Aug 16, 2022
 *      Author: Aseel
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Interface.h"
#include "INTR_Config.h"
#include "INTR_Interface.h"
#include "avr/delay.h"

int main()
{
	/* activate INTR0 with any change interrupt sense */
	INTR_voidInit(INTR0_ID, ANY_CHANGE);
	/* activate INTR1 with rising edge interrupt sense */
	INTR_voidInit(INTR1_ID, RISING_EDGE);
	/* activate INTR2 with falling edge interrupt sense */
	INTR_voidInit(INTR2_ID, FALLING_EDGE);

	/* set pins 0,1,2 at portA direction as output */
	DIO_voidSetPinDirection(PORTA_ID, PIN0_ID, PIN_OUTPUT_ID);
	DIO_voidSetPinDirection(PORTA_ID, PIN1_ID, PIN_OUTPUT_ID);
	DIO_voidSetPinDirection(PORTA_ID, PIN2_ID, PIN_OUTPUT_ID);

	while(1)
	{
		/* clear pins 0,1,2 at portA */
		DIO_voidSetPinValue(PORTA_ID, PIN0_ID, PIN_LOW);
		DIO_voidSetPinValue(PORTA_ID, PIN1_ID, PIN_LOW);
		DIO_voidSetPinValue(PORTA_ID, PIN2_ID, PIN_LOW);
	}

	return 0;
}
