#include "src/List.h"
#include <stdio.h>

/**
 * Function for comparing two ints
 * @param a a
 * @param b b
 * @return positive if a>b, zero if a=b, negative if a<b
 */
int cmp(const void* a, const void* b)
{
    return((*(int*)a) - (*(int*)b));
}

/**
 * Function for printing a list of ints
 * @param carrier list to print
 */
void printIntList(ListCarrier carrier)
{
    //Convert carrier back to list
    List(int) list = fromCarrier(int, carrier);

    printf("[ ");
    for (int i = 0; i < list.count; i++)
    {
        printf("%i ", list.data[i]);
    }
    printf("]\n");
}

/**
 * Adds 100 to a given integer
 * @param a number to add to
 */
void add100(int* a){
    *a = *a + 100;
}

int main(int argc, char** argv)
{
    //Create new list of certain type
    List(int) l = newList(int, 5);

    //Append element to the given list
    appendList(l, 5);
    appendList(l, 6);
    appendList(l, 2);
    appendList(l, 4);
    appendList(l, 9);

    prependList(l, -1);
    prependList(l, -2);
    prependList(l, -3);

    //Remove the lists last element 3 times
    int popped = popList(l);
    printf("Popped: %i\n", popped);
    popList(l);
    popList(l);

    //Prepend elements to list
    prependList(l, 1);
    prependList(l, 14);
    prependList(l, 7);

    //Convert to carrier first
    //Lists sadly cannot be passed directly to functions
    printIntList(toCarrier(l));

    //Sort the entire list
    //uses cmp functiont compare two elements
    sortList(l, cmp);

    printIntList(toCarrier(l));

    //Delete a particular element by its index
    int removed = removeAt(l, 0);
    printf("Removed: %i\n", removed);

    printIntList(toCarrier(l));

    //Add 100 to each element
    //Note that add100 is a function defined at the top
    forEach(l, add100);

    printIntList(toCarrier(l));

    //Free memory
    cleanupList(l);

    return(0);
}
