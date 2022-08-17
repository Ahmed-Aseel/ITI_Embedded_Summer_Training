/*
 * main.c
 *
 *  Created on: Aug 16, 2022
 *      Author: Aseel
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Interface.h"
#include "Motor_Interface.h"
#include "Motor_Config.h"
#include "avr/delay.h"

int main()
{
	Motor_voidInit();

	while(1)
	{
		/* Start DC Motor 1 & 2
		 * Make DC Motor 3 rotates in some direction
		 */
		DIO_voidSetPinValue(MOTOR1_PORT, MOTOR1_PIN, PIN_HIGH);
		DIO_voidSetPinValue(MOTOR2_PORT, MOTOR2_PIN, PIN_HIGH);
		Motor(RIGHT);
		_delay_ms(2000);

		/* Stop DC Motor 1 & 2
		 * Make DC Motor 3 in rotates in opposite direction
		 */
		DIO_voidSetPinValue(MOTOR1_PORT, MOTOR1_PIN, PIN_LOW);
		DIO_voidSetPinValue(MOTOR2_PORT, MOTOR2_PIN, PIN_LOW);
		Motor(LEFT);
		_delay_ms(2000);
	}

	return 0;
}
