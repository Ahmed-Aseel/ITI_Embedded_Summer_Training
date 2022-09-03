/*
 * Timer0_Interface.h
 *
 *  Created on: Aug 23, 2022
 *      Author: Ahmed Aseel
 */

/********** Header Protection ***********/
#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

/***************************** Functions Prototype *****************************/
void TIMER0_voidInitNormal(u8 Copy_u8ClkSelect);
void TIMER0_voidPreload(u8 Copy_u8Value);
void TIMER0_voidInitCTC(u8 Copy_u8Mode, u8 Copy_u8ClkSelect);
void TIMER0_voidSetOCR0Value(u8 Copy_u8Value);
void TIMER0_SetCallBack(void (*fptr)(void));

#endif /* TIMER0_INTERFACE_H_ */
