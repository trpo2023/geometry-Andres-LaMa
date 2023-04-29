#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libgeometry/lexer.h"
#include "libgeometry/mass.h"
#include "libgeometry/parser.h"

int main()
{
    list* mas_circle = list_create();

    // mas_create(mas_circle);

    char string[50] = "0";
    short check = 0;
    printf("В данной программе доступен ввод только объекта типа 'circle'\nВсе "
           "остальные объекты будут являться ошибочными.\n Для окончания ввода "
           "введите 'run' \nДля выхода введите 'quit'\n");

    while (1)
    {
        fgets(string, 50, stdin);

        for (short i = 0; i < 50; i++) // приведение к одному регистру
        {
            string[i] = tolower(string[i]);
        }

        strip_extra_spaces(string); //____circle(... ___... __...___) ->
                                    // circle(..._..._...)

        if (string[0] == 'c')
        {
            check = check_word_circle(string);
            if (check < 0)
            {
                printf("Ошибка синтаксиса %d!\n", check);
            } else
            {
                mas_realloc(mas_circle);
                numbers_circle(string, mas_circle);
            }

        } else if (strcmp("run", string))
        {
            break;
        } else if (strcmp("quit", string))
        {
            return 0;
        }
    }
    double intersection;
    double area;
    double perimeter;

    for (unsigned short i = 0; i < mas_circle->capacity; i++)
    {
        printf("circle %d\n", i + 1);
        area = area_c(mas_circle->mas[i][2]);
        perimeter = area_c(mas_circle->mas[i][2]);
        printf("area = %f; perimeter = %f\nintersection:\n", area, perimeter);

        for (unsigned short j = 0; j < mas_circle->capacity; j++)
        {
            if (i == j)
            {
                continue;
            }
            intersection
                    = intersection_c(mas_circle, i, j); // sqrt( (x2-x1)*(x2-x1)
                                                        // + (y2-y1)*(y2-y1))
            intersection == 1 ? printf("circle %d - пересечение\n", j + 1)
                              : printf("circle %d - не пересечение\n", j + 1);
        }
        printf("\n");
    }

    return 0;
}