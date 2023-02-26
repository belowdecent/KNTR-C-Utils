CC = gcc

LISTS_SRC = $(wildcard src/Lists/*.c)
LISTS_OBJ = $(patsubst src/Lists/%.c, build/Lists/%.o, $(LISTS_SRC))

build/Lists/%.o: src/Lists/%.c
	$(CC) -c $< -o $@

build/Demonstrations/Stack/%.o: src/Demonstrations/Stack/%.c
	$(CC) -c $< -o $@

build/StackTest.o: src/StackTest.c
	$(CC) -c $< -o $@

build/StackTest: build/StackTest.o build/Demonstrations/Stack/HanoiTower.o $(LISTS_OBJ) folders
	$(CC) build/StackTest.o build/Demonstrations/Stack/HanoiTower.o $(LISTS_OBJ) -o build/StackTest

folders:
	mkdir -p build/Lists build/Demonstrations/Stack	

clean:
	rm -rf ./build/*
	rm -rf ./lib/*