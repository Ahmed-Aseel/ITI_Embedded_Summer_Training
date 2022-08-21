// header protection
#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADMUX_REG      *((volatile u8*)0x27)
#define ADCSRA_REG     *((volatile u8*)0x26)
#define ADCL_REG       *((volatile u16*)0x24)
#define SFIOR_REG      *((volatile u8*)0x50)

#endif
