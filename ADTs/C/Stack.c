#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Stack.h"


Stack* stack_new() {
	Stack* S = malloc(sizeof(Stack));
	S->top = NULL;
	return S;
}

// TODO:
Stack* stack_free() {
	
}

bool stack_isEmpty(Stack* S) {
	return S->top == NULL;
}

Stack* stack_push(Stack* S, element el) {
	item* t = malloc(sizeof(item));
	t->el = &el;
	t->next_item = S->top;
	S->top = t;
	return S;
}

Stack* stack_pop(Stack* S) {
	if (stack_isEmpty(S)) return NULL;
	item *t = S->top->next_item;
	free(S->top);
	S->top = t;
	return S;
}

element stack_top(Stack* S) {
	if (stack_isEmpty(S)) return NULL_EL;
	return *(S->top->el);
}

// Retrieve the size (amount of elements) of a given Stack
// Runs in O(n), where n is the amount of elements in the stack
unsigned int stack_size(Stack *S) {
	unsigned int n = 0;
	item* t = S->top;
	while (t != NULL) {
		n++;
		t = t->next_item;
	}
	return n;
}

void stack_print(Stack *S) {
	printf("[");
	item* t = S->top;
	while (t != NULL) {
		printf(" ");
		// element_print(*(t->el));
		printf("%i", *(t->el));
		printf(" ");
		if (t->next_item != NULL) printf("|");
		t = t->next_item;
	}
	printf("]\n");
}

// Creates an element list. The elements are a normal array of elements of size `length`.
// The element at index 0 is the element at te bottom of the stack.
// In other words, `start[length - 1] == stack_top(S)`
// Runs in O(2n), where n is the amount of elements in the stack
element_list stack_toList(Stack *S) {
	unsigned int n = stack_size(S);
	item* t = S->top;
	element *L = malloc(n * sizeof(element));
	for (int i = n - 1; i > 0; i--) {
		L[i] = *(t->el);
		t = t->next_item;
	}
	return (element_list){L, n};
}

// Create a stack from a list of elements
// It is assumed that the last element is at the top of the stack
// and the first element is at the bottom of the stack
// Runs in O(n), where n is equal to length
Stack* stack_create(element* L, unsigned int length) {
	Stack* S = stack_new();
	for (unsigned int i = 0; i < length; i++) stack_push(S, L[i]);
	return S;
}

// Copies all elements of a Stack into a new Stack
// Runs in O(3n), where n is the amount of elements in S
Stack* stack_copy(Stack* S) {
	element_list L = stack_toList(S);
	return stack_create(L.start, L.length);
}