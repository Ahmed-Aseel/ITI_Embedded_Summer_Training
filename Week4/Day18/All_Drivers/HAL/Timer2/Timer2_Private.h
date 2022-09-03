/*
 * Timer2_Private.h
 *
 *  Created on: Aug 24, 2022
 *      Author: Ahmed Aseel
 */

/********** Header Protection ***********/
#ifndef TIMER2_PRIVATE_H_
#define TIMER2_PRIVATE_H_

/* Timer/Counter Interrupt Mask Register */
#define TIMSK_REG  *((volatile u8*)0x59)

/* Timer/Counter Interrupt Flag Register */
#define TIFR_REG   *((volatile u8*)0x58)

/*** Timer/Counter Control Register ***/
#define TCCR2_REG  *((volatile u8*)0x45)

/******* Timer/Counter Register *******/
#define TCNT2_REG  *((volatile u8*)0x44)

/****** Output Compare Register *******/
#define OCR2_REG   *((volatile u8*)0x43)

/**** Asynchronous Status Register ****/
#define ASSR_REG   *((volatile u8*)0x42)

#endif /* TIMER2_PRIVATE_H_ */
