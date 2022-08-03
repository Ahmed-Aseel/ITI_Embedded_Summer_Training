#include <stdio.h>
#include <stdlib.h>

int power(int base, int pow);
void add(int num1, int num2, int* res);
void swap(int* num1, int* num2);
void sum_array(int *arr, int size, int* res);

int main(void)
{
	// Revision
	// func to return power
	int num, pow, res1;
	printf("Enter number: ");
	scanf("%d", &num);
	printf("Enter power: ");
	scanf("%d", &pow);
	
	res1 = power(num, pow);
	printf("%d ** %d = %d\n", num, pow, res1);

	// pointers
	int x = 5, *ptr;
	ptr = &x;
	printf("value of x using var = %d\n", x);
	printf("Address of x using var = 0x%p\n", &x);
	printf("value of x using pointer = %d\n", *ptr);
	printf("Address of x using pointer = 0x%p\n", ptr);
	printf("Address of pointer = 0x%p\n", &ptr);

	// pointers with functions
	// add 2 numbers without return
	int num1, num2, res2;
	printf("Enter number1 : ");
	scanf("%d", &num1);
	printf("Enter number2 : ");
	scanf("%d", &num2);
	add(num1, num2, &res2);
	printf("res = %d\n", res2);
	
	// swap using pass by referance
	printf("Enter number1 : ");
	scanf("%d", &num1);
	printf("Enter number2 : ");
	scanf("%d", &num2);
	printf("Before swap\n");
	printf("%d ", num1);
	printf("%d\n", num2);
	
	swap(&num1, &num2);
	printf("After swap\n");
	printf("%d ", num1);
	printf("%d\n", num2);

	// func to sum array elements without return
	int arr[5] = {1,2,3,4,5}, res3 = 0;
	sum_array(arr, 5, &res3);
	printf("Sum of array elements = %d\n", res3);

	return 0;
}

int power(int base, int pow)
{
	int res = 1;
	if(base == 0 && pow == 0)
	{
		printf("Undefined\n");
		exit(0);
	}
	while(pow)
	{
		res *= base;
		pow--;
	}
	
	return res;
}

void add(int num1, int num2, int* res)
{
	*res = num1 + num2;
}

void swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void sum_array(int *arr, int size, int* res)
{
	int i;
	for(i = 0; i < size; i++)
	{
		*res += arr[i];
	}
}