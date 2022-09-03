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
#include "INTR_Interface.h"
#include "INTR_Config.h"
#include "LCD_Interface.h"
#include "LCD_Config.h"
#include "SPI_Interface.h"
#include "avr/delay.h"
void INTR0_ISR(void)
{
	u8 data;

	/* Disable Global Interrupt
	 * to disable nested interrupts
	 */
	Global_INTR_Disable();

	LCD_voidClear();
	LCD_voidWriteString("INTR0 ISR");

	/* Select slave1 to send data */
	DIO_voidSetPinValue(PORTD_ID, PIN5_ID, PIN_LOW);
	DIO_voidSetPinValue(PORTD_ID, PIN6_ID, PIN_HIGH);

	/* Send latter 'S' to start timer
	 * and read received data
	 */
	data = SPI_u8Transciever('S');

	LCD_voidGoToXY(LINE_2, 0);
	LCD_voidWriteString("Send To Slave1");

	/* Enable Global Interrupt again */
	Global_INTR_Enable();
}

void INTR1_ISR(void)
{
	u8 data, *str = "HELLO!!";

	/* Disable Global Interrupt
	 * to disable nested interrupts
	 */
	Global_INTR_Disable();

	LCD_voidClear();
	LCD_voidWriteString("INTR1 ISR");

	/* Select slave2 to send data */
	DIO_voidSetPinValue(PORTD_ID, PIN6_ID, PIN_LOW);
	DIO_voidSetPinValue(PORTD_ID, PIN5_ID, PIN_HIGH);

	LCD_voidGoToXY(LINE_2, 0);
	LCD_voidWriteString("Send To Slave2");

	/* Send string to slave2
	 * to display using UART
	 * and read received data
	 */
	while(*str)
	{
		data = SPI_u8Transciever(*str);
		str++;
		// delay to make sure there is no overwrite
		_delay_ms(1);
	}

	/* Enable Global Interrupt again */
	Global_INTR_Enable();
}

int main()
{
	/* Enable Global Interrupt */
	Global_INTR_Enable();

	/* Enable Interrupt 0 with rising edge sense */
	INTR_voidInit(INTR0_ID, RISING_EDGE);
	/* Enable Interrupt 1 with rising edge sense */
	INTR_voidInit(INTR1_ID, RISING_EDGE);

	/* Send addresses of ISR functions to INTR driver */
	INTR0_SetCallBack(INTR0_ISR);
	INTR1_SetCallBack(INTR1_ISR);

	/* Set direction of INTR0,1 pins as input */
	DIO_voidSetPinDirection(INTR0_PORT, INTR0_PIN, PIN_INPUT_ID);
	DIO_voidSetPinDirection(INTR1_PORT, INTR1_PIN, PIN_INPUT_ID);

	/* Pins to select slave
	 * pin5 ---> slave1, pin6 ---> slave2
	 * clear corresponding pin to select this slave
	 */
	DIO_voidSetPinDirection(PORTD_ID, PIN5_ID, PIN_OUTPUT_ID);
	DIO_voidSetPinDirection(PORTD_ID, PIN6_ID, PIN_OUTPUT_ID);

	/* Initialize SPI & Select master mode */
	SPI_voidInit(MASTER);

	DIO_voidSetPinDirection(SPI_PORT, SS, PIN_INPUT_ID);
	DIO_voidSetPinDirection(SPI_PORT, MOSI, PIN_OUTPUT_ID);
	DIO_voidSetPinDirection(SPI_PORT, MISO, PIN_INPUT_ID);
	DIO_voidSetPinDirection(SPI_PORT, SCK, PIN_OUTPUT_ID);

	LCD_voidInit();
	LCD_voidWriteString("WELCOME");

	while(1);

	return 0;
}
