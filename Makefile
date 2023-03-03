CC = gcc

LISTS_SRC       = $(wildcard src/Lists/*.c)
STACK_DEMOS_SRC = $(wildcard src/Demos/Stack/*.s)

LISTS_OBJ = $(patsubst src/Lists/%.c, build/Lists/%.o, $(LISTS_SRC))
OBJS = $(shell find build -type f -name '*.o')

build/%.o: src/%.c
	$(CC) -c $< -o $@

folders:
	mkdir -p build/Lists
	mkdir -p build/Demos/Stack
	mkdir -p build/Tests

build/Tests/ListTests.o:		$(LISTS_OBJ)

build/StackTest.o:              build/Demos/Stack/HanoiTower.o
build/Demos/Stack/HanoiTower.o: build/Lists/KNDS_Stack.o

build/Lists/KNDS_Stack.o:       build/Lists/KNDS_List.o
build/Lists/KNDS_Queue.o:       build/Lists/KNDS_List.o

all: folders build/StackTest.o
	gcc build/StackTest.o \
		build/Demos/Stack/HanoiTower.o \
		build/Lists/KNDS_Stack.o \
		build/Lists/KNDS_List.o \
		-o release/StackTest

tests: folders build/Tests/ListTests.o
	gcc -g -O1 build/Tests/ListTests.o $(LISTS_OBJ) -o tests/ListTests

clean:
	rm -rf ./build/*
