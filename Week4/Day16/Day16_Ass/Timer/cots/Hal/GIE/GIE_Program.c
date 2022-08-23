/*
 * GIE_Program.c
 *
 *  Created on: Aug 21, 2022
 *      Author: metro
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Interface.h"
#include "GIE_Private.h"
#include "GIE_Interface.h"
#include "avr/delay.h"

void Global_INTR_Enable()
{
	// enable global interrupt
	set_bit(SREG_REG, GIE);

}

