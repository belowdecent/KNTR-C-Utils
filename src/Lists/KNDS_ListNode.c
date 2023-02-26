#include "KNDS_ListNode.h"
#include <stdlib.h>

void KNDS_ListFree(KNDS_ListNode* head) {
	while (head != NULL) {
		KNDS_ListNode* last_node = head;
		head = head->next;
		free(last_node);
	}
}

void KNDS_ListDestroy(KNDS_ListNode* head) {
	while (head != NULL) {
		KNDS_ListNode* last_node = head;
		head = head->next;
		
		if (last_node->data != NULL) free(last_node->data);
		free(last_node);
	}
}

