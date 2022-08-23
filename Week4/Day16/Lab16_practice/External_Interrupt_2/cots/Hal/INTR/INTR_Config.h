// header protection
#ifndef INTR_CONFIG_H_
#define INTR_CONFIG_H_

#define INTR0_ID  0x00
#define INTR1_ID  0x01
#define INTR2_ID  0x02

#define INTR0_BIT  PIN6_ID
#define INTR1_BIT  PIN7_ID
#define INTR2_BIT  PIN5_ID

/* Interrupt Sense Control 0 Bit 0 and Bit 1 */
#define ISC00 PIN0_ID
#define ISC01 PIN1_ID

/* Interrupt Sense Control 1 Bit 0 and Bit 1 */
#define ISC10 PIN2_ID
#define ISC11 PIN3_ID

/* Interrupt Sense Control 2 Bit */
#define ISC2 PIN6_ID


/* external interrupt pins */
#define INTR0_PIN  PIN2_ID
#define INTR1_PIN  PIN3_ID
#define INTR2_PIN  PIN2_ID

/* interrupt sense control */
#define LOW_LEVEL    0x00
#define ANY_CHANGE   0x01
#define FALLING_EDGE 0x02
#define RISING_EDGE  0x03

#endif
