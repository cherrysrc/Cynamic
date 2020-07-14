#ifndef PROJECTION_LIST_H
#define PROJECTION_LIST_H

#include <stdlib.h>

/**
 * List type definition
 */
#define List(T) \
    struct{\
        unsigned int capacity;\
        unsigned int count;\
        T* data;\
    }

/**
 * Creates a new list of a given type and initial capacity
 */
#define newList(T, capacity) \
    {\
        capacity,\
        0,\
        (T*)calloc(capacity, sizeof(T))\
    }

/**
 * Appends an element to the given list
 */
#define appendList(list, elt)\
    if(list.count >= list.capacity){\
        list.capacity*=2;\
        list.data = (typeof(list.data))realloc(list.data, list.capacity * sizeof(*list.data));\
    }\
    list.data[list.count++] = elt

/**
 * Prepends an element to the given list
 */
#define prependList(list, elt)\
    appendList(list, elt);\
    for(int i = list.count - 1; i >= 1; i--){\
        list.data[i] = list.data[i-1];\
    }\
    list.data[0] = elt

/**
 * Removes and returns the last element of the given list
 */
#define popList(list)\
    list.data[list.count--]

/**
 * Sorts a given list
 */
#define sortList(list, compareFunction)\
    qsort(list.data, list.count, sizeof(*list.data), compareFunction)

/**
 * Clean memory used by list
 */
#define cleanupList(list)\
    free(list.data)

#endif //PROJECTION_LIST_H