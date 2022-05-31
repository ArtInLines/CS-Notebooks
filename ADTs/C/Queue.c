#include <stdlib.h>
#include <stdbool.h>
#include "element.h"
#include "item.h"


typedef struct Queue {
	item* start;
	item* end;
} Queue;


Queue* queue_new() {
	Queue* Q = malloc(sizeof(Queue));
	Q->start = NULL;
	Q->end = NULL;
	return Q;
}

unsigned int queue_size(Queue* Q) {
	unsigned int i = 0;
	item* t = Q->start;
	while (t != Q->end) {
		i++;
		t = t->next_item;
	}
	return i;
}

bool queue_isEmpty(Queue* Q) {
	return Q->start == NULL;
}

Queue* queue_enqueue(Queue* Q, element el) {
	item* t = malloc(sizeof(item));
	t->el = el;
	t->next_item = NULL;
	if (Q->start == NULL) Q->start = Q->end = t;
	else {
		Q->end->next_item = t;
		Q->end = t;
	}
	return Q;
}

Queue* queue_dequeue(Queue* Q) {
	if (queue_isEmpty(Q)) return NULL;
	item *t = Q->start->next_item;
	free(Q->start);
	Q->start = t;
	return Q;
}

element* queue_peek(Queue* Q) {
	if (queue_isEmpty(Q)) return NULL;
	return Q->start->el;
}

element_list queue_toList(Queue* Q) {
	unsigned int n = queue_size(Q);
	item* t = Q->start;
	element *L = malloc(n * sizeof(element));
	for (unsigned int i = 0; i < n; i++) {
		L[i] = *(t->el);
		t = t->next_item;
	}
	return (element_list){L, n};
}

Queue* queue_create(element* L, unsigned int length) {
	Queue* Q = queue_new();
	for (unsigned int i = 0; i < length; i++) queue_enqueue(Q, L[i]);
	return Q;
}

Queue* queue_copy(Queue* Q) {
	element_list L = queue_toList(Q);
	return queue_create(L.start, L.length);
}