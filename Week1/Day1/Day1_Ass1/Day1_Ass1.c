/*
	Description: Code takes 2 numders and performs various operations
	Author: Ahmed Aseel
*/

// Including libraries
#include <stdio.h>

int main(void)
{
	// Variables declaration
	int a, b;
	
	// Asking the user to input the 1st number
	printf("Please enter number a: ");
	// Taking the 1st number from the user
	scanf("%d", &a);
	
	// Asking the user to input the 2nd number
	printf("Please enter number b: ");
	// Taking the 2nd number from the user
	scanf("%d", &b);
	
	// Arithmetic operations
	printf("\t\t<<< Arithmetic operations >>>\n");
	printf("a + b = %d\n", a + b);
	printf("a - b = %d\n", a - b);
	printf("a * b = %d\n", a * b);
	printf("a / b = %d\n", a / b);
	printf("a %% b = %d\n", a % b);

	// Bitwise operations
	printf("\t\t<<< Bitwise operations >>>\n");
	printf("a & b = %d\n", a & b);
	printf("a | b = %d\n", a | b);
	printf("a ^ b = %d\n", a ^ b);
	printf("~a = %d\n", ~a);
	printf("~b = %d\n", ~b);
	
	// Logical operations
	printf("\t\t<<< Logical operations >>>\n");
	printf("a && b = %d\n", a && b);
	printf("a || b = %d\n", a || b);
	printf("!a = %d\n", !a);
	printf("!b = %d\n", !b);	

	// Rational operations
	printf("\t\t<<< Rational operations >>>\n");
	printf("a < b = %d\n", a < b);
	printf("a != b = %d\n", a != b);
	
	return 0;
}