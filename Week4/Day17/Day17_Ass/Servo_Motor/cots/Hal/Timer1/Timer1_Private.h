/*
 * Timer1_Private.h
 *
 *  Created on: Aug 22, 2022
 *      Author: metro
 */

#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

#define TCCR1A_REG  *((volatile u8*)0x4F)
#define TCCR1B_REG  *((volatile u8*)0x4E)
#define TCNT1_REG   *((volatile u16*)0x4C)
#define OCR1A_REG   *((volatile u16*)0x4A)
#define OCR1B_REG   *((volatile u16*)0x48)
#define ICR1_REG    *((volatile u16*)0x46)
#define TIFR_REG    *((volatile u8*)0x58)
#define TIMSK_REG   *((volatile u8*)0x59)

#endif /* TIMER1_PRIVATE_H_ */
