/*
 * Timer0_Private.h
 *
 *  Created on: Aug 21, 2022
 *      Author: metro
 */

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define TCCR0_REG *((volatile u8*)0x53)
#define TCNT0_REG *((volatile u8*)0x52)
#define TIFR_REG  *((volatile u8*)0x58)
#define TIMSK_REG *((volatile u8*)0x59)
#define OCR0_REG *((volatile u8*)0x5C)

#endif /* TIMER0_PRIVATE_H_ */
