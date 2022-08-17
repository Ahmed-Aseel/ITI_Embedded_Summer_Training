// header protection
#ifndef INTR_PRIVATE_H_
#define INTR_PRIVATE_H_

#define SREG_REG     *((volatile u8*)0x5F)
#define GICR_REG     *((volatile u8*)0x5B)
#define MCUCR_REG    *((volatile u8*)0x55)
#define MCUCSR_REG   *((volatile u8*)0x54)

#endif
