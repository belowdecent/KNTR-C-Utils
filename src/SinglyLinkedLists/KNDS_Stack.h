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



#endif
