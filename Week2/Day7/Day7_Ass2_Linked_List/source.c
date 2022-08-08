#include "Linkedlist.h"

int main()
{
	int option;
	while(1)
	{
		Dprintf("-----------------------\n");
		Dprintf("Choose one of the following options \n");
		Dprintf("1: Insert At First \n");
		Dprintf("2: Insert At Last \n");
		Dprintf("3: Search List \n");
		Dprintf("4: Delete Node \n");
		Dprintf("5: List Length \n");
		Dprintf("6: Print List \n");
		Dprintf("7: Delete All Nodes \n");
		Dprintf("8: Exit \n");
		Dprintf("Enter your option : ");
		scanf("%d", &option);
		Dprintf("-----------------------\n");

		switch(option)
		{
		case 1:
			LKL_InsertAtFirst();
			break;

		case 2:
			LKL_InsertAtLast();
			break;

		case 3:
			LKL_SearchList();
			break;

		case 4:
			LKL_DeleteNode();
			break;

		case 5:
			LKL_ListLength();
			break;

		case 6:
			LKL_PrintList();
			break;

		case 7:
			LKL_DeleteAll();
			break;

		case 8:
			Dprintf("<<< THANK YOU >>>\n");
			exit(0);
			break;

		default:
			Dprintf("<<< Wrong Choice!!! >>>\n");
			break;
		}
	}
	
	return 0;
}