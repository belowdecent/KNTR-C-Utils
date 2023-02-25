#include "../SinglyLinkedLists/KNDS_Stack.h"

#include <stdlib.h>
#include <stdio.h>


#define EMPTY_PEG "    ┃    "
void draw_pegs(KNDS_Stack* stacks) {
	KNDS_StackNode* current_layer[3] = {
		stacks[0].top, stacks[1].top, stacks[2].top,
	};
	
	for (size_t i = 4; i > 0; --i) {
		for (size_t j = 0; j < 3; ++j) {
			if (stacks[j].length < i || current_layer[j] == NULL) {
				printf(" %s ", EMPTY_PEG);
			} else {
				printf(" %s ", (char*)current_layer[j]->data);
				current_layer[j] = current_layer[j]->next;
			}
		}
		printf("\n");
	}
}


#define FROM_LABEL "from ↑     "
#define TO_LABEL   "  to ↑     "
#define NONE_LABEL "           "
void draw_choice(char from, char to) {
	if (from == 0) {
		printf("%s", FROM_LABEL);
		if (to == 1) {
			printf("%s", TO_LABEL);
			printf("%s", NONE_LABEL);
		} else {
			printf("%s", NONE_LABEL);
			printf("%s", TO_LABEL);
		}
	}	else if (to == 0) {
		printf("%s", TO_LABEL);
		if (from == 1) {
			printf("%s", FROM_LABEL);
			printf("%s", NONE_LABEL);
		} else {
			printf("%s", NONE_LABEL);
			printf("%s", FROM_LABEL);
		}
	} else {
		printf("%s", NONE_LABEL);
		if (from == 1) {
			printf("%s", FROM_LABEL);
			printf("%s", TO_LABEL);
		} else {
			printf("%s", NONE_LABEL);
			printf("%s", TO_LABEL);
		}
	}

	printf("\n");
}

void tower_of_hanoi() {
	// system("clear");
	printf("To move the top disk from one peg to another,\ntype the first and then the second peg\n");

	char* pegs[4] = {
		"   ▇▇▇   ",
		"  ▇▇▇▇▇  ",
		" ▇▇▇▇▇▇▇ ",
		"▇▇▇▇▇▇▇▇▇",
	};

	char from_choice = 0;
	char to_choice   = 1;
	char free_choice = 2;

	KNDS_Stack stacks[3] = {
		{0}, {0}, {0}
	};

	KNDS_StackPush(&stacks[0], pegs[3]);	
	KNDS_StackPush(&stacks[0], pegs[2]);	
	KNDS_StackPush(&stacks[0], pegs[1]);	
	KNDS_StackPush(&stacks[0], pegs[0]);
	
	for (;;) {
		system("clear");
		draw_pegs(stacks);
		draw_choice(from_choice, to_choice);

		char buffer;
		char input = getchar();
		switch (input) {
			case 'a':
				buffer = from_choice;
				from_choice = free_choice;
				free_choice = buffer;
				break;
			case 'd':
				buffer = to_choice;
				to_choice = free_choice;
				free_choice = buffer;
				break;
			case 's':
				KNDS_StackPush(&stacks[to_choice], KNDS_StackPop(&stacks[from_choice]));
				break;
			case 'q':
				goto hanoi_end;
		}
	}
	
	hanoi_end: {
		KNDS_StackFreeNodes(&stacks[0]);
		KNDS_StackFreeNodes(&stacks[1]);
		KNDS_StackFreeNodes(&stacks[2]);
	}
}

int main() {
	printf("Stack usage!\nPick a game:\n");
	printf("1) Tower of Hanoi\n");	
	tower_of_hanoi();
}

