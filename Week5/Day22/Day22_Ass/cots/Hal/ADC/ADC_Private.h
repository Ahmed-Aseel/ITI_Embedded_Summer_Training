/*
 * ADC_Private.h
 *
 *  Created on: Aug 23, 2022
 *      Author: Ahmed Aseel
 */

/********** Header Protection ***********/
#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/***** Special Function I/O Register ****/
#define SFIOR_REG    *((volatile u8*)0x50)

/** ADC Multiplexer Selection Register **/
#define ADMUX_REG    *((volatile u8*)0x27)

/*** ADC Control and Status Register A **/
#define ADCSRA_REG   *((volatile u8*)0x26)

/********* The ADC Data Register *********/
#define ADCL_REG     *((volatile u16*)0x24)

#endif /* ADC_PRIVATE_H_ */
