#ifndef _KNDS_STACK
#define _KNDS_STACK

#include <stdlib.h>

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
Creates a new stack consisting of all the top elements, followed by bottom elements.
Resulting stack does not share any nodes between the top and bottom, sharing only data withing them.
*/
KNDS_Stack KNDS_StackMerge(KNDS_Stack* top, KNDS_Stack* bottom);

/*
Links the last node of the top stack to the first node of the bottom stack.
Modifying the nodes inside the bottom stack will change the top stack, but will not update the length.
*/
void KNDS_StackMergeInplace(KNDS_Stack* top, KNDS_Stack* bottom);
#endif
