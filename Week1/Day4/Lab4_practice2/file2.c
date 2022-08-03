#include "file2.h"

// function definition
void sum_array(int *arr, int size, int* res)
{
	int i;
	for(i = 0; i < size; i++)
	{
		*res += arr[i];
	}
}