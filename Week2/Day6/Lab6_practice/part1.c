#include <stdio.h>

struct data
{
	int x;
	char y;
};

//#pragma pack(1)
struct SEmp
{
	short bonus;
	int salary;
	short id;	
	int deduction;
	
};

typedef struct SEmployee
{
	float salary;
	float bonus;
	float deduction;
	
}SEmp;

typedef struct Data
{
	int min;
	int max;
	
}SData;

SData find_max_min(int* arr, int size);

int main(void)
{
	// user defined data type
	// size of struct
	struct data d;
	printf("Size of struct data = %d\n", sizeof(d));
	
	 
	// packing and padding of struct 
	struct SEmp e;	
	printf("Size of struct SEmployee = %d\n", sizeof(e));
	
	// program to calculate total salary of all employees
	int i; 
	float total = 0;
	SEmp employees[3];
	// loop over array elements
	for(i = 0; i < 3; i++)
	{
		// take data from the user
		printf("Enter data for employee %d \n", i+1);
		printf("Enter salary: ");
		scanf("%f", &employees[i].salary);
		printf("Enter bonus percentage: ");
		scanf("%f", &employees[i].bonus);
		printf("Enter deduction percentage: ");
		scanf("%f", &employees[i].deduction);
		printf("\n");
		total += employees[i].salary * (1 + employees[i].bonus - employees[i].deduction);
	}
	printf("Total = %0.2f\n", total);
	
	// passing array to function 
	// and return a struct containing the max & min num	
	int arr[4];
	// loop over array elements
	for(i = 0; i < 4; i++)
	{
		// take data from the user
		printf("Enter a number: ");
		scanf("%d", &arr[i]);	
	}

	SData temp = find_max_min(arr, 4);
	printf("\nMinimum number = %d\n", temp.min);
	printf("Maximum number = %d\n", temp.max);
	
	return 0;
}

SData find_max_min(int* arr, int size)
{
	SData temp;
	int i, j;
	
	// bubble sort
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

	temp.min = arr[0];
	temp.max = arr[size-1];
	
	return temp;
}