#ifndef _KNDS_LIST_NODE
#define _KNDS_LIST_NODE

typedef struct KNDS_ListNode {
	void* data;
	struct KNDS_ListNode* next;	
} KNDS_ListNode;

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

#endif
