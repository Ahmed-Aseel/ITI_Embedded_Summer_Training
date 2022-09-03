/*
 * INTR_Private.h
 *
 *  Created on: Aug 23, 2022
 *      Author: Ahmed Aseel
 */

/********** Header Protection ***********/
#ifndef INTR_PRIVATE_H_
#define INTR_PRIVATE_H_

/** General Interrupt Control Register **/
#define GICR_REG     *((volatile u8*)0x5B)

/********* MCU Control Register *********/
#define MCUCR_REG    *((volatile u8*)0x55)

/**** MCU Control and Status Register ***/
#define MCUCSR_REG   *((volatile u8*)0x54)

#endif /* INTR_PRIVATE_H_ */
