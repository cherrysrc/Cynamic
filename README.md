<h1 align="center">Cynamic</h1>

<p align="center">
Implementation of a dynamic array for C using macros
</p>
<p align="center">
    <img src="https://img.shields.io/badge/-Language-blue?style=for-the-badge&logo=c" />
</div>

Include Header:
```c
#include "List.h"
```

Create a new list (dynamic array):
```c
//Parameters are type and initial capacity
List(int) list = newList(int, 5);
```

Append to list:
```c
appendList(list, 9);
appendList(list, 4);
appendList(list, 7);
```

Prepend list:
```c
prependList(list, 6);
prependList(list, 3);
```

Pop:
```c
int element = popList(list);
```

Sort:
```c
sortList(list, cmp);
```
This functions essantially just wraps up C's standard qsort function.<br>
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

Dont forget to free used memory afterwards:
```c
cleanupList(list);
```
