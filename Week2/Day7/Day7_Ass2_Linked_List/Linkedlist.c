#include "Linkedlist.h"

Node* Head = NULL;
Node* Tail = NULL;

Node* LKL_CreateNode(int Data)
{
	// dynamic allocation of siae struct Node
	Node* new = (Node*)malloc(sizeof(Node));
	// store data into ptr
	// make next of ptr point to null
	new->Data = Data;
	new->Next = NULL;
	// return address of the new node
	return new;
}

void LKL_InsertAtFirst()
{
	int Data;
	Dprintf("Enter data you want to insert : ");
	scanf("%d", &Data);
	// create a new node
	Node* ptr = LKL_CreateNode(Data);
	// check if list empty ?
	if(!Head)
	{
		// make tail point to the new node
		Tail = ptr;
	}
	// if list is not empty
	else
	{
		// make next of the new node point to the first node
		ptr->Next = Head;
	}
	// make head point to the new node
	// then the new node becomes the first node
	Head = ptr;	
}

void LKL_InsertAtLast()
{
	int Data;
	Dprintf("Enter data you want to insert : ");
	scanf("%d", &Data);
	// create a new node	
	Node* ptr = LKL_CreateNode(Data);
	// check if list empty ?
	if(!Head)
	{
		// make head point to the new node
		Head = ptr;
	}
	// if list is not empty
	else
	{
		// make next of the last node point to the new node
		Tail->Next = ptr;
	}
	// make tail point to the new node
	// then the new node becomes the last node	
	Tail = ptr;
}

void LKL_SearchList()
{
	// count var to indicate at which node data was found
	int Data, count = 1, found = 0;
	Dprintf("Enter data you want to search : ");
	scanf("%d", &Data);
	Node* temp = Head;
	// check if the list empty ?
	if(!temp)
	{
		Dprintf("<<< List Is Empty >>>\n");
	}
	else
	{
		// loop over all nodes
		while(temp)
		{
			// check if the current node data == input data
			if(temp->Data == Data)
			{
				Dprintf("<<< %d found at node %d >>>\n", Data, count);
				found = 1; //set var found
				// once find data break
				break;
			}
			
			count++;
			temp = temp->Next;
		}
		// check if the data found or not ?
		if(!found)
		{
			Dprintf("<<< %d does not exist in list >>>\n", Data);
		}
	}	
}
void LKL_DeleteNode()
{
	int Data, found = 0;
	Dprintf("Enter data you want to delete : ");
	scanf("%d", &Data);	
	Node* selected = Head;
	Node* prev = NULL;
	// check if the list empty ?
	if(!selected)
	{
		Dprintf("<<< List Is Empty >>>\n");
	}
	else
	{
		// loop over all nodes
		while(selected)
		{
			// check if the current node data == input data
			if(selected->Data == Data)
			{
				if(!selected->Next) // if the last node is to be deleted
				{
					// make tail point to the previous node
					Tail = prev;
				}
				// if the first & last node are not the selected
				if(prev) 
				{
				// make next of the previous node point to the next of the selected node					
					prev->Next = selected->Next;
				}

				else // if the first node is to be deleted
				{
					// make head point to the next node
					Head = selected->Next;
				}
				
				found = 1; //set var found
				free(selected);
				Dprintf("<<< %d found and deleted >>>\n", Data);
				// once delete data break
				break;
			}
			
			prev = selected;
			selected = selected->Next;
		}
		// check if the data found or not ?
		if(!found)
		{
			Dprintf("<<< %d does not exist in list >>>\n", Data);
		}
	}
}

void LKL_ListLength()
{
	int length = 0;
	Node* temp = Head;
	// loop over all nodes
	while(temp)
	{
		// increament length and make
		// temp point to the next node 
		length++;
		temp = temp->Next;
	}

	Dprintf("Length of the list =  %d \n", length);
}

void LKL_PrintList()
{
	Node* current = Head;
	// check if the list empty ?
	if(!current)
	{
		Dprintf("<<< List Is Empty >>>\n");
	}
	
	else
	{
		Dprintf("<<< List Data >>>\n");
		// loop over all nodes
		while(current)
		{
			Dprintf("\t %d\n", current->Data);
			current = current->Next;
		}	
	}
}

void LKL_DeleteAll()
{
	Node* current = Head;
	Node* temp = NULL;
	// check if the list empty ?
	if(!current)
	{
		Dprintf("<<< List Is Empty >>>\n");
	}

	else
	{
		// loop over all nodes
		while(current)
		{
			temp = current;
			current = current->Next;
			free(temp);
		}
		// initialize head & tail with null
		Head = NULL;
		Tail = NULL;
		Dprintf("<<< All nodes deleted successfully >>>\n");
	}
}