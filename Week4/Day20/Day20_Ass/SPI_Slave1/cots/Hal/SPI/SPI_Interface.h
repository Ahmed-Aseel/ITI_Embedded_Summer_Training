/*
 * SPI_Interface.h
 *
 *  Created on: Aug 25, 2022
 *      Author: Ahmed Aseel
 */

/********** Header Protection **********/
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#define SPI_PORT  0x01 /* Port B */
#define SS    0x04
#define MOSI  0x05
#define MISO  0x06
#define SCK   0x07

#define SPE      0x06 /* SPI Enable          */
#define DORD     0x05 /* Data Order          */
#define MSTR     0x04 /* Master/Slave Select */
#define CPOL     0x03 /*Clock Polarity       */
#define CPHA     0x02 /*Clock Phase          */

/* SPI Clock Rate Select 1 and 0 */
#define SPR1     0x01
#define SPR0     0x00

#define SPI2X    0x00 /* Double SPI Speed Bit */

#define SPIF     0x07 /* SPI Interrupt Flag  */

/*     SPI Mode    */
#define SLAVE   0x00
#define MASTER  0x01

/***************************** Functions Prototype *****************************/
void SPI_voidInit(u8 Copy_u8SPIMode);
u8 SPI_u8Transciever(u8 Copy_u8Data);

#endif /* SPI_INTERFACE_H_ */
