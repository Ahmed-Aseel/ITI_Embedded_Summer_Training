/*
 * GIE_Program.c
 *
 *  Created on: Aug 23, 2022
 *      Author: Ahmed Aseel
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "GIE_Private.h"
#include "GIE_Interface.h"

/*********************************** Functions Definition ***********************************/

/*******************************************************************************************/
void Global_INTR_Enable()
{
	// enable global interrupt
	Set_Bit(SREG_REG, GIE);

}

/*******************************************************************************************/
void Global_INTR_Disable()
{
	// disable global interrupt
	Clr_Bit(SREG_REG, GIE);

}
/*******************************************************************************************/
