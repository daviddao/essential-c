# essential-c
A C data structure library for rapid prototyping

### Library

#### Double-linked List 
`list` provides basic functionalities of double-linked lists

#### Dynamic Array 
`darray` provides basic functionalities of an dynamic array

#### Debug helper macros in `dbg.h`


#### Automatic Unit Testing in `minunit.h`


### Documentation

#### Double-linked List

##### `List *List_create()`
Creates a new double-linked List

##### `void List_destroy(List *list)`
Destroys a List and any elements it might have

##### `void List_clear(List *list)`
Convenience function for freeing the values in each node, but not the nodes

##### `void List_clear_destroy(List *list)`
Clears and destroys a list. Loops over the list twice

##### `List_count(A)`
Returns the number of elements in the list, which is maintained as elements are added and removed

##### `List_first(A)`
Returns the first element of the list, but does not remove it

##### `List_last(A)`
Returns the last element of the list, but does not remove it

##### `List_push(List *list, void *value)`
Adds a new element to the end of the list (fast)

##### `void *List_pop(List *list)`
Takes the last element off and returns it

##### `List_unshift(List *list, void *value)`
Like List_push, adds element to the front

##### `void *List_shift(List *list)`
Like List_pop, this removes the first element and returns it

##### `void *List_remove(List *list, ListNode *node)`
Removes the nodes in List_pop and List_shift

##### `LIST_FOREACH(List *list, first, next, current)`
Iterates over the elements in the list

#### Dynamic Array

##### `DArray *DArray_create(size_t element_size, size_t initial_max)`
Create new dynamic array from type t

##### `*DArray_new(DArray *array)`
Create a new element pointer for array

##### `DArray_last(DArray *array)`
Returns the last element

##### `DArray_first(DArray *array)`
Returns the first element

##### `DArray_end(DArray *array)`
Returns the index of the last element

##### `DArray_count(DArray *array)`
Returns the number of elements in array

##### `DArray_max(DArray *array)`
Returns the max elements

##### `DArray_set(DArray *array, int i, void *el)`
Set an element on index i with the element pointer el

##### `DArray_get(DArray *array, int i)` 
Returns element on index i 

##### `DArray_remove(DArray *array, int i)`
Removes el on index i 

##### `DArray_clear(DArray *array)`
Clear all elements

##### `DArray_clear_destroy(DArray *array)`
Clear array and free it afterwards

##### `DArray_push(DArray *array, void *el)`
Push an element pointer into the end of the array. If max size is reached, the array expands

##### `DArray_pop(DArray *array, void *el)`
Returns and remove the last element. If old max size is reached, the array shrinks
