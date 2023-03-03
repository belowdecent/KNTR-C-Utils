#ifndef _KNDS_LIST_NODE
#define _KNDS_LIST_NODE

#include <stdlib.h>

typedef struct KNDS_DListNode {
	void* data;
	struct KNDS_DListNode* next;	
	struct KNDS_DListNode* prev;	
} KNDS_DListNode;

/*
Creates a list node with the following data and next values.
*/
KNDS_DListNode* KNDS_DListNodeNew(void* data, 
	KNDS_DListNode* next, KNDS_DListNode* prev);


/*
Frees this node and every connected node.
Does not free the data stored within nodes.
*/
void KNDS_DListFree(KNDS_DListNode* node);

/*
Frees this node and every connected node along with the stored data.
Free queues from the "front", stacks from the "top"
*/
void KNDS_DListDestroy(KNDS_DListNode* node);

/*
Returns the first element of the list;
*/
KNDS_DListNode* KNDS_DListGetFirst(KNDS_DListNode* list);

/*
Returns the last element of the list;
*/
KNDS_DListNode* KNDS_DListGetLast(KNDS_DListNode* list);

/*
*/
KNDS_DListNode* KNDS_DListGetNode(KNDS_DListNode* list, int relative_position);

/*
Clones the target node and each of the following nodes, forming a new list.
*/
KNDS_DListNode* KNDS_DListClone(const KNDS_DListNode* node);

/*
Returns the length of the list
*/
int KNDS_DListLength(const KNDS_DListNode* head);

#endif
