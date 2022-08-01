#include <stdio.h>

int main(void)
{
	int choice, rows, columns, i, j;
	// Asking the user to choose the shape
	printf("\nIf you want to print square press(1) or rectangle press(2): ");
	scanf("%d", &choice);

	switch(choice)
	{
		case 1:
		// Asking the user to input the side length of the square
		printf("Enter the number of rows: ");
		scanf("%d", &rows);		
		for(i = 1; i <= rows; i++)
		{
			for(j = 1; j <= rows; j++)
			{
				// we need only to print (*) at the 1st & last rows and  1st & last columns
				if(i == 1 || i == rows || j == 1 || j == rows)
				{
					printf("*");
				}
				// Other positions print white space
				else
				{
					printf(" ");					
				}
			}
			printf("\n");
		}
		break;
		
		case 2:
		// Asking the user to input the length & width of the rectangle		
		printf("Enter the number of rows: ");
		scanf("%d", &rows);	
		printf("Enter the number of columns: ");
		scanf("%d", &columns);
		for(i = 1; i <= rows; i++)
		{
			for(j = 1; j <= columns; j++)
			{
				// we need only to print (*) at the 1st & last rows and  1st & last columns
				if(i == 1 || i == rows || j == 1 || j == columns)
				{
					printf("*");
				}
				else
				// Other positions print white space
				{
					printf(" ");					
				}
			}
			printf("\n");
		}		
		break;
		
		// If the user enter anything else 1 & 2		
		default:
		printf("Wrong Choice !!");
		break;
	}
	
	return 0;
}