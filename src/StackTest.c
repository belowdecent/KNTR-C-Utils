#include "Demos/Stack/HanoiTower.h"

#include <stdlib.h>
#include <stdio.h>

int main() {
	printf("Stack usage!\nPick a game:\n");
	printf("1) Tower of Hanoi\n");

	for (;;) {
		if (hanoi_tower() == 0) break;
	}

	return EXIT_SUCCESS;
}

