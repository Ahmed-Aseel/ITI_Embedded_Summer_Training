#include <stdio.h>

int main(void)
{
	/* Take 5 numbers from the user
	   Then search if the user enter exists or not
	*/
	// Using array
	int i, nums[5], num;
	for(i = 0; i < 5; i++)
	{
		printf("Enter number %d: ", i + 1);
		scanf("%d", &nums[i]);
	}
	
	printf("Enter number to search: ");
	scanf("%d", &num);
	
	for(i = 0; i < 5; i++)
	{
		if(num == nums[i])
			break;
	}
	
	if(i != 5)
		printf("value is exist at element number %d\n", i + 1);
	else
		printf("value not found!!\n");
	
	// Another solution using variables and if statement
	int num1, num2, num3, num4, num5;
	printf("Enter number 1 : ");
	scanf("%d", &num1);
	printf("Enter number 2 : ");
	scanf("%d", &num2);
	printf("Enter number 3 : ");
	scanf("%d", &num3);
	printf("Enter number 4 : ");
	scanf("%d", &num4);
	printf("Enter number 5 : ");
	scanf("%d", &num5);

	printf("Enter value : ");
	scanf("%d", &num);
	
	if(num == num1)
		printf("element number 1\n");
	else if(num == num2)
		printf("element number 2\n");
	else if(num == num3)
		printf("element number 3\n");	
	else if(num == num4)
		printf("element number 4\n");
	else if(num == num5)
		printf("element number 5\n");
	else
		printf("not found!!!\n");

	// Another solution using variables and switch statement	
	switch(num)
	{
		default:

		case 1:
		if(num == num1)
		{
			printf("element number 1\n");
			break;
		}
		case 2:
		if(num == num2)
		{
			printf("element number 2\n");
			break;
		}
		case 3:
		if(num == num3)
		{
			printf("element number 3\n");
			break;
		}
		case 4:
		if(num == num4)
		{
			printf("element number 4\n");
			break;
		}
		case 5:
		if(num == num5)
		{
			printf("element number 5\n");
			break;
		}
	}

	// print day corresponding to user input
	int day;
	printf("Enter a day between 1 & 7 : ");
	scanf("%d", &day);
	switch(day)
	{
		case 1:
		printf("Saturday\n");
		break;
		
		case 2:
		printf("Sunday\n");
		break;
		
		case 3:
		printf("Monday\n");
		break;
	
		case 4:
		printf("Tuesday\n");
		break;
	
		case 5:
		printf("Wednesday\n");
		break;
	
		case 6:
		printf("Thursday\n");
		break;
	
		case 7:
		printf("Friday\n");
		break;
			
		default:
		printf("not found");
	}	
	
	// Take 2 numbers from the user and display result infinitly
	while(1)
	{
		printf("Enter number 1 : ");
		scanf("%d", &num1);
		printf("Enter number 2 : ");
		scanf("%d", &num2);
		printf("res = %d\n", num1 + num2);
	}
	
	return 0;
}