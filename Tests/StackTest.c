#include "../SinglyLinkedLists/KNDS_Stack.h"

#include <stdlib.h>
#include <stdio.h>

struct peg {
	size_t value;
	char* visual;
};

// void move_peg(KNDS_Stack* from, KNDS_Stack* to) {
//	if (from->top == NULL) return;/
// }

void move_peg(KNDS_Stack* from, KNDS_Stack* to) {
	if (from->top == NULL) return;
	struct peg* from_peg = from->top->data;

	if (to->top != NULL) {
		struct peg* to_peg = to->top->data;
		if (from_peg->value > to_peg->value) return;
	}
	
	KNDS_StackPush(to, KNDS_StackPop(from));
	return;
}

#define EMPTY_PEG "    ┃    "
void draw_pegs(KNDS_Stack* stacks) {
	KNDS_StackNode* current_layers[3] = {
		stacks[0].top, stacks[1].top, stacks[2].top,
	};

	for (size_t counter = 4; counter > 0; --counter) {
		for (size_t i = 0; i < 3; ++i) {
			if (stacks[i].length < counter || current_layers[i] == NULL) {
				printf(" %s ", EMPTY_PEG);
			} else {
				struct peg* layer_data = current_layers[i]->data;
				printf(" %s ", layer_data->visual);
				current_layers[i] = current_layers[i]->next;
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

	struct peg pegs[4] = {
		{0}, {0}, {0}, {0}
	};

	pegs[0].value = 1;
	pegs[1].value = 2;
	pegs[2].value = 3;
	pegs[3].value = 4;

	pegs[0].visual = "   ▇▇▇   ";
	pegs[1].visual = "  ▇▇▇▇▇  ";
	pegs[2].visual = " ▇▇▇▇▇▇▇ ";
	pegs[3].visual = "▇▇▇▇▇▇▇▇▇";

	char from_id = 0;
	char to_id   = 1;
	char free_id = 2;

	KNDS_Stack stacks[3] = {
		{0}, {0}, {0}
	};

	KNDS_StackPush(&stacks[0], &pegs[3]);	
	KNDS_StackPush(&stacks[0], &pegs[2]);	
	KNDS_StackPush(&stacks[0], &pegs[1]);	
	KNDS_StackPush(&stacks[0], &pegs[0]);
	
	for (;;) {
		system("clear");
		draw_pegs(stacks);
		draw_choice(from_id, to_id);

		char buffer;
		char input = getchar();
		switch (input) {
			case 'a':
				buffer = from_id;
				from_id = free_id;
				free_id = buffer;
				break;
			case 'd':
				buffer = to_id;
				to_id = free_id;
				free_id = buffer;
				break;
			case 's':
				move_peg(&stacks[from_id], &stacks[to_id]);
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

