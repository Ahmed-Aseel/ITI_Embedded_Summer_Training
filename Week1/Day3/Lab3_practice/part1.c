#include <stdio.h>
// functions prototype
float add(float num1, float num2);
float sub(float num1, float num2);
float mul(float num1, float num2);
float div(float num1, float num2);
float cal(float num1, float num2, char op);
void swap(void);
int fact(int num);
// global variables
int num7, num8;

int main(void)
{
	// Revision
	// print the max of 3 numbers
	int num1, num2, num3;
	printf("Enter number 1: ");
	scanf("%d", &num1);
	printf("Enter number 2: ");
	scanf("%d", &num2);	
	printf("Enter number 3: ");
	scanf("%d", &num3);	

	// check if num1 is greater than num3
	if(num1 > num2)
	{
		// if num1 also greater than num3 
		// then print num1 
		if(num1 > num3)
		{
			printf("Max number is %d\n", num1);
		}
		
		// but if num3 is greater than num1
		// then print num3
		else
		{
			printf("Max number is %d\n", num3);			
		}
	}
	
	else
	{
		// but if num2 is greater than num1
		// then check if num2 greater than num3
		// then print the larger number
		if(num2 > num3)
		{
			printf("Max number is %d\n", num2);
		}
		
		else
		{
			printf("Max number is %d\n", num3);			
		}
	}
	
	// raed specific bit
	int num4, bit, res1;
	printf("Enter number: ");
	scanf("%d", &num4);
	printf("Enter bit you want to read: ");
	scanf("%d", &bit);
/* 	shift the number to right by value of bit
	then bitwise and with on if this bit is 0 res is 0
	and if this bit is 1 res is 1 */
	res1 = (num4 >> bit) & 1; 
	printf("The value of bit %d is %d\n", bit, res1);
	
	// Functions
	// func to multiply 2 numbers
	float num5, num6, res2;
	printf("Enter number 1: ");
	scanf("%f", &num5);
	printf("Enter number 2: ");
	scanf("%f", &num6);
	res2 = mul(num5, num6);
	printf("res = %0.2f\n", res2);

	// simple calculator using func
	char op;
	printf("Enter number 1: ");
	scanf("%f", &num5);
	printf("Enter number 2: ");
	scanf("%f", &num6);
	printf("Enter operator: ");
	scanf(" %c", &op);	
	res2 = cal(num5, num6, op);
	printf("res = %0.2f\n", res2);
	
	// func to swap 2 numbers using global vars
	printf("Enter number 1: ");
	scanf("%d", &num7);
	printf("Enter number 2: ");
	scanf("%d", &num8);
	printf("<<<< Before swap >>>>\n");
	printf("num1 = %d\n", num7);
	printf("num2 = %d\n", num8);	
	swap();
	printf("<<<< After swap >>>>\n");
	printf("num1 = %d\n", num7);
	printf("num2 = %d\n", num8);
	
	// factorial using recursion
	int num9;
	printf("Enter number: ");
	scanf("%d", &num9);
	printf("factorial = %d", fact(num9));

	return 0;
}

// functions definition

float add(float num1, float num2)
{
	float res;
	res = num1 + num2;
	return res;
}

float sub(float num1, float num2)
{
	float res;
	res = num1 - num2;
	return res;
}

float mul(float num1, float num2)
{
	float res;
	res = num1 * num2;
	return res;
}

float div(float num1, float num2)
{
	float res;
	res = num1 / num2;
	return res;
}

float cal(float num1, float num2, char op)
{
	float res;
	switch(op)
	{
		case '+':
		res = add(num1, num2);
		break;
		case '-':
		res = sub(num1, num2);
		break;
		
		case '*':
		res = mul(num1, num2);
		break;

		case '/':
		res = div(num1, num2);
		break;
	}
	
	return res;
}

void swap(void)
{
	int temp = num7;
	num7 = num8;
	num8 = temp;
}


int fact(int num)
{
	if(num == 0)
		return 1;
	
	return (num * fact(num - 1));
}