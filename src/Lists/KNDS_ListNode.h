#ifndef _KNDS_LIST_NODE
#define _KNDS_LIST_NODE

#include <stdlib.h>

typedef struct KNDS_ListNode {
	void* data;
	struct KNDS_ListNode* next;	
} KNDS_ListNode;

/*
Creates a list node with the following data and next values.
*/
KNDS_ListNode* KNDS_ListNodeNew(void* data, KNDS_ListNode* next);


/*
Frees this node and every node that comes after.
Does not free the data stored within nodes.
Free queues from the "front", stacks from the "top"
*/
void KNDS_ListFree(KNDS_ListNode* head);

/*
Frees this node and every node that comes after along with the stored data.
Free queues from the "front", stacks from the "top"
*/
void KNDS_ListDestroy(KNDS_ListNode* head);

/*
Returns the last element of the list;
*/
KNDS_ListNode* KNDS_ListGetLast(KNDS_ListNode* list);

/*
*/
KNDS_ListNode* KNDS_ListGetNode(KNDS_ListNode* list, size_t position);

/*
Clones the target node and each of the following nodes, forming a new list.
*/
KNDS_ListNode* KNDS_ListClone(const KNDS_ListNode* node);

/*
Returns the length of a list starting from head
*/
int KNDS_ListLength(const KNDS_ListNode* head);

#endif
