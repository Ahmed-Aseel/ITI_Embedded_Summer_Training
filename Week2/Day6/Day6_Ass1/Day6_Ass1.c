/*
	Description: Simple C program to implement employees data structure
	Author: Ahmed Aseel
*/

#include <stdio.h>
#include <string.h>

// size of the array
#define SIZE 4

// user defined data types
typedef struct data
{
	int day;
	int month;
	int year;
	
}SDate_t;

typedef struct employee
{
	int ID;
	char Name[15];
	SDate_t DateOfBirth;
	float salary;
	float bonus;
		
}SEmployee_t;

int main(void)
{
	int i;
	// temp var to hold total employee salary
	// total var to hold the total salary of all employees
	float temp, total = 0;	
	
	// array of struct employee
	SEmployee_t employees[SIZE];
	// loop over array elements
	for(i = 0; i < SIZE; i++)
	{
		// take data from the user
		printf("<<< Enter data for employee %d >>>\n", i+1);
		printf("Enter mployee ID: ");
		scanf("%d", &employees[i].ID);
		fflush(stdin); fflush(stdout);
		printf("Enter employee Name: ");
		gets(employees[i].Name);
		printf("Enter employee birth date(xx-yy-zzzz): ");
		scanf("%d-%d-%d", &employees[i].DateOfBirth.day, &employees[i].DateOfBirth.month, &employees[i].DateOfBirth.year);		
		printf("Enter employee salary: ");
		scanf("%f", &employees[i].salary);
		// take the bonus as a percentage of the salary
		printf("Enter employee bonus(as %% and could be -ve) : ");
		scanf("%f", &employees[i].bonus);		
		printf("\n");
	}

	printf("<<< Data of all employees >>>\n");
	for(i = 0; i < SIZE; i++)
	{
		printf("Employee ID: %d\n", employees[i].ID);
		printf("Employee Name: %s\n", employees[i].Name);
		printf("Employee Date Of Birth: %d//%d//%d\n", employees[i].DateOfBirth.day, employees[i].DateOfBirth.month, employees[i].DateOfBirth.year);
		// calculate employee total salary by adding bonus
		temp = employees[i].salary * (1 + employees[i].bonus);
		// increament total by addig each employee total salary
		total += temp; 
		printf("Employee Total Salary: %0.2f\n", temp);
		printf("-------------------------\n");
	}
	
	printf("Total Employees Salary: %0.2f\n", total);

	return 0;
}