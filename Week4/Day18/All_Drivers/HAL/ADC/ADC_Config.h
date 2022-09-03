/*
 * ADC_Config.h
 *
 *  Created on: Aug 23, 2022
 *      Author: Ahmed Aseel
 */

/********** Header Protection **********/
#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#define ADSC   0x06 /* ADC Start Conversion Bit */
#define ADEN   0x07 /* ADC Enable Bit           */

/* Reference Selection Bits */
#define REFS0  0x06
#define REFS1  0x07
/* ADC Voltage Reference    */
#define VREF_OFF   0x00
#define AVCC_CAP   0x01
#define RESERVED   0x02
#define VREF_2_56  0x03

/* Analog Channel and
 * Gain Selection Bits
 */
#define MUX0  0x00
#define MUX1  0x01
#define MUX2  0x02
#define MUX3  0x03
#define MUX4  0x04
/* ADC Analog Channel */
#define CHANNEL0  0x00
#define CHANNEL1  0x01
#define CHANNEL2  0x02
#define CHANNEL3  0x03
#define CHANNEL4  0x04
#define CHANNEL5  0x05
#define CHANNEL6  0x06
#define CHANNEL7  0x07

 /* ADC Left Adjust Result Bit */
#define ADLAR 0x05
/* Adjust Result               */
#define RIGHT  0x00
#define LEFT   0x01

/* ADC Prescaler Select Bits */
#define ADPS0  0x00
#define ADPS1  0x01
#define ADPS2  0x02
/* ADC Prescaler Selections  */
#define FACTOR_2_0  0x00
#define FACTOR_2_1  0x01
#define FACTOR_4    0x02
#define FACTOR_8    0x03
#define FACTOR_16   0x04
#define FACTOR_32   0x05
#define FACTOR_64   0x06
#define FACTOR_128  0x07

#endif /* ADC_CONFIG_H_ */
