#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Private.h"
#include "DIO_Interface.h"
#include "Motor_Interface.h"
#include "Motor_Config.h"

void Motor_voidInit()
{
	DIO_voidSetPinDirection(MOTOR_PORT, MOTOR_PIN1, PIN_OUTPUT_ID);
	DIO_voidSetPinDirection(MOTOR_PORT, MOTOR_PIN2, PIN_OUTPUT_ID);
	DIO_voidSetPinDirection(MOTOR_PORT, LED, PIN_OUTPUT_ID);

	// set switches as input pins
	DIO_voidSetPinDirection(SWITCHES_PORT, SW1, PIN_INPUT_ID);
	DIO_voidSetPinDirection(SWITCHES_PORT, SW2, PIN_INPUT_ID);
	DIO_voidSetPinDirection(SWITCHES_PORT, SW3, PIN_INPUT_ID);
	DIO_voidSetPinDirection(SWITCHES_PORT, SW4, PIN_INPUT_ID);

	// activate pull-up
	DIO_voidSetPinValue(SWITCHES_PORT, SW1, PIN_HIGH);
	DIO_voidSetPinValue(SWITCHES_PORT, SW2, PIN_HIGH);
	DIO_voidSetPinValue(SWITCHES_PORT, SW3, PIN_HIGH);
	DIO_voidSetPinValue(SWITCHES_PORT, SW4, PIN_HIGH);
}

void Motor(u8 Copy_u8State)
{
	switch(Copy_u8State)
	{
	case STOP:
		DIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN1, PIN_LOW);
		DIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN2, PIN_LOW);
		break;
	case RIGHT:
		DIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN1, PIN_HIGH);
		DIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN2, PIN_LOW);
		break;

	case LEFT:
		DIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN1, PIN_LOW);
		DIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN2, PIN_HIGH);
		break;

	}
}
