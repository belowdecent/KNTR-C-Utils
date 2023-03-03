#ifndef _KNDS_LIST_NODE
#define _KNDS_LIST_NODE

#include <stdlib.h>

typedef struct KNDS_List {
	void* data;
	struct KNDS_List* next;	
} KNDS_List;

/*
Creates a list node with the following data and next values.
*/
KNDS_List* KNDS_ListNew(void* data, KNDS_List* next);


/*
Frees this list, applies a data function to the data.
*/
void KNDS_ListFree(KNDS_List* head, void (*data_function)(void*));

/*
Returns the last element of the list;
*/
KNDS_List* KNDS_ListGetLast(KNDS_List* list);

/*
*/
KNDS_List* KNDS_ListGet(KNDS_List* list, size_t position);

/*
Creates a shallow copy of the list.
Does not share nodes with the original list.
Shares the data with the original list.
*/
KNDS_List* KNDS_ListClone(const KNDS_List* list);

/*
Returns the length of a list starting from head
*/
int KNDS_ListLength(const KNDS_List* head);

#endif
