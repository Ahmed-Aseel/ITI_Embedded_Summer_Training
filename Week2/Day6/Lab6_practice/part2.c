#include <stdio.h>

// bit field
struct field
{
	unsigned char a:3;
	unsigned char b:3;
	unsigned char c:2;
};

union UEmp
{
	unsigned char id1;
	unsigned char id2;
	unsigned short salary;
};

// enum
enum w {x, y = -1, z};


int main(void)
{
	struct field f1;
	// over flow will happen 
	// the extera bit will not be stored 
	// in the next member of the bit field
	f1.a = 9;
	printf("a = %d  b = %d\n", f1.a, f1.b);
	
	// union
	union UEmp emp1;
	emp1.id1 = 5;
	// yhe size of union = the size of the largest data type
	printf("Size of union UEmp = %d\n", sizeof(emp1));
	// both id1 & id2 share the first byte
	printf("id1 = %d, id2 = %d\n", emp1.id1, emp1.id2);
	
	// print enum
	printf("Size of enum = %d\n", sizeof(enum w));
	printf("x = %d, y = %d, z = %d\n", x, y, z);
	
	return 0;
}