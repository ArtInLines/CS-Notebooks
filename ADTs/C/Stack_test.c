#include "Stack.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main() {
	Stack* S = stack_new();
	
	int x = 3;
	
	assert(stack_top(S) == NULL_EL);
	assert(stack_isEmpty(S));
	assert(stack_pop(S) == NULL);
	assert(stack_top(stack_copy(stack_new())) == stack_top(stack_pop(stack_push(stack_new(), x))));
	
	int n = 10;
	int* L = malloc(sizeof(int) * n);
	
	for (int i = 0; i < n; i++) {
		// if (i > 0) printf("i == %i; L[i] == %i; stack_top(S) == %i; stack_size(S) == %i\n", i-1, L[i-1], stack_top(S), stack_size(S));	
		stack_push(S, i);
		assert(stack_top(S) == i);
		assert(!stack_isEmpty(S));
		L[i] = i;
		printf("i == %i; L[i] == %i; stack_top(S) == %i; stack_size(S) == %i\n", i, L[i], stack_top(S), stack_size(S));
		stack_print(S);
	}
		
	for (int i = n-1; i >= 0; i--) {
		printf("L[i] == %i; stack_top(S) == %i\n", L[i], stack_top(S));
		stack_print(S);
		assert(L[i] == stack_top(S));
		stack_pop(S);
	}
	
	printf("Test successful");
}
