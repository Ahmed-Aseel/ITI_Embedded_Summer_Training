// header protection
#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_

#define STOP  0x00
#define RIGHT 0x01
#define LEFT  0x02

/*       prototypes      */
void Motor_voidInit();
void Motor(u8 Copy_u8State);

#endif
