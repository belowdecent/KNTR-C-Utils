#ifndef _KNDS_LIST_NODE
#define _KNDS_LIST_NODE

#include <stdlib.h>

typedef struct KNDS_List {
	void* data;
	struct KNDS_List* next;	
	struct KNDS_List* prev;	
} KNDS_List;

/*
Creates a list node with the following data and next values.
*/
KNDS_List* KNDS_ListNew(void* data, 
	KNDS_List* next, KNDS_List* prev);

/*
Returns the end of the list from which the argument was split from.
-a-a-(a)-a-a- => -a-a- & -(a)-a-a-
*/
KNDS_List* KNDS_DListSplit(KNDS_List* list);

/*
Frees this node and every connected node.
Does not free the data stored within nodes.
*/
void KNDS_DListFree(KNDS_List* node, void (*data_function)(void*));

/*
Returns the first element of the list;
*/
KNDS_List* KNDS_DListGetFirst(KNDS_List* list);

/*
Returns the last element of the list;
*/
KNDS_List* KNDS_DListGetLast(KNDS_List* list);

/*
*/
KNDS_List* KNDS_DListGetNode(KNDS_List* list, int relative_position);

/*
Clones the target node and each of the following nodes, forming a new list.
*/
KNDS_List* KNDS_DListClone(const KNDS_List* node);

/*
Returns the length of the list
*/
int KNDS_DListLength(const KNDS_List* head);

#endif
