/**
 * @author Jerrit Gläsker
 * @copyright MIT-License
 *
 * @version 14 07 2020
 * @brief Dynamic Array implementation
 */

#ifndef CYNAMIC_LIST_H
#define CYNAMIC_LIST_H

#include <stdlib.h>

typedef struct
{
    unsigned int capacity;
    unsigned int count;
    void*        data;
} ListCarrier;

/**
 * Converts a list into a ListCarrier
 * This enables it to be used as a function parameter
 * @param  list list to convert
 * @return      ListCarrier object
 */
#define toCarrier(list)  \
    (ListCarrier) {      \
        list.capacity,   \
        list.count,      \
        (void*)list.data \
    }

/**
 * Converts a carrier back into a list
 * @param  T       type to convert into
 * @param  carrier carrier to convert
 * @return         List(T)
 */
#define fromCarrier(T, carrier) \
    {                           \
        carrier.capacity,       \
        carrier.count,          \
        (T*)carrier.data        \
    }

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
 * Removes an element at a particular index
 * @param  list  list to delete from
 * @param  index index to remove
 * @return       the element at that position
 */
#define removeAt(list, index)                      \
    list.data[index];                              \
    for (int i = index; i < list.count - 1; i++) { \
        list.data[i] = list.data[i + 1];           \
    }                                              \
    list.count--;                                  \


/**
 * Executes a given function on each element of the list
 * @param  list     list to operate on
 * @param  function function to execute on each object
 */
#define forEach(list, function)            \
    for (int i = 0; i < list.count; i++) { \
        function(&list.data[i]);           \
    }

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
