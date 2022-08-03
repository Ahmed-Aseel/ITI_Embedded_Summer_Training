#include <stdio.h>

// function prototype
void str_length(char *str, int *length);

int main(void)
{
	char str[20];
	int length = 0;
	
	// ask the user to input a string
	printf("Enter a string: ");
	scanf("%s", str);
	
	/* 
		function call to calculate the length of 
		the input string and store the value in length var
		which is passed by referance
	*/
	str_length(str, &length);
	printf("length of string (%s) = %d\n", str, length);

	return 0;
}

// function declaration
void str_length(char *str, int *length)
{
	// loop until the value pointed by str is null
	while(*str)
	{
		/* 
			increament length and 
			make pointer points to the next char
		*/
		++*length;
		str++;
	}
}

