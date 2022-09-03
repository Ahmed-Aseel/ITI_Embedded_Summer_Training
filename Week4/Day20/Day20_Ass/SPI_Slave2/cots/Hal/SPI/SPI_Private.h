/*
 * SPI_Private.h
 *
 *  Created on: Aug 25, 2022
 *      Author: Ahmed Aseel
 */

/********** Header Protection **********/
#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

/********** SPI Data Register **********/
#define SPDR_REG    *((volatile u8*)0x2F)

/******** SPI Status Register **********/
#define SPSR_REG    *((volatile u8*)0x2E)

/******** SPI Control Register *********/
#define SPCR_REG    *((volatile u8*)0x2D)

#endif /* SPI_PRIVATE_H_ */
