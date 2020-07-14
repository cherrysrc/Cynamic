#include "src/List.h"
#include <stdio.h>

int cmp(const void* a, const void* b)
{
    return((*(int*)a) - (*(int*)b));
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

    sortList(l, cmp);

    for (int i = 0; i < l.count; i++)
    {
        printf("%i, ", l.data[i]);
    }

    cleanupList(l);

    return(0);
}
