#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// for loop
	// print name and numbers 5 times
	int i;
	for(i = 0; i < 5 ; i++)
	{
		printf("Ahmed --> ");
		printf("%d\n", i);
	}
	
	// sum and avg of 10 numbers
	int num, sum = 0;
	for(i = 0; i < 10 ; i++)
	{
		printf("Enter number %d : ", i + 1);
		scanf("%d", &num);
		sum += num;
	}	
	printf("Sum = %d\nAvg = %0.2f\n", sum, sum / 10.0);

	// while loop
	int num1, num2, res;
	printf("Enter two numbers: ");
	scanf("%d %d", &num1, &num2);
	res = num1 * num2;
	while(res != 15)
	{
		printf("Enter res: ");
		scanf("%d", &res);
	}
	printf("correct answer\n");
	
	// Multiplication table
	printf("Enter a number: ");
	scanf("%d", &num);
	i = 1;
	while(i <= 10)
	{
		printf("%d * %d = %d\n", num, i, num * i);
		i++;
	}
	
	// factorial
	int temp, fact = 1;
	printf("Enter a number: ");
	scanf("%d", &num);
	temp = num;
	do
	{
		if(temp < 0)
		{
			printf("Wrong number!!");
			exit(0);			
		}
		else if(temp == 0)
			break;
		
		fact *= temp;
		temp--;
	}while(temp > 0);

	printf("%d! = %d\n", num, fact);

	return 0;
}