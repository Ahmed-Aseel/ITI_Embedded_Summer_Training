// including libraries
#include <stdio.h>
#include <stdlib.h> // to use malloc and free

// functions prototype
int count_digits(unsigned int num);
void conver_to_array(unsigned int num, int size);
void bubble_sort(int arr[], int size);
void print_array(int arr[], int size);

int main(void)
{
	unsigned int num;
	int digits;
	// ask the user to enter a number
	printf("Enter a number: ");
	scanf("%d", &num);	
	
	// counting and printing the number of digits
	digits = count_digits(num);
	printf("Number of digits: %u\n", digits);

	// convert the user number to array of integers to sort
	conver_to_array(num, digits);
	
	return 0;
}

// functions definition

int count_digits(unsigned int num)
{
	int count = 0;
	do
	{
		num /= 10;
		count++;
	}while(num);
	
	return count;
}

void conver_to_array(unsigned int num, int size)
{
	// dynamic allocation with size = number of digits * size(int)
	// as we cant use static allocation with variable size
	int* arr = (int*) malloc(size * sizeof(int));
	// check if the memory has been allocated successfully
	if(arr == NULL)
	{
		printf("Failed to allocate memory\n");
		exit(0);
	}
	
	int mod, i = 0;
	do
	{
		mod = num % 10;
		// filling array
		arr[i] = mod;
		num /= 10;
		i++;
	}while(num);	
	
	// sortin array
	bubble_sort(arr, size);
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
	
	// print the sorted number
	print_array(arr, size);
}

void print_array(int arr[], int size)
{
	int i;
	printf("Number after sorting: ");
	for(i = 0; i < size; i++)
	{
		printf("%d", arr[i]);
	}	
	printf("\n");
	
	// free dynamic allocation
	free(arr);	
}