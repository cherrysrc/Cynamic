<h1 align="center">Cynamic</h1>

<p align="center">
Implementation of a dynamic array for C using macros
</p>
<p align="center">
    <img src="https://img.shields.io/badge/-Language-blue?style=for-the-badge&logo=c" />
</div>

<h4>Run this project:</h4>

```
cmake .
make Cynamic
./Cynamic
```

<h4>For a complete example take a look at main.c</h4>

<h4>Include Header:</h4>

```c
#include "List.h"
```

<h4>Create a new list (dynamic array):</h4>

```c
//Parameters are type and initial capacity
List(int) list = newList(int, 5);
```

<h4>Append to list:</h4>

```c
appendList(list, 9);
appendList(list, 4);
appendList(list, 7);
```

<h4>Prepend list:</h4>

```c
prependList(list, 6);
prependList(list, 3);
```

<h4>Pop:</h4>

```c
int last = popList(list);
```

<h4>Remove at index:</h4>

```c
int removed = removeAt(list, 3);
```

<h4>Sort:</h4>

```c
sortList(list, cmp);
```
This functions essentially just wraps up C's standard qsort function.<br>
Therefore the second parameter, which is a function, has to be of type:
```c
int func(const void* a, const void* b);
```
Example for a function for comparing integer values:
```c
int cmp(const void* a, const void* b)
{
    return((*(int*)a) - (*(int*)b));
}
```

<h4>Pass as parameter:</h4>
Sadly it's not possible to pass a List directly as a parameter.
However you can convert it into a ListCarrier and back to get it across:

```c
printIntList(toCarrier(l));
```

In your function, you simply convert it back:
```c
void printIntList(ListCarrier carrier)
{
    List(int) list = fromCarrier(int, carrier);

    printf("[ ");
    for (int i = 0; i < list.count; i++)
    {
        printf("%i ", list.data[i]);
    }
    printf("]\n");
}
```

<h4>For Each:</h4>

```c
forEach(l, add100);
```
Second parameter is a function defined by you. In this example:

```c
void add100(int* a){
    *a = *a + 100;
}
```

<h2>Free Memory:</h2>

```c
cleanupList(list);
```
