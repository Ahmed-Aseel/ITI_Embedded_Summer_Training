#include <stdio.h>
#include "BitMath.h"

int main()
{
	int num, pos;
	printf("Enter a number: ");
	scanf("%d", &num);
	printf("Enter bit position: ");
	scanf("%d", &pos);

	printf("Bit at position %d in the number = %d\n", pos, read_bit(num, pos));
	printf("After clearing bit %d ---> number = %d\n", pos, clear_bit(num, pos));
	printf("After setting bit %d ---> number = %d\n", pos, set_bit(num, pos));
	printf("After toggling bit %d ---> number = %d\n", pos, toggle_bit(num, pos));
	
	return 0;
}