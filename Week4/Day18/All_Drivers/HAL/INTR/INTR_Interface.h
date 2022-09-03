/*
 * INTR_Interface.h
 *
 *  Created on: Aug 23, 2022
 *      Author: Ahmed Aseel
 */

#ifndef INTR_INTERFACE_H_
#define INTR_INTERFACE_H_

/***************************** Functions Prototype *****************************/
void INTR_voidInit(u8 Copy_u8INTR_ID, u8 Copy_u8INTR_Sense);
void INTR0_SetCallBack(void (*fptr)(void));
void INTR1_SetCallBack(void (*fptr)(void));
void INTR2_SetCallBack(void (*fptr)(void));

#endif /* INTR_INTERFACE_H_ */
