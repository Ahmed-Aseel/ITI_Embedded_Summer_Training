// incuding libraries
#include <stdio.h>
#include "file2.h"

int main(void)
{
	int arr[5] = {1,2,3,4,5}, res = 0;
	sum_array(arr, 5, &res);
	printf("Sum of array elements = %d\n", res);
	
	return 0;
}