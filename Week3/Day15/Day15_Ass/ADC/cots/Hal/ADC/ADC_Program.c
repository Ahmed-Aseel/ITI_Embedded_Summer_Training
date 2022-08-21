#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Interface.h"
#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "avr/delay.h"

void ADC_voidInit()
{
	/* ADC Enable */
	set_bit(ADCSRA_REG, PIN7_ID);
	/* ADC Start Conversion  (Single Conversion) */
	set_bit(ADCSRA_REG, PIN6_ID);
}

void ADC_voidSelectRef(u8 Copy_u8VoltRef)
{
	// clear pins 7(REFS1) ,6(REFS0)
	ADMUX_REG &= 0x3F;
	// store Copy_u8VoltRef in pins 6,7
	ADMUX_REG |= (Copy_u8VoltRef << 6);
}

void ADC_voidSelectChannel(u8 Copy_u8Channnel)
{
	// clear first five bits (ADC4:ADC0)
	ADMUX_REG &= 0xE0;
	// store Copy_u8Channnel in first five bits (ADC4:ADC0)
	ADMUX_REG |= Copy_u8Channnel;
}

void ADC_voidLeftorRight(u8 Copy_u8Adjust)
{
	switch(Copy_u8Adjust)
	{
	case RIGHT:
		// ADC Right Adjust Result
		clear_bit(ADMUX_REG, PIN5_ID);
		break;

	case LEFT:
		// ADC Right Adjust Result
		set_bit(ADMUX_REG, PIN5_ID);
		break;
	}
}

void ADC_voidSelectPrescaler(u8 Copy_u8Factor)
{
	// clear first three bits (ADPS2:ADPS0)
	ADCSRA_REG &= 0xF8;
	// store Copy_u8Factor in first three bits (ADPS2:ADPS0)
	ADCSRA_REG |= Copy_u8Factor;
}

void ADC_voidSimpleConv()
{
	/* ADC Start Conversion (Single Conversion) */
	set_bit(ADCSRA_REG, PIN6_ID);
}

u16 ADC_u16GetResult()
{
	return ADCL_REG;
}
