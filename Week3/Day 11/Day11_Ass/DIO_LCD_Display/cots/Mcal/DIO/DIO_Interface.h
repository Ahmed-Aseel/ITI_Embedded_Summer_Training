// header protection
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*
 * Port ID Macros
 */
#define PORTA_ID  (0x00)
#define PORTB_ID  (0x01)
#define PORTC_ID  (0x02)
#define PORTD_ID  (0x03)

/*
 * Pin ID Macros
 */
#define PIN0_ID  (0x00)
#define PIN1_ID  (0x01)
#define PIN2_ID  (0x02)
#define PIN3_ID  (0x03)
#define PIN4_ID  (0x04)
#define PIN5_ID  (0x05)
#define PIN6_ID  (0x06)
#define PIN7_ID  (0x07)

/*
 * Direction Macros
 */
#define PIN_INPUT_ID   (0x00)
#define PIN_OUTPUT_ID  (0x01)


/*
 * Pin Output Value
 */
#define PIN_LOW   (0x00)
#define PIN_HIGH  (0x01)

/*       prototypes      */
void DIO_voidSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PINID, u8 Copy_u8PINDIR);
void DIO_voidSetPinValue(u8 Copy_u8PortID, u8 Copy_u8PINID, u8 Copy_u8PINValue);
void DIO_voidSetPortDirection(u8 Copy_u8PortID, u8 Copy_u8PORTDIR);
void DIO_voidSetPortValue(u8 Copy_u8PortID, u8 Copy_u8PORTValue);

#endif
