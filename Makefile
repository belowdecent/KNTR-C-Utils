CC = gcc
ERROR_HANDLING_OBJS = src/ErrorHandling/KNDS_Result.c
LINKED_LISTS_OBJS = src/SinglyLinkedLists/KNDS_Stack.c src/SinglyLinkedLists/KNDS_ListNode.c
DEMONSTRATIONS_OBJS = src/Demonstrations/StackTest.c

all: $(DEMONSTRATIONS_OBJS) $(LINKED_LISTS_OBJS) $(ERROR_HANDLING_OBJS)
	$(CC) -o build/StackTest $(DEMONSTRATIONS_OBJS) $(LINKED_LISTS_OBJS) $(ERROR_HANDLING_OBJS)