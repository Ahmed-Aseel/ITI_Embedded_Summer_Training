/*
 * Timer1_Private.h
 *
 *  Created on: Aug 23, 2022
 *      Author: Ahmed Aseel
 */

/********** Header Protection ***********/
#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

/* Timer/Counter Interrupt Mask Register */
#define TIMSK_REG   *((volatile u8*)0x59)

/* Timer/Counter Interrupt Flag Register */
#define TIFR_REG    *((volatile u8*)0x58)

/** Timer/Counter1 Control Register A **/
#define TCCR1A_REG  *((volatile u8*)0x4F)

/** Timer/Counter1 Control Register B **/
#define TCCR1B_REG  *((volatile u8*)0x4E)

/******* Timer/Counter1 Register ********/
#define TCNT1_REG   *((volatile u16*)0x4C)

/****** Output Compare Register 1 A *****/
#define OCR1A_REG   *((volatile u16*)0x4A)

/****** Output Compare Register 1 B *****/
#define OCR1B_REG   *((volatile u16*)0x48)

/******* Input Capture Register 1 *******/
#define ICR1_REG    *((volatile u16*)0x46)

#endif /* TIMER1_PRIVATE_H_ */
