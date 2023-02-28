#ifndef _KNDS_QUEUE
#define _KNDS_QUEUE

#include <stdlib.h>

#include "KNDS_ListNode.h"

/* 
First-In First-Out (FIFO) data structure.
Useful for queues.
Length is updated on each KNDS_QueuePush/KNDS_QueuePop call.
*/
typedef struct KNDS_Queue {
	KNDS_ListNode* front;
	KNDS_ListNode* back;

	size_t length;
} KNDS_Queue;

/*
Puts data to the back of the queue, returns put data.
*/
void* KNDS_QueuePush(KNDS_Queue* queue, void* data);

/*
Frees the front node of the queue, returns data stored there.
Does not free memory associated with the data.
*/
void* KNDS_QueuePop(KNDS_Queue* queue);

/*
Creates a new queue
*/
KNDS_Queue KNDS_QueueMerge(KNDS_Queue* front_queue, KNDS_Queue* back_queue);

/*
Links the last node of the top stack to the first node of the bottom stack.
Modifying the nodes inside the bottom stack will change the top stack, but will not update the length.
*/
void KNDS_QueueMergeInplace(KNDS_Queue* front_queue, KNDS_Queue* back_queue);
#endif
