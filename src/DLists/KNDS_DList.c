#include "KNDS_DList.h"

KNDS_DList* KNDS_DListNew(
	void* data,
	KNDS_DList* next,
	KNDS_DList* prev	
) {
	KNDS_DList* list = malloc(sizeof(KNDS_DList));
	list->data = data;
	list->next = next;
	list->prev = prev;

	return list;
}

void KNDS_DListFree(KNDS_DList* node) {
	if (node == NULL) return;
	
	KNDS_DList* left  = node->prev;
	KNDS_DList* right = node->next;
	free(node);

	while (left != NULL) {
		KNDS_DList* prev = left->prev;
		free(left);
		left = prev;
	}

	while (right != NULL) {
		KNDS_DList* next = right->next;
		free(right);
		right = next;
	}
}

void KNDS_DListDestroy(KNDS_DList* node) {
	if (node == NULL) return;
	
	KNDS_DList* left  = node->prev;
	KNDS_DList* right = node->next;
	free(node->data);
	free(node);

	while (left != NULL) {
		KNDS_DList* prev = left->prev;
		free(left->data);
		free(left);
		left = prev;
	}

	while (right != NULL) {
		KNDS_DList* next = right->next;
		free(right->data);
		free(right);
		right = next;
	}
}
