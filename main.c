#include "src/List.h"
#include <stdio.h>

int cmp(const void* a, const void* b)
{
    return((*(int*)a) - (*(int*)b));
}

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

int main(int argc, char** argv)
{
    List(int) l = newList(int, 5);
    appendList(l, 5);
    appendList(l, 6);
    appendList(l, 2);
    appendList(l, 4);
    appendList(l, 9);

    prependList(l, -1);
    prependList(l, -2);
    prependList(l, -3);

    popList(l);
    popList(l);
    popList(l);

    prependList(l, 1);
    prependList(l, 14);
    prependList(l, 7);

    //Convert to carrier first
    //Lists sadly cannot be passed directly to functions
    printIntList(toCarrier(l));

    sortList(l, cmp);

    printIntList(toCarrier(l));

    cleanupList(l);

    return(0);
}
