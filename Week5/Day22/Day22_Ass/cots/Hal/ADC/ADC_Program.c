/*
 * ADC_Program.c
 *
 *  Created on: Aug 23, 2022
 *      Author: Ahmed Aseel
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "ADC_Private.h"
#include "ADC_Config.h"
#include "ADC_Interface.h"
#include "avr/delay.h"

/*********************************** Functions Definition ***********************************/

/*******************************************************************************************/
void ADC_voidInit()
{
	/* ADC Enable */
	Set_Bit(ADCSRA_REG, ADEN);
	/* ADC Start Conversion  (Single Conversion) */
	Set_Bit(ADCSRA_REG, ADSC);
}

/*******************************************************************************************/
void ADC_voidSelectRef(u8 Copy_u8VoltRef)
{
	// clear pins 6(REFS0), 7(REFS1)
	Clr_Bit(ADMUX_REG, REFS0);
	Clr_Bit(ADMUX_REG, REFS1);

	// store Copy_u8VoltRef in pins 6,7
	ADMUX_REG |= (Copy_u8VoltRef << REFS0);
}

/*******************************************************************************************/
void ADC_voidSelectChannel(u8 Copy_u8Channnel)
{
	// clear first five bits (MUX4:MUX0)
	Clr_Bit(ADMUX_REG, MUX0);
	Clr_Bit(ADMUX_REG, MUX1);
	Clr_Bit(ADMUX_REG, MUX2);
	Clr_Bit(ADMUX_REG, MUX3);
	Clr_Bit(ADMUX_REG, MUX4);

	// store Copy_u8Channnel in first five bits (ADC4:ADC0)
	ADMUX_REG |= Copy_u8Channnel;
}

/*******************************************************************************************/
void ADC_voidLeftorRight(u8 Copy_u8Adjust)
{
	switch(Copy_u8Adjust)
	{
	case RIGHT:
		// ADC Right Adjust Result
		Clr_Bit(ADMUX_REG, ADLAR);
		break;

	case LEFT:
		// ADC Right Adjust Result
		Set_Bit(ADMUX_REG, ADLAR);
		break;
	}
}

/*******************************************************************************************/
void ADC_voidSelectPrescaler(u8 Copy_u8Factor)
{
	// clear first three bits (ADPS2:ADPS0)
	Clr_Bit(ADCSRA_REG, ADPS0);
	Clr_Bit(ADCSRA_REG, ADPS1);
	Clr_Bit(ADCSRA_REG, ADPS2);

	// store Copy_u8Factor in first three bits (ADPS2:ADPS0)
	ADCSRA_REG |= Copy_u8Factor;
}

/*******************************************************************************************/
void ADC_voidSingleConv()
{
	/* ADC Start Conversion (Single Conversion) */
	Set_Bit(ADCSRA_REG, ADSC);
}

/*******************************************************************************************/
u16 ADC_u16GetResult()
{
	/* return value of ADC Data Register */
	return ADCL_REG;
}
/*******************************************************************************************/
