/*
 * main.c
 *
 *  Created on: Aug 25, 2022
 *      Author: Ahmed Aseel
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Interface.h"
#include "UART_Interface.h"
#include "SPI_Interface.h"

int main()
{
	u8 data;
	/* Select slave mode */
	SPI_voidInit(SLAVE);

	DIO_voidSetPinDirection(SPI_PORT, SS, PIN_INPUT_ID);
	DIO_voidSetPinDirection(SPI_PORT, MOSI, PIN_INPUT_ID);
	DIO_voidSetPinDirection(SPI_PORT, MISO, PIN_OUTPUT_ID);
	DIO_voidSetPinDirection(SPI_PORT, SCK, PIN_INPUT_ID);

	UART_voidInit();

	while(1)
	{
		/* Send letter 'B' and read received data */
		data = SPI_u8Transciever('B');
		/* Send data to UART */
		UART_voidSendData(data);
	}

	return 0;
}

