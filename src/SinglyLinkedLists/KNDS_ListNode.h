#ifndef _KNDS_LIST_NODE
#define _KNDS_LIST_NODE

typedef struct KNDS_ListNode {
	void* data;
	struct KNDS_ListNode* next;	
} KNDS_ListNode;

#endif
