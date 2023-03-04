#include "KNDS_DList.h"

KNDS_List* KNDS_ListNew(
	void* data, 
	KNDS_List* next, 
	KNDS_List* prev
) {
	KNDS_List* list = malloc(sizeof(KNDS_List));
	list->data = data;
	list->next = next;
	list->prev = prev;

	return list;
}

KNDS_List* KNDS_DListSplit(KNDS_List* list) {
	if (list == NULL) return NULL;

	KNDS_List* split_end = list->prev;
	if (split_end == NULL) return NULL;
	list->prev = NULL;

	split_end->next = NULL;
	return split_end;
}

void KNDS_DListFree(KNDS_List* list, void (*data_function)(void*)) {
	if (list == NULL) return;
	
	KNDS_List* left  = list->prev;
	KNDS_List* right = list->next;
	
	if (data_function == NULL) {
		while (left != NULL) {
			KNDS_List* next_node = left->prev;
			data_function(left->data);
			free(left);
			left = next_node;
		}

		while (right != NULL) {
			KNDS_List* next_node = right->next;
			data_function(right->data);
			free(right);
			right = next_node;
		}

		data_function(list->data);
		free(list);

		return;
	}
	
	while (left != NULL) {
		KNDS_List* next_node = left->prev;
		free(left);
		left = next_node;
	}

	while (right != NULL) {
		KNDS_List* next_node = right->next;
		free(right);
		right = next_node;
	}

	free(list);
}

KNDS_List* KNDS_DListGetFirst(KNDS_List* list) {
	if (list == NULL) return NULL;
	
	KNDS_List* node = list;
	while (node->prev != NULL)
		node = node->prev;

	return node;
}

KNDS_List* KNDS_DListGetLast(KNDS_List* list) {
	if (list == NULL) return NULL;
	
	KNDS_List* node = list;
	while (node->next != NULL)
		node = node->next;

	return node;
}

KNDS_List* KNDS_DListGetNode(KNDS_List* list, int relative_position) {
	size_t offset = abs(relative_position);

	if (relative_position < 0) {
		for (size_t i = 0; i < offset; ++i) {
			
		}
	}
}

/*
Clones the target node and each of the following nodes, forming a new list.
*/
KNDS_List* KNDS_DListClone(const KNDS_List* node);

/*
Returns the length of the list
*/
int KNDS_DListLength(const KNDS_List* head);

