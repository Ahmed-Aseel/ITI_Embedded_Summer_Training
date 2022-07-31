/*
	Description: prefix & postfix operators
	Author: Ahmed Aseel
*/

// Including libraries
#include <stdio.h>

int main(void)
{
	int num1 = 5, num2 = 7;
	/*
		First it will get the value of num1 (5)
		Then increament the value of num1 (6)
		Then get the new value of num1 (6)
		Finally add the two numbers (5 + 6)
	*/
	printf("num1 = num1++ + num1 = %d\n", num1++ + num1);
	
	/*
		First it will get the value of num2 (7)
		Then decreament the value of num2 (6)
		Then get the new value of num2 (6)
		Finally add the two numbers (7 + 6)
	*/
	printf("num2 = num2-- + num2 = %d\n", num2-- + num2);
	 
	return 0;
}	