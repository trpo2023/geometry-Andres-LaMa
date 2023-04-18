#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "mass.h"

list* list_create()
{
    list* a = (list*)malloc(sizeof(list));
    assert((a != NULL) && "Memory was not allocated under list");

    a->capacity = 0;
    a->mas = (int**)malloc(0 * sizeof(int*));
    assert((a->mas != NULL)
           && "Memory was not allocated under mas_circle.mas");

    a->mas[0] = (int*)malloc(0 * sizeof(int));
    assert((a->mas[0] != NULL)
           && "Memory was not allocated under mas_circle.mas[0]");

    for (short i = 0; i < 3; i++)
    {
        a->mas[0][i] = 0;
    }

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
    int** temp_m = (int**)realloc(circle->mas, sizeof(int*) * circle->capacity);
    for (short i = 0; i < circle->capacity; i++)
    {
        temp_m[i] = (int*)realloc(circle->mas[i], 3 * circle->capacity);
        assert((temp_m[i] != NULL) && "Memory was not reallocated under temp[i]");
    }
    
    assert((temp_m != NULL) && "Memory was not reallocated under temp");

    circle->mas = temp_m;
}
