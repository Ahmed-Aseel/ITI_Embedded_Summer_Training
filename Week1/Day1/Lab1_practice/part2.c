#include <stdio.h>

int main()
{
	// Print full pyramid pattern using printf
	printf("<<< Using printf >>>\n");
	printf("     *\n");
	printf("    ***\n");
	printf("   *****\n");
	printf("  *******\n");
	printf(" *********\n");
	printf("***********\n");
	
	printf("\n<<< Using Loop >>>\n");
	// Print full pyramid pattern using loop
	int rows, spaces;
	for(rows = 1; rows <= 6; rows++)
	{
		for(spaces = 1; spaces <= 6 - rows; spaces++)
		{
			printf(" ");
		}
		
		int i = 1;
		while(i != rows * 2)
		{
			printf("*");
			i++;
		}
		printf("\n");
	}

	/*
		print welcome message then ask the user
		to enter age and display it
	*/
	int age;
	printf("\nHi Ahmed\nEnter your age: ");
	scanf("%d", &age);
	printf("Your age = %d", age);

	return 0;
}