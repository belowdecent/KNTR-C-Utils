#include "KNDS_Stack.h"

void* KNDS_StackPush(KNDS_Stack* stack, void* data) {
  KNDS_ListNode* node = malloc(sizeof(KNDS_ListNode));
  node->data = data;
  node->next = stack->top;

  stack->top = node;
  stack->length += 1;
  
  return data;
}

// These functions don't free memory of the data within them, be a good person
void* KNDS_StackPop(KNDS_Stack* stack) {
  void* popped_data = stack->top->data;

  KNDS_ListNode* last = stack->top;
  stack->top = last->next;
  stack->length -= 1;
  free(last);
  
  return popped_data;
}

void KNDS_StackFreeChildren(KNDS_Stack* stack) {
  KNDS_ListNode* node = stack->top;
  while (node != NULL) {
    KNDS_ListNode* last = node;
    node = node->next;

    if (last->data != NULL) free(last->data);
    free(last);
  }
}

void KNDS_StackFreeNodes(KNDS_Stack* stack) {
  KNDS_ListNode* node = stack->top;
  while (node != NULL) {
    KNDS_ListNode* last = node;
    node = node->next;

    free(last);
  }
}