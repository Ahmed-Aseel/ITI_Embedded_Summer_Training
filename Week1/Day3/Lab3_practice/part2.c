#include <stdio.h>

void bubble_sort(int arr[], int size);
int binary_search(int arr[], int size, int num);

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
	
	bubble_sort(arr2, 5);
	
	printf("\n<<< Array after sorting >>>\n");
	for(i = 0; i < 5; i++)
	{
		printf("%d ", arr2[i]);
	}	
	printf("\n");

	// Linear search
	int arr3[5], num1;
	for(i = 0; i < 5; i++)
	{
		printf("Enter element %d: ", i+1);
		scanf("%d", &arr3[i]);
	}
	
	printf("Enter element you want to search: ");
	scanf("%d", &num1);
	for(i = 0; i < 5; i++)
	{
		if(num1 == arr3[i])
		{
			printf("%d is found at index %d\n", num1, i);
			break;
		}
	}
	
	// check if we raech the end of the array
	// then the element no found
	if(i == 5)
	{
		printf("%d not found!!\n", num1);		
	}
	
	// Binary search
	int arr4[5], num2, found;
	for(i = 0; i < 5; i++)
	{
		printf("Enter element %d: ", i+1);
		scanf("%d", &arr4[i]);
	}	
	
	printf("Enter element you want to search: ");
	scanf("%d", &num2);
	
	bubble_sort(arr4, 5);
	found = binary_search(arr4, 5, num2);
	if(found)
	{
		printf("%d is found\n", num2);
	}
	else
	{
		printf("%d not found!!!\n", num2);
	}		

	return 0;
}

void bubble_sort(int arr[], int size)
{
	int i, j;
	for(i = 0; i < size - 1; i++)
	{
		// flag to check if the array is already sorted
		// if no swap happened then array is sorted
		int sorted = 1;
		for(j = 0; j < size - i - 1; j++)
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
}

int binary_search(int arr[], int size, int num)
{
	int start = 0, end = size - 1, mid;
	int found = 0;
	while(start <= end)
	{
		mid = (start + end) / 2;
		if(num == arr[mid])
		{
			return 1;
		}
		
		else if(num < arr[mid])
		{
			end = mid - 1;
		}
		
		else
		{
			start = mid + 1;
		}
	}
	
	return 0;
}