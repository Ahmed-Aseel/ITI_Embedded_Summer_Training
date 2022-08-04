#include <stdio.h>

int main(void)
{
	// C modifiers
	// print the -ve value of the number
	// that user entered
	signed int num;
	printf("Enter number: ");
	scanf("%d", &num);
	// the neg = 2's complement of the number = 1's complement of the number + 1
	printf("The negative value of %d = %d\n\n", num, ~num + 1);
	
	// datatypes size
	printf("Size of (char) = %d\n", sizeof(char));	
	printf("Size of (short) = %d\n", sizeof(short));
	printf("Size of (long) = %d\n", sizeof(long));
	printf("Size of (int) = %d\n", sizeof(int));
	printf("Size of (float) = %d\n", sizeof(float));
	printf("Size of (double) = %d\n", sizeof(double));
	printf("Size of (long double) = %d\n\n", sizeof(long double));	
	
	// const && double pointer (pointer to pointer)
	int x = 5;
	int y = 6;
	int *const p1 = &x;
	printf("Value of single pointer = %d\n", *p1);
	
	int **p2 = &p1;
	// changing the value of p1 using double pointer
	*p2 = &y;
	
	printf("Value of double pointer = %d\n", **p2);
	printf("New value of single pointer = %d\n", *p1);
	
	return 0;
}