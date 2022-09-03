/*
 * Timer0_Config.h
 *
 *  Created on: Aug 23, 2022
 *      Author: Ahmed Aseel
 */

/********** Header Protection ***********/
#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

/* Clock Select Bits */
#define CS00    0x00
#define CS01    0x01
#define CS02    0x02
/* Waveform Generation Bits */
#define WGM01   0x03
#define WGM00   0x06
/* Compare Match Output Mode Bits */
#define COM00    0x04
#define COM01    0x05

/* Timer/Counter0 Overflow Interrupt Enable */
#define TOIE0    0x00

/* Timer/Counter0 Output Compare Match Interrupt Enable */
#define OCIE0    0x01

/* Timer0 Clock Selections  */
#define NO_CLOCK_SOURCE      0x00
#define NO_PRESCALING        0x01
#define CLK_8                0x02
#define CLK_64               0x03
#define CLK_256              0x04
#define CLK_1024             0x05
#define FALLING_EDGE_CLOCK   0x06
#define RISING_EDGE_CLOCK    0x07

/* Compare Output Mode, non-PWM Mode */
#define OC0_DISCONNECTED     0x00
#define TOGGLE_OC0           0x01
#define CLEAR_OC0            0x02
#define SET_OC0              0x03

#endif /* TIMER0_CONFIG_H_ */
