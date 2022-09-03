/*
 * Timer2_Interface.h
 *
 *  Created on: Aug 24, 2022
 *      Author: Ahmed Aseel
 */

/********** Header Protection ***********/
#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_

/***************************** Functions Prototype *****************************/
void TIMER2_voidInitNormal(u8 Copy_u8ClkSelect);
void TIMER2_voidPreload(u8 Copy_u8Value);
void TIMER2_voidInitCTC(u8 Copy_u8Mode, u8 Copy_u8ClkSelect);
void TIMER2_voidSetOCR2Value(u8 Copy_u8Value);
void TIMER2_SetCallBack(void (*fptr)(void));

#endif /* TIMER2_INTERFACE_H_ */
