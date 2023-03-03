#include "KNDS_Queue.h"

void* KNDS_QueuePush(KNDS_Queue* queue, void* data) {
	KNDS_List* node = malloc(sizeof(KNDS_List));
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

	KNDS_List* last_front = queue->front;
	queue->front = queue->front->next;
	queue->length -= 1;
	free(last_front);

	if (queue->front == NULL) queue->back = NULL;
	
	return data;
}

KNDS_Queue KNDS_QueueMerge(
	const KNDS_Queue* front_queue, 
	const KNDS_Queue* back_queue
) {
	KNDS_Queue queue = {0};

	KNDS_List* current_node = front_queue->front;
	while (current_node != NULL) {
		KNDS_QueuePush(&queue, current_node->data);
		current_node = current_node->next;
	}

	current_node = back_queue->front;
	while (current_node != NULL) {
		KNDS_QueuePush(&queue, current_node->data);
		current_node = current_node->next;
	}

	return queue;
}

void KNDS_QueueMergeInplace(KNDS_Queue* front_queue, KNDS_Queue* back_queue) {
	front_queue->length += back_queue->length;	
	front_queue->back->next = back_queue->front;
	front_queue->back = back_queue->back;

	return;
}
