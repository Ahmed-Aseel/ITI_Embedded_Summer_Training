/*
 * Timer2_Config.h
 *
 *  Created on: Aug 24, 2022
 *      Author: Ahmed Aseel
 */

/********** Header Protection ***********/
#ifndef TIMER2_CONFIG_H_
#define TIMER2_CONFIG_H_

/* Clock Select Bits */
#define CS20    0x00
#define CS21    0x01
#define CS22    0x02
/* Waveform Generation Bits */
#define WGM21   0x03
#define WGM20   0x06
/* Compare Match Output Mode Bits */
#define COM20    0x04
#define COM21    0x05

/* Timer/Counter2 Overflow Interrupt Enable */
#define TOIE2    0x06

/* Timer/Counter2 Output Compare Match Interrupt Enable */
#define OCIE2    0x07

/* Timer2 Clock Selections  */
#define NO_CLOCK_SOURCE      0x00
#define NO_PRESCALING        0x01
#define CLK_8                0x02
#define CLK_64               0x03
#define CLK_256              0x04
#define CLK_1024             0x05
#define FALLING_EDGE_CLOCK   0x06
#define RISING_EDGE_CLOCK    0x07

/* Compare Output Mode, non-PWM Mode */
#define OC2_DISCONNECTED     0x00
#define TOGGLE_OC2           0x01
#define CLEAR_OC2            0x02
#define SET_OC2              0x03

#endif /* TIMER2_CONFIG_H_ */
