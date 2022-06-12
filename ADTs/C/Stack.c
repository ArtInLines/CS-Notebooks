#include <stdlib.h>
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

Stack* stack_push(Stack* S, element* el) {
	item* t = malloc(sizeof(item));
	t->el = el;
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

element* stack_top(Stack* S) {
	if (stack_isEmpty(S)) return NULL;
	return S->top->el;
}

unsigned int stack_size(Stack *S) {
	unsigned int n = 0;
	item* t = S->top;
	while (t != NULL) {
		n++;
		t = t->next_item;
	}
	return n;
}

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

Stack* stack_create(element* L, unsigned int length) {
	Stack* S = stack_new();
	for (unsigned int i = 0; i < length; i++) stack_push(S, &L[i]);
	return S;
}

Stack* stack_copy(Stack* S) {
	element_list L = stack_toList(S);
	return stack_create(L.start, L.length);
}