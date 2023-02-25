#include "KNDS_Stack.h"

void* KNDS_StackPush(KNDS_Stack* stack, void* data) {
  KNDS_StackNode* node = malloc(sizeof(KNDS_StackNode));
  node->data = data;
  node->next = stack->top;

  stack->top = node;
  stack->length += 1;
  
  return data;
}

KNDS_Result KNDS_StackInsert(KNDS_Stack* stack, size_t index, void* data) {
  if (index > stack->length) {
    return KNDS_ResultError(data, "Access out of bounds!");
  }

  if (index == 0) {
    KNDS_StackPush(stack, data);
    return KNDS_ResultOK(data);
  }

  KNDS_StackNode* target_node = malloc(sizeof(KNDS_StackNode));
  target_node->data = data;

  KNDS_StackNode* back_node = stack->top;
  
  for (size_t i = 1; i < index; ++i) {
    back_node = back_node->next;
  }

  target_node->next = back_node->next;
  back_node->next   = target_node;
  
  stack->length += 1;

  return KNDS_ResultOK(data);
}

// These functions don't free memory of the data within them, be a good person
void* KNDS_StackPop(KNDS_Stack* stack) {
  void* popped_data = stack->top->data;

  KNDS_StackNode* last = stack->top;
  stack->top = last->next;
  stack->length -= 1;
  free(last);
  
  return popped_data;
}

KNDS_Result KNDS_StackDelete(KNDS_Stack* stack, size_t index) {
  if (index > stack->length) {
    return KNDS_ResultError(NULL, "Access out of bounds!");
  }

  if (index == 0) {
    return KNDS_ResultOK(KNDS_StackPop(stack));
  }

  return KNDS_ResultError(NULL, "NOT IMPLEMENTED");
}

void KNDS_StackFreeChildren(KNDS_Stack* stack) {
  KNDS_StackNode* node = stack->top;
  while (node != NULL) {
    KNDS_StackNode* last = node;
    node = node->next;

    if (last->data != NULL) free(last->data);
    free(last);
  }
}

void KNDS_StackFreeNodes(KNDS_Stack* stack) {
  KNDS_StackNode* node = stack->top;
  while (node != NULL) {
    KNDS_StackNode* last = node;
    node = node->next;

    free(last);
  }
}