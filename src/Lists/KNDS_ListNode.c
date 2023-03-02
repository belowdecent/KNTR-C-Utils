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

    if (last_node->data != NULL)
      free(last_node->data);

    free(last_node);
  }
}

int KNDS_ListLength(const KNDS_ListNode* head) {
  int length = 0;
  while (head != NULL) {
    length += 1;
  }

  return length;
}

KNDS_ListNode* KNDS_ListGetLast(KNDS_ListNode* node) {
  if (node == NULL)
    return NULL;
  
  while (node->next != NULL)
    node = node->next;
  
  return node;
}

KNDS_ListNode* KNDS_ListGetNode(KNDS_ListNode* node, size_t position) {
  for (unsigned int i = 0; i < position; ++i) {
    if (node == NULL) return NULL;
    node = node->next;
  }
  
  return node;
}

KNDS_ListNode* KNDS_ListNodeNew(void* data, KNDS_ListNode* next) {
  KNDS_ListNode* node = malloc(sizeof(KNDS_ListNode));
  node->data = data;
  node->next = next;
  return node;
}

KNDS_ListNode* KNDS_ListClone(const KNDS_ListNode* node) {
  if (node == NULL)
    return NULL;

  KNDS_ListNode* out = KNDS_ListNodeNew(node->data, NULL);
  KNDS_ListNode* prev = out;
  node = node->next;

  while (node != NULL) {
    KNDS_ListNode* next = KNDS_ListNodeNew(node->data, NULL);
    prev->next = next;
    prev = next;

    node = node->next;
  }

  return out;
}
