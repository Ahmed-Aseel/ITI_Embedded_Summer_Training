// header protection
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/*
 * 7Segment config
 */
#define ZERO   0x40
#define ONE    0x79
#define TWO    0x24
#define THREE  0x30
#define FOUR   0x19
#define FIVE   0x12
#define SIX    0x02
#define SEVEN  0x78
#define EIGHT  0x00
#define NINE   0x10

/*       prototypes      */
void SevSeg_voidInit();
u8 SevSeg_u8CheckSwitches();
void SevSeg_voidDisplayNumber(u8 Copy_u8PortID, u8 copy_u8Number);

#endif
