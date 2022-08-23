// header protection
#ifndef INTR_INTERFACE_H_
#define INTR_INTERFACE_H_

/*       prototypes      */
void INTR_voidInit(u8 Copy_u8INTR_ID, u8 Copy_u8INTR_Sense);
void EXTI0_SetCallBack(void (*fptr)(void));
void EXTI1_SetCallBack(void (*fptr)(void));
void EXTI2_SetCallBack(void (*fptr)(void));

#endif
