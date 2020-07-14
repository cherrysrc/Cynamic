/**
 * @author Jerrit Gläsker
 * @copyright MIT-License
 *
 * @version 14 07 2020
 * @brief Dynamic Array implementation
 */

#ifndef PROJECTION_LIST_H
#define PROJECTION_LIST_H

#include <stdlib.h>

/**
 * List structure
 * @param  T type of list data
 */
#define List(T)                \
    struct {                   \
        unsigned int capacity; \
        unsigned int count;    \
        T*           data;     \
    }

/**
 * Creates a new list of the given type and capacity
 * @param  T        Type
 * @param  capacity Capacity
 * @return          new list
 */
#define newList(T, capacity)            \
    {                                   \
        capacity,                       \
        0,                              \
        (T*)calloc(capacity, sizeof(T)) \
    }

/**
 * Append an item to the given list
 * @param  list list to operate on
 * @param  elt  element to append
 */
#define appendList(list, elt)                                                                       \
    if (list.count >= list.capacity) {                                                              \
        list.capacity *= 2;                                                                         \
        list.data      = (typeof(list.data))realloc(list.data, list.capacity * sizeof(*list.data)); \
    }                                                                                               \
    list.data[list.count++] = elt

/**
 * Prepent item to list
 * @param  list list to operate on
 * @param  elt  element to prepend
 */
#define prependList(list, elt)                  \
    appendList(list, elt);                      \
    for (int i = list.count - 1; i >= 1; i--) { \
        list.data[i] = list.data[i - 1];        \
    }                                           \
    list.data[0] = elt

/**
 * Removes and returns the last element
 * @param  list list to operate on
 * @return      last item of list
 */
#define popList(list) \
    list.data[list.count--]

/**
 * Returns item at position
 * @param  list list to retrieve from
 * @param  i    index to retrieve from
 * @return      item at given location
 */
#define at(list, i) \
    list.data[i];

/**
 * Sorts a list using the builtin qsort function
 * @param  list            list to sort
 * @param  compareFunction function for comparing two elements
 */
#define sortList(list, compareFunction) \
    qsort(list.data, list.count, sizeof(*list.data), compareFunction)

/**
 * Frees memory used by a given list
 * @param  list list to operate on
 */
#define cleanupList(list) \
    free(list.data)

#endif //PROJECTION_LIST_H
