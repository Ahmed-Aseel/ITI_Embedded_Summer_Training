/*
	modify the value of const pointer 
	using double pointer (pointer to pointer)
 */

#include <stdio.h>

int main(void)
{
	int num1 = 5, num2 = 6;
	// make a const pointer (ptr1) point to num1
	int* const ptr1 = &num1;
	
	printf("Value of num1 = %d\n", num1);	
	printf("Value of single pointer = %d\n", *ptr1);
	
/* 	ptr2 is a pointer to pointer points to ptr1
	which points to num1 */
	int** ptr2 = (int**)&ptr1; // type casting address to (int**)
	
/* 	changing the value of const pointer (ptr1) 
	using another pointer (double pointer)
	now ptr1 & ptr2 points to num2 */ 
	*ptr2 = &num2;
	
	printf("Value of num2 = %d\n", num2);	
	printf("Value of double pointer = %d\n", **ptr2);
	printf("New value of single pointer = %d\n", *ptr1);
	
	return 0;
}