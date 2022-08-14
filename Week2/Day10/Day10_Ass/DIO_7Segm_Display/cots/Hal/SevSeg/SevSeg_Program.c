#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Private.h"
#include "DIO_Interface.h"
#include "SevSeg_Interface.h"

void SevSeg_voidInit()
{
	// set pins 0:6 direction as output pins
	// and pin 7 as input pin at each port
	DIO_voidSetPortDirection(PORTA_ID, 0b01111111);
	DIO_voidSetPortDirection(PORTB_ID, 0b01111111);
	DIO_voidSetPortDirection(PORTC_ID, 0b01111111);
	DIO_voidSetPortDirection(PORTD_ID, 0b01111111);

	// initialize all 7Segs by 0
	DIO_voidSetPortValue(PORTA_ID, 0x40);
	DIO_voidSetPortValue(PORTB_ID, 0x40);
	DIO_voidSetPortValue(PORTC_ID, 0x40);
	DIO_voidSetPortValue(PORTD_ID, 0x40);
}

u8 SevSeg_u8CheckSwitches()
{
	volatile u8 switches = 0;

	// switches var store pin 7 from each port
	// == pinD7 pinC7 pinB7 pinA7
	switches =  switches + read_bit(PIND_REG, 7);
	switches = (switches << 1) + read_bit(PINC_REG, 7);
	switches = (switches << 1) + read_bit(PINB_REG, 7);
	switches = (switches << 1) + read_bit(PINA_REG, 7);

	return switches;
}

void SevSeg_voidDisplayNumber(u8 Copy_u8PortID, u8 copy_u8Number)
{
	DIO_voidSetPortValue(Copy_u8PortID, copy_u8Number);
}
