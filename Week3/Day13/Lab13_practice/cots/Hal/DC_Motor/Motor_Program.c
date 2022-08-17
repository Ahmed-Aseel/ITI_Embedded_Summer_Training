#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Private.h"
#include "DIO_Interface.h"
#include "Motor_Interface.h"
#include "Motor_Config.h"

void Motor_voidInit()
{
	/* DC Motor 1 connected to pin0 portC
	 * DC Motor 2 connected to pin1 portC
	 * DC Motor 3 connected to pin 0,1 portD
	 */
	DIO_voidSetPinDirection(MOTOR1_PORT, MOTOR1_PIN, PIN_OUTPUT_ID);
	DIO_voidSetPinDirection(MOTOR2_PORT, MOTOR2_PIN, PIN_OUTPUT_ID);
	DIO_voidSetPinDirection(MOTOR3_PORT, MOTOR3_PIN1, PIN_OUTPUT_ID);
	DIO_voidSetPinDirection(MOTOR3_PORT, MOTOR3_PIN2, PIN_OUTPUT_ID);
}

void Motor(u8 Copy_u8State)
{
	switch(Copy_u8State)
	{
	case STOP:
		DIO_voidSetPinValue(MOTOR3_PORT, MOTOR3_PIN1, PIN_LOW);
		DIO_voidSetPinValue(MOTOR3_PORT, MOTOR3_PIN2, PIN_LOW);
		break;
	case RIGHT:
		DIO_voidSetPinValue(MOTOR3_PORT, MOTOR3_PIN1, PIN_HIGH);
		DIO_voidSetPinValue(MOTOR3_PORT, MOTOR3_PIN2, PIN_LOW);
		break;

	case LEFT:
		DIO_voidSetPinValue(MOTOR3_PORT, MOTOR3_PIN1, PIN_LOW);
		DIO_voidSetPinValue(MOTOR3_PORT, MOTOR3_PIN2, PIN_HIGH);
		break;

	}
}
