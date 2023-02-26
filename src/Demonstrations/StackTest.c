#include "../SinglyLinkedLists/KNDS_Stack.h"

#include <stdlib.h>
#include <stdio.h>

struct peg {
	size_t value;
	char* visual;
};

void move_peg(KNDS_Stack* from, KNDS_Stack* to) {
	if (from->top == NULL) return;
	struct peg* from_peg = from->top->data;

	if (to->top != NULL) {
		struct peg* to_peg = to->top->data;
		if (from_peg->value > to_peg->value) return;
	}
	
	KNDS_StackPush(to, KNDS_StackPop(from));
}

#define EMPTY_PEG "    ┃    "
void draw_pegs(KNDS_Stack* stacks) {
	KNDS_ListNode* current_layers[3] = {
		stacks[0].top, stacks[1].top, stacks[2].top,
	};

	for (size_t row = 4; row > 0; --row) {
		for (size_t i = 0; i < 3; ++i) {
			if (stacks[i].length < row || current_layers[i] == NULL) {
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
	switch (from) {
		case 0:
			if (to == 1) {
				printf("%s%s%s\n", FROM_LABEL, TO_LABEL, NONE_LABEL);
			} else {
				printf("%s%s%s\n", FROM_LABEL, NONE_LABEL, TO_LABEL);
			}
			break;
		case 1:
			if (to == 0) {
				printf("%s%s%s\n", TO_LABEL, FROM_LABEL, NONE_LABEL);
			} else {
				printf("%s%s%s\n", NONE_LABEL, FROM_LABEL, TO_LABEL);
			}
			break;
		case 2:
			if (to == 0) {
				printf("%s%s%s\n", TO_LABEL, NONE_LABEL, FROM_LABEL);
			} else {
				printf("%s%s%s\n", NONE_LABEL, TO_LABEL, FROM_LABEL);
			}
			break;
	}
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
	  system("/bin/stty raw");
		char input = getchar();
		system("/bin/stty cooked");
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
				if (stacks[2].length == 4) goto hanoi_win;
				break;
			case 'q':
				goto hanoi_end;
		}
	}

	hanoi_win: {
		system("clear");
		draw_pegs(stacks);
		printf("You won! Press q to quit\n");

		for (;;) {
		  system("/bin/stty raw");
			char input = getchar();
			system("/bin/stty cooked");

			if (input == 'q') goto hanoi_end;
		} 
	}
	
	hanoi_end: {
		system("clear");
		KNDS_ListFree(stacks[0].top);
		KNDS_ListFree(stacks[1].top);
		KNDS_ListFree(stacks[2].top);
	}
}

int main() {
	printf("Stack usage!\nPick a game:\n");
	printf("1) Tower of Hanoi\n");	
	tower_of_hanoi();
}
