#include "element.h"
#include "item.h"
#include <stdbool.h>

typedef struct Stack {
	item* top;
} Stack;

Stack* stack_new();

bool stack_isEmpty(Stack* S);

Stack* stack_push(Stack* S, element* el);

Stack* stack_pop(Stack* S);

element* stack_top(Stack* S);

unsigned int stack_size(Stack *S);

element_list stack_toList(Stack *S);

Stack* stack_create(element* L, unsigned int length);

Stack* stack_copy(Stack* S);