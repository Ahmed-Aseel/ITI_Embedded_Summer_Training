/*
 * UART_Interface.h
 *
 *  Created on: Aug 24, 2022
 *      Author: Ahmed Aseel
 */

/********** Header Protection **********/
#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#define RXC     0x07 /* USART Receive Complete    */
#define TXC     0x06 /* USART Transmit Complete   */
#define UDRE    0x05 /* USART Data Register Empty */

#define RXEN    0x04 /* USART Receiver Enable    */
#define TXEN    0x03 /* USART Transmitter Enable */

#define URSEL   0x07 /* USART Register Select    */
#define UMSEL   0x06 /* USART Mode Select        */

/* USART Parity Mode */
#define UPM1    0x05
#define UPM0    0x04

#define USBS    0x03 /* USART Stop Bit Select    */

/* USART Character Size */
#define UCSZ2   0x02 /* In UCSRB_REG */
#define UCSZ1   0x02
#define UCSZ0   0x01

#define UCPOL   0x00 /* USART Clock Polarity    */

/***************************** Functions Prototype *****************************/
void UART_voidInit();
void UART_voidSendData(u8 Copy_u8Data);
void UART_voidSendString(u8* Copy_u8Str);
u8 UART_u8RecieveData();

#endif /* UART_INTERFACE_H_ */
