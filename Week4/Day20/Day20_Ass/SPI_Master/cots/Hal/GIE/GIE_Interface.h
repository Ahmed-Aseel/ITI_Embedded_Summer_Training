/*
 * GIE_Interface.h
 *
 *  Created on: Aug 23, 2022
 *      Author: Ahmed Aseel
 */

/********** Header Protection **********/
#ifndef GIE_INTERFACE_H_
#define GIE_INTERFACE_H_

/* Global Interrupt Enable bit */
#define GIE  0x07

/***************************** Functions Prototype *****************************/
void Global_INTR_Enable();
void Global_INTR_Disable();

#endif /* GIE_INTERFACE_H_ */
