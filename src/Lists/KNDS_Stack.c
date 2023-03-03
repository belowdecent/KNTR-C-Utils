#include "KNDS_Stack.h"
#include <stdlib.h>

void* KNDS_StackPush(KNDS_Stack* stack, void* data) {
  KNDS_List* node = malloc(sizeof(KNDS_List));
  node->data = data;
  node->next = stack->top;

  stack->top = node;
  stack->length += 1;
  
  return data;
}

void* KNDS_StackPop(KNDS_Stack* stack) {
  void* popped_data = stack->top->data;

  KNDS_List* last = stack->top;
  stack->top = last->next;
  stack->length -= 1;
  free(last);
  
  return popped_data;
}

KNDS_Stack* KNDS_StackMerge(
  const KNDS_Stack* top_stack, 
  const KNDS_Stack* bottom_stack
) {
  KNDS_List* current_node = top_stack->top;
  KNDS_Stack* stack = malloc(sizeof(KNDS_Stack));

  if (current_node == NULL) {
    stack->top = KNDS_ListClone(bottom_stack->top);
    stack->length = bottom_stack->length;
    return stack;
  }

  stack->length = top_stack->length + bottom_stack->length;
  
  KNDS_List* cloned_node = KNDS_ListNew(current_node->data, NULL);
  KNDS_List* last_cloned_node = cloned_node;

  stack->top = last_cloned_node;
  
  current_node = current_node->next;

  while (current_node != NULL) {
    cloned_node = KNDS_ListNew(current_node->data, NULL);
    last_cloned_node->next = cloned_node;
    last_cloned_node = cloned_node;

    current_node = current_node->next;
  }

  KNDS_List* bottom_stack_nodes = KNDS_ListClone(bottom_stack->top);
  last_cloned_node->next = bottom_stack_nodes;

  return stack;
}

void KNDS_StackMergeInplace(KNDS_Stack* top_stack, KNDS_Stack* bottom_stack) {
  if (bottom_stack == NULL)
    return;
  
  if (top_stack == NULL) {
    top_stack = bottom_stack;
    return;
  }

  if (top_stack->top == NULL) {
    if (bottom_stack != NULL)
      top_stack = bottom_stack;

    return;
  }

  top_stack->length += bottom_stack->length;
  KNDS_ListGetLast(top_stack->top)->next = bottom_stack->top;
  return;
}