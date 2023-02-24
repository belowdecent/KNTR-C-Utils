#ifndef _KNDS_Stack
#define _KNDS_Stack

#include <stdlib.h>
#include "../ErrorHandling/KNDS_Result.h"

struct KNDS_StackNode;

typedef struct KNDS_Stack {
	struct KNDS_StackNode* top;
	
	size_t length;
	size_t data_size;
} KNDS_Stack;

void* KNDS_StackPush(KNDS_Stack* stack, void* data);
KNDS_Result KNDS_StackInsert(KNDS_Stack* stack, size_t index, void* data);

// These functions don't free memory of the data within them, be a good person
void* KNDS_StackPop(KNDS_Stack* stack);
KNDS_Result KNDS_StackDelete(KNDS_Stack* stack, size_t index);

void KNDS_StackFreeChildren(KNDS_Stack* stack);

#endif
