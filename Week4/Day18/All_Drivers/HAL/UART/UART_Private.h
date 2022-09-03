/*
 * UART_Private.h
 *
 *  Created on: Aug 24, 2022
 *      Author: Ahmed Aseel
 */

/********** Header Protection **********/
#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

/********** USART I/O Data Register **********/
#define UDR_REG          *((volatile u8*)0x2C)

/**** USART Control and Status Register A ****/
#define UCSRA_REG        *((volatile u8*)0x2B)

/**** USART Control and Status Register B ****/
#define UCSRB_REG        *((volatile u8*)0x2A)

/**** USART Control and Status Register C ****/
#define UBRRH_UCSRC_REG  *((volatile u8*)0x40)

/**** USART Baud Rate Registers (Low Byte) ***/
#define UBRRL_REG        *((volatile u8*)0x29)

#endif /* UART_PRIVATE_H_ */
