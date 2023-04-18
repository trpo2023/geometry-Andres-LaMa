#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "mass.h"

list* list_create()
{
    list* a = (list*)malloc(sizeof(list));
    assert((a != NULL) && "Memory was not allocated under list");

    return a;
}

void mas_create(list* circle)
{
    circle->mas = (int**)malloc(1 * sizeof(int*));
    assert((circle->mas != NULL)
           && "Memory was not allocated under mas_circle.mas");

    circle->mas[0] = (int*)malloc(3 * sizeof(int));
    assert((circle->mas[0] != NULL)
           && "Memory was not allocated under mas_circle.mas[0]");

    for (short i = 0; i < 3; i++)
    {
        circle->mas[0][i] = 0;
    }

    circle->capacity = 1;
}

void mas_realloc(list* circle)
{
    circle->capacity += 1;
    int** temp = (int**)realloc(circle->mas, circle->capacity);
    assert((temp != NULL) && "Memory was not reallocated under temp");

    circle->mas = temp;
}
