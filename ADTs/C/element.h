typedef int element;

#define NULL_EL (element)0

typedef struct element_list {
	element* start;
	unsigned int length;
} element_list;

void element_print(element el);