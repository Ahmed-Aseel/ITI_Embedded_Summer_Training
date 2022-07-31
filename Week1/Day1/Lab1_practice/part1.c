#include <stdio.h>

int main()
{
	// Printing Hello World
	printf("Hello World!\n");
	/* 
	   Printing welcome + my name
	   then use format specifier to print an expr
	*/	 
	printf("Welcome Ahmed\n");
	printf("Result = %d\n", 5 + 2);
	
	int num1, num2;
	
	// Taking 2 numbers fom the user
	printf("Enter number1: ");
	scanf("%d", &num1);
	printf("Enter number2: ");
	scanf("%d", &num2);
	
	// Perform arithmetic operations
	printf("\t\t<<< Arithmetic operations >>>\n");
	printf("%d + %d = %d\n", num1, num2, num1 + num2);
	printf("%d - %d = %d\n", num1, num2, num1 - num2);
	printf("%d * %d = %d\n", num1, num2, num1 * num2);
	printf("%d / %d = %d\n", num1, num2, num1 / num2);
	printf("%d %% %d = %d\n", num1, num2, num1 % num2);

	// Perform bitwise operations	
	printf("\t\t<<< Bitwise operations >>>\n");
	printf("%d & %d = %d\n", num1, num2, num1 & num2);
	printf("%d | %d = %d\n", num1, num2, num1 | num2);
	printf("%d ^ %d = %d\n", num1, num2, num1 ^ num2);
	printf("~%d = %d\n", num1, ~num1);
	printf("~%d = %d\n", num2, ~num2);
	printf("%d >> %d = %d\n", num1, 2, num1 >> 2);
	printf("%d << %d = %d\n", num2, 2, num2 << 2);
	
	num1 = 5;
	num2 = 7;
	// Perform rational operations
	printf("\t\t<<< Rational operations >>>\n");
	printf("%d < %d = %d\n", num1, num2, num1 < num2);
	printf("%d > %d = %d\n", num1, num2, num1 > num2);
	
	// Printing the size of different data types
	printf("\t\t<<< Datatypes size >>>\n");
	printf("Size of datatype (int) = %d bytes\n", sizeof(int));
	printf("Size of datatype (char) = %d bytes\n", sizeof(char));
	printf("Size of datatype (float) = %d bytes\n", sizeof(float));
	printf("Size of datatype (double) = %d bytes\n", sizeof(double));
	
	return 0;
}