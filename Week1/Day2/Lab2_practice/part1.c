#include <stdio.h>

int main(void)
{
	// Revision
	int x = 7, y = 4, z, k, m, l, n;
	z = x& y;
	k = x| y;
	m = x ^ y;
	l = x >> 1;
	n = y << 2;
	printf("z = %d\n", z);
	printf("k = %d\n", k);	
	printf("m = %d\n", m);	
	printf("l = %d\n", l);
	printf("n = %d\n", n);
	
	// if condition
	int num;
	printf("Enter value: ");
	scanf("%d", &num);
	if(num == 5)
	{
		printf("Welcome Ahmed\n");
	}
	
	// if else & nested if
	int ID;
	printf("Enter ID: ");
	scanf("%d", &ID);
	if(ID == 1)
	{
		printf("Ahmed\n");
	}
	else
	{
		if(ID == 2)
		{
			printf("Elsayed\n");
		}
		else
		{
			if(ID == 3)
			{
				printf("Aya\n");
			}
			else
			{
				printf("Wrong ID!!!\n");
			}
		}
	}
	
	// if elseif else
	if(ID == 1)
	{
		printf("Ahmed\n");
	}
	else if(ID == 2)
	{
		printf("Elsayed\n");
	}
	else if(ID == 3)
	{
		printf("Aya\n");
	}
	else
	{
		printf("Wrong ID!!!\n");
	}

	// Even or Odd check
	printf("Enter a number: ");
	scanf("%d", &num);
	// Using mod
	if(num % 2 == 0)
	{
		printf("%d is even\n", num);
	}
	else
	{
		printf("%d is odd\n", num);
	}

	// Using bitwise and	
	if((num & 1) == 0)
	{
		printf("%d is even\n", num);
	}
    else
	{
		printf("%d is odd\n", num);
	}
	
	// student garde
	int grade;
	printf("Enter your grade: ");
	scanf("%d", &grade);
	if(grade < 0 || grade > 100)
	{
		printf("Wrong entery!!!\n");
	} 
	else if(grade < 50)
	{
		printf("fail\n");
	}
	else if(grade < 65)
	{
		printf("pass\n");
	}
	else if(grade < 75)
	{
		printf("good\n");
	}
	else if(grade < 85)
	{
		printf("very good\n");
	}
	else if(grade <= 100)
	{
		printf("excellent\n");
	}

	// switch statement
	printf("Enter ID: ");
	scanf("%d", &ID); 
	switch(ID)
	{
		case 1112:
		printf("welcome elsayed\n");
		break;
		
		case 2396:
		printf("welcome ahmed\n");
		break;
		
		case 5678:
		printf("welcome aya\n");
		break;
		
		default:
		printf("welcome anyone %d\n", ID);
		break;
	}
	
	// various operations using switch (+ - * /)
	int num1, num2;
	char op;
	printf("Enter two numbers: ");
	scanf("%d %d", &num1, &num2); 
	printf("Enter operator: ");
	scanf(" %c", &op);
	switch(op)
	{
		case '+':
		printf("sum = %d\n", num1 + num2);
		break;
		
		case '-':
		printf("sub = %d\n", num1 - num2);
		break;
		
		case '*':
		printf("mul = %d\n", num1 * num2);
		break;

		case '/':
		printf("div = %d\n", num1 / num2);
		break;
		
		default:
		printf("wrong operation\n");
		break;
	}	

	return 0;
}