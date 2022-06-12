#include "element.h"
#include "item.h"
#include <stdbool.h>

typedef struct Queue {
	item* start;
	item* end;
} Queue;

Queue* queue_new();

unsigned int queue_size(Queue* Q);

bool queue_isEmpty(Queue* Q);

Queue* queue_enqueue(Queue* Q, element el);

Queue* queue_dequeue(Queue* Q);

element* queue_peek(Queue* Q);

element_list queue_toList(Queue* Q);

Queue* queue_create(element* L, unsigned int length);

Queue* queue_copy(Queue* Q);