#include <stdio.h>

int main(void)
{
	// Arrays
	// scan 10 elements from the user and print them in reverse
	int arr1[5], i;
	for(i = 0; i < 5; i++)
	{
		printf("Enter element %d: ", i+1);
		scanf("%d", &arr1[i]);
	}
	
	printf("<< Array elements in reverse >>\n");	
	for(i = 4; i >= 0; i--)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	
	// Bubble sort
	int arr2[5], j;
	for(i = 0; i < 5; i++)
	{
		printf("Enter element %d: ", i+1);
		scanf("%d", &arr2[i]);
	}	
	
	printf("<<< Array before sorting >>>\n");
	for(i = 0; i < 5; i++)
	{
		printf("%d ", arr2[i]);
	}
	
	for(i = 0; i < 5 - 1; i++)
	{
		// flag to check if the array is already sorted
		// if no swap happened then array is sorted
		int sorted = 1;
		for(j = 0; j < 5 - i - 1; j++)
		{
			// if the current value is greater than next value then swap
			if(arr2[j] > arr2[j+1])
			{
				int temp = arr2[j];
				arr2[j] = arr2[j+1];
				arr2[j+1] = temp;
				sorted = 0;
			}
		}
		// check the flag at each end of the outer loop
		if(sorted == 1)
			break;
	}
	
	printf("\n<<< Array after sorting >>>\n");
	for(i = 0; i < 5; i++)
	{
		printf("%d ", arr2[i]);
	}	
	printf("\n");

	// Linear search
	int arr3[5], num;
	for(i = 0; i < 5; i++)
	{
		printf("Enter element %d: ", i+1);
		scanf("%d", &arr3[i]);
	}
	
	printf("Enter element you want to search: ");
	scanf("%d", &num);
	for(i = 0; i < 5; i++)
	{
		if(num == arr3[i])
		{
			printf("%d is found at index %d\n", num, i);
			break;
		}
	}
	
	// check if we raech the end of the array
	// then the element no found
	if(i == 5)
	{
		printf("%d not found!!\n", num);		
	}
	
	// Binary search
	
	return 0;
}