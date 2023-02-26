#include "KNDS_Queue.h"

void* KNDS_QueuePush(KNDS_Queue* queue, void* data) {
	KNDS_ListNode* node = malloc(sizeof(KNDS_ListNode));
	node->data = data;
	
	if (queue->back == NULL) {
		queue->front  = node;
		queue->back   = node;
		queue->length = 1;
		return data;
	}

	queue->back->next = node;
	queue->back = node;
	return node;
}

void* KNDS_QueuePop(KNDS_Queue* queue) {
	if (queue->front == NULL) return NULL;

	void* data = queue->front->data;

	KNDS_ListNode* last_front = queue->front;
	queue->front = queue->front->next;
	queue->length -= 1;
	free(last_front);

	if (queue->front == NULL) queue->back = NULL;
	
	return data;
}
