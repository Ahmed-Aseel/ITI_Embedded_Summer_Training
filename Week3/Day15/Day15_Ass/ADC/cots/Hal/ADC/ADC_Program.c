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
	switch(Copy_u8VoltRef)
	{
	case VREF_OFF:    /* AREF, Internal Vref turned off */
		clear_bit(ADMUX_REG, PIN7_ID);
		clear_bit(ADMUX_REG, PIN6_ID);
		break;

	case AVCC_CAP:    /* AVCC with external capacitor at AREF pin */
		clear_bit(ADMUX_REG, PIN7_ID);
		set_bit(ADMUX_REG, PIN6_ID);
		break;

	case RESERVED:    /* Reserved */
		set_bit(ADMUX_REG, PIN7_ID);
		clear_bit(ADMUX_REG, PIN6_ID);
		break;

	case VREF_2_56:    /* Internal 2.56V Voltage Reference */
		set_bit(ADMUX_REG, PIN7_ID);
		set_bit(ADMUX_REG, PIN6_ID);
		break;
	}
}

void ADC_voidSelectChannel(u8 Copy_u8Channnel)
{
	switch(Copy_u8Channnel)
	{
	case CHANNEL0:    /* Analog Channel 0 */
		clear_bit(ADMUX_REG, PIN0_ID);
		clear_bit(ADMUX_REG, PIN1_ID);
		clear_bit(ADMUX_REG, PIN2_ID);
		clear_bit(ADMUX_REG, PIN3_ID);
		clear_bit(ADMUX_REG, PIN4_ID);
		break;

	case CHANNEL1:    /* Analog Channel 1 */
		set_bit(ADMUX_REG, PIN0_ID);
		clear_bit(ADMUX_REG, PIN1_ID);
		clear_bit(ADMUX_REG, PIN2_ID);
		clear_bit(ADMUX_REG, PIN3_ID);
		clear_bit(ADMUX_REG, PIN4_ID);
		break;

	case CHANNEL2:    /* Analog Channel 2 */
		clear_bit(ADMUX_REG, PIN0_ID);
		set_bit(ADMUX_REG, PIN1_ID);
		clear_bit(ADMUX_REG, PIN2_ID);
		clear_bit(ADMUX_REG, PIN3_ID);
		clear_bit(ADMUX_REG, PIN4_ID);
		break;

	case CHANNEL3:    /* Analog Channel 3 */
		set_bit(ADMUX_REG, PIN0_ID);
		set_bit(ADMUX_REG, PIN1_ID);
		clear_bit(ADMUX_REG, PIN2_ID);
		clear_bit(ADMUX_REG, PIN3_ID);
		clear_bit(ADMUX_REG, PIN4_ID);
		break;

	case CHANNEL4:    /* Analog Channel 4 */
		clear_bit(ADMUX_REG, PIN0_ID);
		clear_bit(ADMUX_REG, PIN1_ID);
		set_bit(ADMUX_REG, PIN2_ID);
		clear_bit(ADMUX_REG, PIN3_ID);
		clear_bit(ADMUX_REG, PIN4_ID);
		break;

	case CHANNEL5:    /* Analog Channel 5 */
		set_bit(ADMUX_REG, PIN0_ID);
		clear_bit(ADMUX_REG, PIN1_ID);
		set_bit(ADMUX_REG, PIN2_ID);
		clear_bit(ADMUX_REG, PIN3_ID);
		clear_bit(ADMUX_REG, PIN4_ID);
		break;

	case CHANNEL6:    /* Analog Channel 6 */
		clear_bit(ADMUX_REG, PIN0_ID);
		set_bit(ADMUX_REG, PIN1_ID);
		set_bit(ADMUX_REG, PIN2_ID);
		clear_bit(ADMUX_REG, PIN3_ID);
		clear_bit(ADMUX_REG, PIN4_ID);
		break;

	case CHANNEL7:    /* Analog Channel 7 */
		set_bit(ADMUX_REG, PIN0_ID);
		set_bit(ADMUX_REG, PIN1_ID);
		set_bit(ADMUX_REG, PIN2_ID);
		clear_bit(ADMUX_REG, PIN3_ID);
		clear_bit(ADMUX_REG, PIN4_ID);
		break;
	}
}

void ADC_voidLeftorRight(u8 Copy_u8Adjust)
{
	switch(Copy_u8Adjust)
	{
	case RIGHT:
		/* ADC Right Adjust Result */
		clear_bit(ADMUX_REG, PIN5_ID);
		break;

	case LEFT:
		/* ADC Right Adjust Result */
		set_bit(ADMUX_REG, PIN5_ID);
		break;
	}
}

void ADC_voidSelectPrescaler(u8 Copy_u8Factor)
{
	switch(Copy_u8Factor)
	{
	case FACTOR_2_0:  /* ADC Prescaler Division Factor 2 */
		clear_bit(ADCSRA_REG, PIN2_ID);
		clear_bit(ADCSRA_REG, PIN1_ID);
		clear_bit(ADCSRA_REG, PIN0_ID);
		break;

	case FACTOR_2_1:  /* ADC Prescaler Division Factor 2 */
		clear_bit(ADCSRA_REG, PIN2_ID);
		clear_bit(ADCSRA_REG, PIN1_ID);
		set_bit(ADCSRA_REG, PIN0_ID);
		break;

	case FACTOR_4:	 /* ADC Prescaler Division Factor 4 */
		clear_bit(ADCSRA_REG, PIN2_ID);
		set_bit(ADCSRA_REG, PIN1_ID);
		clear_bit(ADCSRA_REG, PIN0_ID);
		break;

	case FACTOR_8:	 /* ADC Prescaler Division Factor 8 */
		clear_bit(ADCSRA_REG, PIN2_ID);
		set_bit(ADCSRA_REG, PIN1_ID);
		set_bit(ADCSRA_REG, PIN0_ID);
		break;

	case FACTOR_16:	 /* ADC Prescaler Division Factor 16 */
		set_bit(ADCSRA_REG, PIN2_ID);
		clear_bit(ADCSRA_REG, PIN1_ID);
		clear_bit(ADCSRA_REG, PIN0_ID);
		break;

	case FACTOR_32:	 /* ADC Prescaler Division Factor 32 */
		set_bit(ADCSRA_REG, PIN2_ID);
		clear_bit(ADCSRA_REG, PIN1_ID);
		set_bit(ADCSRA_REG, PIN0_ID);
		break;

	case FACTOR_64:	 /* ADC Prescaler Division Factor 64 */
		set_bit(ADCSRA_REG, PIN2_ID);
		set_bit(ADCSRA_REG, PIN1_ID);
		clear_bit(ADCSRA_REG, PIN0_ID);
		break;

	case FACTOR_128: /* ADC Prescaler Division Factor 128 */
		set_bit(ADCSRA_REG, PIN2_ID);
		set_bit(ADCSRA_REG, PIN1_ID);
		set_bit(ADCSRA_REG, PIN0_ID);
		break;
	}
}

void ADC_voidSimpleConv()
{
	/* ADC Start Conversion  (Single Conversion) */
	set_bit(ADCSRA_REG, PIN6_ID);
}

u16 ADC_u16GetResult()
{
	return ADCL_REG;
}
