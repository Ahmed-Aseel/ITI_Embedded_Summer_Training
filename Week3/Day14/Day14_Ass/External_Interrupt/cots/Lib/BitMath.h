// header protection
#ifndef BITMATH_H_
#define BITMATH_H_

#define read_bit(reg, bit) ((reg >> bit) & 1)
#define clear_bit(reg, bit) (reg &= ~(1 << bit))
#define set_bit(reg, bit) (reg |= (1 << bit))
#define toggle_bit(reg, bit) (reg ^= (1 << bit))

#endif
