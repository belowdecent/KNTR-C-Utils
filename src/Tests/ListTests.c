#include "../Lists/KNDS_Queue.h"
#include "../Lists/KNDS_Stack.h"
#include <assert.h>
#include <stdio.h>

#define STACK KNDS_Stack
#define QUEUE KNDS_Queue
#define NODE  KNDS_ListNode

int* CreateListData(int value);
STACK* CreateStack(int value_start, int length);
void ShrinkExpand(STACK* stack, size_t length);
void MergeUnmerge(STACK* stack1, STACK* stack2);

int* CreateListData(int value) {
	int* list_data = malloc(sizeof(int));
	*list_data = value;
	return list_data;
}

STACK* CreateStack(int value_start, int length) {
	STACK* stack = malloc(sizeof(STACK));
	stack->top = NULL;
	stack->length = 0;

	for (int i = 0; i < (int)length; ++i) {
		KNDS_StackPush(stack, CreateListData(i));
	}

	assert(stack->length == length);
	return stack;
}

void ShrinkExpand(STACK* stack, size_t length) {
	if (length > stack->length)
		length = stack->length;

	STACK* stack_copy = CreateStack(*(int*)(stack->top), stack->length);

	int** popped_numbers = malloc(sizeof(int*) * length);

	for (size_t i = 0; i < length; ++i) {
		popped_numbers[i] = (int*)KNDS_StackPop(stack);
	}

	for (size_t i = 0; i < length; ++i) {
		KNDS_StackPush(stack, popped_numbers[length - i - 1]);
	}

	assert(stack_copy->length == stack->length);
	
	NODE* stack_node = stack->top;
	NODE* copy_node  = stack_copy->top;
	while (stack_node != NULL) {
		assert(*(int*)(stack_node->data) == *(int*)(copy_node->data));
		stack_node = stack_node->next;
		copy_node  = copy_node->next;
	}

	KNDS_ListDestroy(stack_copy->top);
	free(stack_copy);
	
	free(popped_numbers);
}

void MergeUnmerge(STACK* stack1, STACK* stack2) {
	STACK* merged = KNDS_StackMerge(stack1, stack2);

	STACK* copy1 = malloc(sizeof(STACK));
	copy1->top = KNDS_ListClone(stack1->top);
	copy1->length = stack1->length;

	STACK* copy2 = malloc(sizeof(STACK));
	copy2->top = KNDS_ListClone(stack2->top);
	copy2->length = stack2->length;

	KNDS_StackMergeInplace(copy1, copy2);
	free(copy2);
	
	NODE* stack_node = merged->top;
	NODE* copy_node  = copy1->top;
	while (stack_node != NULL) {
		assert(copy_node != NULL);
		assert(*(int*)(stack_node->data) == *(int*)(copy_node->data));
		stack_node = stack_node->next;
		copy_node  = copy_node->next;
	}

	stack_node = merged->top;
	copy_node  = copy1->top;
	while (copy_node != NULL) {
		assert(stack_node != NULL);
		assert(*(int*)(stack_node->data) == *(int*)(copy_node->data));
		stack_node = stack_node->next;
		copy_node  = copy_node->next;
	}

	KNDS_ListFree(merged->top);
	KNDS_ListFree(copy1->top);
	free(merged);
	free(copy1);
}

int main() {
	for (size_t i = 0; i < 1; ++i) {
		STACK* stack = CreateStack(0, 100);
		STACK* stack2 = CreateStack(50, 100);
		ShrinkExpand(stack, 1);
		ShrinkExpand(stack2, 1);
		MergeUnmerge(stack, stack2);
		KNDS_ListDestroy(stack->top);
		KNDS_ListDestroy(stack2->top);
		free(stack);
		free(stack2);
	}
}