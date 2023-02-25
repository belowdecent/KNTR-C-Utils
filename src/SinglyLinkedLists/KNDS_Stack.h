#ifndef _KNDS_STACK
#define _KNDS_STACK

#include <stdlib.h>
#include "../ErrorHandling/KNDS_Result.h"
#include "KNDS_ListNode.h"

/* 
Last-In First-Out (LIFO) data structure.
Useful for stacks of things.
Length is updated on each KNDS_StackPush/KNDS_StackPop call.
*/
typedef struct KNDS_Stack {
	KNDS_ListNode* top;
	size_t length;
} KNDS_Stack;

/*
Puts data on top of the stack, returns put data.
*/
void* KNDS_StackPush(KNDS_Stack* stack, void* data);

/* 
Frees the top node of the stack, returns data stored there.
Does not free memory associated with the data.
*/
void* KNDS_StackPop(KNDS_Stack* stack);


/*
Frees every node of the stack and the data stored there.
Does not free the stack itself.
*/
void KNDS_StackFreeChildren(KNDS_Stack* stack);

/*
Frees every node of the stack.
Does not free the stack itself.
*/
void KNDS_StackFreeNodes(KNDS_Stack* stack);

#endif
