#ifndef _list_h_
#define _list_h_

#include <stdlib.h>

struct ListNode;

typedef struct ListNode {
	struct ListNode *next;
	struct ListNode *prev;
	void *value;
} ListNode;

typedef struct List {
	int count;
	ListNode *first;
	ListNode *last;
} List;

//Creates a new double-linked List
List *List_create();

//Destroys a List and any elements it might have
void List_destroy(List *list);

//Convenience function for freeing the values in each node, but not the nodes
void List_clear(List *list);

//Clears and destroys a list. Loops over the list twice
void List_clear_destroy(List *list);

//Returns the number of elements in the list, which is maintained as elements are added and removed
#define List_count(A) ((A)->count)

//Returns the first element of the list, but does not remove it
#define List_first(A) ((A)->first != NULL ? (A)->first->value : NULL)

//Returns the last element of the list, but does not remove it
#define List_last(A) ((A)->last != NULL ? (A)->last->value : NULL)

//Adds a new element to the end of the list (fast)
void List_push(List *list, void *value);

//Takes the last element off and returns it
void *List_pop(List *list);

//Like List_push, adds element to the front
void List_unshift(List *list, void *value);

//Like List_pop, this removes the first element and returns it
void *List_shift(List *list);

//Removes the nodes in List_pop and List_shift
void *List_remove(List *list, ListNode *node);

//Iterates over the elements in the list
#define LIST_FOREACH(L, S, M, V) ListNode *_node = NULL;\
	ListNode *V = NULL; \
	for(V = _node = L->S; _node != NULL; V = _node = _node->M)

#endif
