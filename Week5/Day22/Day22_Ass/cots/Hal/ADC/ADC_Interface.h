/*
 * ADC_Interface.h
 *
 *  Created on: Aug 23, 2022
 *      Author: Ahmed Aseel
 */

/********** Header Protection **********/
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/***************************** Functions Prototype *****************************/
void ADC_voidInit();
void ADC_voidSelectRef(u8 Copy_u8VoltRef);
void ADC_voidSelectChannel(u8 Copy_u8Channnel);
void ADC_voidLeftorRight(u8 Copy_u8Adjust);
void ADC_voidSelectPrescaler(u8 Copy_u8Factor);
void ADC_voidSingleConv();
u16 ADC_u16GetResult();

#endif /* ADC_INTERFACE_H_ */
