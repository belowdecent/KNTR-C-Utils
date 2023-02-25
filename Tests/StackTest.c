#include "../SinglyLinkedLists/KNDS_Stack.h"

#include <stdlib.h>
#include <stdio.h>

void tower_of_hanoi() {
	// system("clear");
	printf("To move the top disk from one peg to another,\ntype the first and then the second peg\n");

	char* pegs[5] = {
		"    ┃    ",
		"   ▇▇▇   ",
		"  ▇▇▇▇▇  ",
		" ▇▇▇▇▇▇▇ ",
		"▇▇▇▇▇▇▇▇▇",
	};

	KNDS_Stack stacks[3] = {
		{0}, {0}, {0}
	};

	KNDS_StackPush(&stacks[0], pegs[4]);	
	KNDS_StackPush(&stacks[0], pegs[3]);	
	KNDS_StackPush(&stacks[0], pegs[2]);	
	KNDS_StackPush(&stacks[0], pegs[1]);

	KNDS_StackNode* current_layer[3] = {
		stacks[0].top, stacks[1].top, stacks[2].top,
	};

	for (size_t i = 4; i > 0; --i) {
		for (size_t i = 0; i < 3; ++i) {
			if (stacks[i].length < i || current_layer[i] == NULL) {
				printf(" %s ", pegs[0]);
			} else {
				printf(" %s ", (char*)current_layer[i]->data);
				current_layer[i] = current_layer[i]->next;
			}
		}
		printf("\n");
	}

	KNDS_StackFreeNodes(&stacks[0]);
	KNDS_StackFreeNodes(&stacks[1]);
	KNDS_StackFreeNodes(&stacks[2]);
}

int main() {
	printf("Stack usage!\nPick a game:\n");
	printf("1) Tower of Hanoi\n");	
	tower_of_hanoi();
}

