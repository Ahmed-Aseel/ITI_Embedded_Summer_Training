// header protection
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>

#define Dprintf(...)     {fflush(stdin);\
						  fflush(stdout);\
						  printf(__VA_ARGS__);\
						  fflush(stdin);\
						  fflush(stdout);}

// Variables
typedef struct Node Node;

struct Node
{
	int Data;
	Node* Next;
};

// Functions
Node* LKL_CreateNode(int Data);
void LKL_InsertAtFirst();
void LKL_InsertAtLast();
void LKL_SearchList();
void LKL_DeleteNode();
void LKL_ListLength();
void LKL_PrintList();
void LKL_DeleteAll();

#endif