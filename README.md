# libdatastructures

A static library containing generic definitions of data structures for my use in projects. Often times I find myself creating and recreating lists, heaps, trees, queues, etc for projects on my own and in class. I decided I would make one library that I could use in all of my projects that only requires a comparator for custom structs and nothing else, as it would be very easy to use and link in future projects that I do not even know the scope or requirements of.

# THIS LIBRARY HAS ZERO GUARANTEES ASSOCIATED WITH IT
It is definitely not safe and makes several assumptions about the data. For example, if you want to use a linked list of integers, you will need to strictly use integers and use the `size_t` of integers. Anything else will cause it to segfault and/or cause undefined behavior, as copying between `void*` will not work correctly. There are better ways to do this I'm sure, but this works for now, and is clearly documented. You have been warned!

## Usage
This will require a lot of initialization from the user. For example, in the heap data structure, this is an example of creation of a heap

```c
minheap* heap = malloc(sizeof(minheap));
size_t size = sizeof(int);
heap->capacity = 15;
heap->heap_size = 0;
heap->elements = malloc(sizeof(void *) * heap->capacity);
for (int i = 0; i < heap->capacity; i++) {
    heap->elements[i] = malloc(sizeof(size));
}
```

This is a heap with a capacity of 15 (TODO arbitraty size with realloc). Notice each of the void* in the array are allocated with the size of an integer. If you want to make a heap of custom structs, you will need to redefine the `size_t` to be the size of whatever item you want. 

Usage of a linked list follows less of a manual approach, as creating and adding to a linked list is as simple as 

```c
linked_list* list = malloc(sizeof(linked_list));

int to_add = 5;
void* p = &to_add;

list_add(list, p, sizeof(int));
```

A list is created, and it is passed in to a list_add with the pointer to the data to add, and the size of the data at that particular pointer. For your use case, you may send a different data size and you can add a custom struct. You can add whatever you want really, it's just a `void *`.

Remember though, if the `size_t` parameter is wrong, it could very well fail. If it is smaller than the size of what you pass in it should be alright, but anything larger and you will run into issues. Again, you have been warned!

## TODO
- [ ] Test the linking of the lib
- [x] Linked List
    - [x] Add wrapper class for list, abstract it out slightly
- [x] Binary Search Tree
- [x] Max Heap (and by extension, Priority Queue)
    - [ ] Heaps of arbitraty capacity
- [x] Binary Search Tree
    - [ ] NEEDS TESTING
- [ ] Hash Table/Hash Map
- [x] Stack
    - [ ] NEEDS TESTING
    - [ ] Stacks of arbitrary capacity
- [ ] Directed Graph
- [ ] Undirected Graph
- [ ] Init methods for various structures

# Contributing
At the moment I am not accepting contributions, as this is meant to be a learning opportunity for me. However, once done, if anyone really wants to, this portion of the README will be changed and I will accept contributions. I don't imagine anyone will use this, but you are absolutely welcome to use the library if you so choose!