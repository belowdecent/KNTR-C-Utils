#ifndef _KNDS_DLIST_NODE
#define _KNDS_DLIST_NODE

#include <stdlib.h>

typedef struct KNDS_DList {
	void* data;
	struct KNDS_DList* next;	
	struct KNDS_DList* prev;	
} KNDS_DList;

/*
Creates a list node with the following data and next values.
*/
KNDS_DList* KNDS_DListNew(void* data, 
	KNDS_DList* next, KNDS_DList* prev);

/*
Frees this node and every connected node.
Does not free the data stored within nodes.
*/
void KNDS_DListFree(KNDS_DList* node);

/*
Frees this node and every connected node along with the stored data.
Free queues from the "front", stacks from the "top"
*/
void KNDS_DListDestroy(KNDS_DList* node);

/*
Returns the first element of the list;
*/
KNDS_DList* KNDS_DListGetFirst(KNDS_DList* list);

/*
Returns the last element of the list;
*/
KNDS_DList* KNDS_DListGetLast(KNDS_DList* list);

/*
*/
KNDS_DList* KNDS_DListGetNode(KNDS_DList* list, int relative_position);

/*
Creates a shallow copy of the list!
*/
KNDS_DList* KNDS_DListClone(const KNDS_DList* node);

/*
*/

/*
Returns the length of the list
*/
int KNDS_DListLength(const KNDS_DList* head);

#endif
