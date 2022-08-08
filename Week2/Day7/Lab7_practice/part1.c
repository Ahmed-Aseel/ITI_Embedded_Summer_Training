#include <stdio.h>
#include <stdlib.h>

#define x 10
#define Get_Bit(num, pos) ((num >> pos) & 1)
#define SIZE 5

int main(void)
{
	printf("x = %d, ", x);
	// macro redefine it will give a warning
	// undefine x first
	#undef x
	#define x 20
	printf("x = %d\n", x);
	
	// get a bit in a certine position 
	int num, pos;
	printf("Enter number: ");
	scanf("%d", &num);
	printf("Enter bit position: ");
	scanf("%d", &pos);
	printf("Bit at position %d = %d\n", pos, Get_Bit(num, pos));
	
	// dynamic allocation
	// allocate elements using malloc take
	//  them from the user and sort them
	int i, j;
	int* arr = (int*)malloc(SIZE * sizeof(int));
	printf("<<< Enter array elements >>>\n");
	for(i = 0; i < SIZE; i++)
	{
		printf("Enter element %d : ", i+1);
		scanf("%d", arr+i);
	}
	
	// bubble sort
	for(i = 0; i < SIZE - 1; i++)
	{
		// flag to check if the array is already sorted
		// if no swap happened then array is sorted
		int sorted = 1;
		for(j = 0; j < SIZE - i - 1; j++)
		{
			// if the current value is greater than next value then swap
			if(arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				sorted = 0;
			}
		}
		// check the flag at each end of the outer loop
		if(sorted == 1)
			break;
	}

	printf("Sorted elements:\n");
	for(i = 0; i < SIZE; i++)
	{
		
		printf("%d ", *(arr+i));
	}
	
	free(arr);
		
	return 0;
}