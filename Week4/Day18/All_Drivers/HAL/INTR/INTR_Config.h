/*
 * INTR_Config.h
 *
 *  Created on: Aug 23, 2022
 *      Author: Ahmed Aseel
 */

#ifndef INTR_CONFIG_H_
#define INTR_CONFIG_H_

/* Interrupts ID Macros */
#define INTR0_ID  0x00
#define INTR1_ID  0x01
#define INTR2_ID  0x02

/* External Interrupt Bit Enable */
#define INT0  0x06
#define INT1  0x07
#define INT2  0x05

/* Interrupt Sense Control 0 Bit 0 and Bit 1 */
#define ISC00  0x00
#define ISC01  0x01

/* Interrupt Sense Control 1 Bit 0 and Bit 1 */
#define ISC10  0x02
#define ISC11  0x03

/* Interrupt Sense Control 2 Bit */
#define ISC2  0x06

/*** Interrupt Ports ***/
#define INTR0_PORT  0x03     /* PortD */
#define INTR1_PORT  0x03     /* PortD */
#define INTR2_PORT  0x01     /* PortB */

/*** Interrupt Pins ***/
#define INTR0_PIN  0x02     /* Pin2 */
#define INTR1_PIN  0x03     /* Pin3 */
#define INTR2_PIN  0x02     /* Pin2 */

/* Interrupt Sense Control */
#define LOW_LEVEL     0x00
#define ANY_CHANGE    0x01
#define FALLING_EDGE  0x02
#define RISING_EDGE   0x03

/* Pin Direction */
#define PIN_INPUT   0x00
#define PIN_OUTPUT  0x01

#endif /* INTR_CONFIG_H_ */
