/*
 * Timer0_Interface.h
 *
 *  Created on: Aug 21, 2022
 *      Author: metro
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

void TIMER0_voidInitNormal();
void TIMER0_voidPreload(u8 Copy_u8Value);
void TIMER0_voidInitCTC();
void TIMER0_voidSetOCR0Value(u8 Copy_u8Value);
void TIMER0_SetCallBack(void (*fptr)(void));


#endif /* TIMER0_INTERFACE_H_ */
