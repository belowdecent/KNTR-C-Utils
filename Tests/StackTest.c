#include "../SinglyLinkedLists/KNDS_Stack.h"

#include <stdlib.h>
#include <stdio.h>

void tower_of_hanoi() {
	// system("clear");
	printf("To move the top disk from one peg to another,\ntype the first and then the second peg\n");

	const char* empty = "    ┃    ";
	char* peg1  			= "   ▇▇▇   ";
	char* peg2  			= "  ▇▇▇▇▇  ";
	char* peg3  			= " ▇▇▇▇▇▇▇ ";
	char* peg4  			= "▇▇▇▇▇▇▇▇▇";

	KNDS_Stack stack1 = {0};
	KNDS_Stack stack2 = {0};
	KNDS_Stack stack3 = {0};

	KNDS_StackPush(&stack1, peg4);	
	KNDS_StackPush(&stack1, peg3);	
	KNDS_StackPush(&stack1, peg2);	
	KNDS_StackPush(&stack1, peg1);

	KNDS_StackPush(&stack2, KNDS_StackPop(&stack1));
	KNDS_StackPush(&stack2, KNDS_StackPop(&stack1));

	KNDS_StackNode* stack1_node = stack1.top;
	KNDS_StackNode* stack2_node = stack2.top;
	KNDS_StackNode* stack3_node = stack3.top;

	for (size_t i = 4; i > 0; --i) {
		if (stack1.length < i || stack1_node == NULL) {
			printf(" %s ", empty);
		} else {
			printf(" %s ", (char*)stack1_node->data);
			stack1_node = stack1_node->next;
		}

		if (stack2.length < i || stack2_node == NULL) {
			printf(" %s ", empty);
		} else {
			printf(" %s ", (char*)stack2_node->data);
			stack2_node = stack2_node->next;
		}

		if (stack3.length < i || stack3_node == NULL) {
			printf(" %s\n", empty);
		} else {
			printf(" %s\n", (char*)stack3_node->data);
			stack3_node = stack3_node->next;
		}
	}

	// TODO: Fix the goddamn FreeChildren function
}

int main() {
	printf("Stack usage!\n Pick a game:\n");
	printf("1) Tower of Hanoi\n");	
	tower_of_hanoi();
}

