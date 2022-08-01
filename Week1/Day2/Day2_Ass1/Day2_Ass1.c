#include <stdio.h>

int main(void)
{
	// the counter var is to keep the value that will be printed
	int rows, i, j, counter = 1;
	// Asking the user to input #rows
	printf("\nEnter the number of rows of floyd's triangle:\n");
	scanf("%d", &rows);

	/* 
		nested loop the outer loop for the rows
		the inner loop for columns	
	*/
	for(i = 1; i <= rows; i++)
	{
		for(j = 1; j <= i; j++)
		{
			printf("%d ", counter++);
		}
		printf("\n");
	}

	// Another solution without counter var
/* 	for(i = 1; i <= rows; i++)
	{
		for(j = 1; j <= i; j++)
		{
			// This equ describes the relation between
			// the value to be printed and values of i, j
			printf("%d ", ((i-1)*i) / 2 + j);
		}
		printf("\n");
	} */
	
	return 0;
}