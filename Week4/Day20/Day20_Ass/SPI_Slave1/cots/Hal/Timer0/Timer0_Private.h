/*
 * Timer0_Private.h
 *
 *  Created on: Aug 23, 2022
 *      Author: Ahmed Aseel
 */

/********** Header Protection ***********/
#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

/****** Output Compare Register *******/
#define OCR0_REG   *((volatile u8*)0x5C)

/* Timer/Counter Interrupt Mask Register */
#define TIMSK_REG  *((volatile u8*)0x59)

/* Timer/Counter Interrupt Flag Register */
#define TIFR_REG   *((volatile u8*)0x58)

/*** Timer/Counter Control Register ***/
#define TCCR0_REG  *((volatile u8*)0x53)

/******* Timer/Counter Register *******/
#define TCNT0_REG  *((volatile u8*)0x52)

#endif /* TIMER0_PRIVATE_H_ */
