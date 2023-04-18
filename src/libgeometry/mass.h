#pragma once
typedef struct list
{
    int capacity;
    int** mas;
} list;

list* list_create();

void mas_create(list* circle);

void mas_realloc(list* circle);