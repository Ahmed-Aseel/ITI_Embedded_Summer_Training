// header protection
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

// ADC Voltage Reference
#define VREF_OFF  0x00
#define AVCC_CAP  0x01
#define RESERVED  0x02
#define VREF_2_56 0x03

// ADC Analog Channel
#define CHANNEL0 0x00
#define CHANNEL1 0x01
#define CHANNEL2 0x02
#define CHANNEL3 0x03
#define CHANNEL4 0x04
#define CHANNEL5 0x05
#define CHANNEL6 0x06
#define CHANNEL7 0x07

// Adjust Result
#define RIGHT  0x00
#define LEFT   0x01

// ADC Division Factor
#define FACTOR_2_0 0x00
#define FACTOR_2_1 0x01
#define FACTOR_4   0x02
#define FACTOR_8   0x03
#define FACTOR_16  0x04
#define FACTOR_32  0x05
#define FACTOR_64  0x06
#define FACTOR_128 0x07


/*       prototypes      */
void ADC_voidInit();
void ADC_voidSelectRef(u8 Copy_u8VoltRef);
void ADC_voidSelectChannel(u8 Copy_u8Channnel);
void ADC_voidLeftorRight(u8 Copy_u8Adjust);
void ADC_voidSelectPrescaler(u8 Copy_u8Factor);
void ADC_voidSingleConv();
u16 ADC_u16GetResult();
#endif
