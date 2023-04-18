#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <math.h>

#include "libgeometry/parser.h"
#include "libgeometry/lexer.h"
#include "libgeometry/mass.h"

int main()
{
    list *mas_circle = list_create();
    
    mas_create(mas_circle);

    char string[50] = "0";
    short check = 0;
    printf("В данной программе доступен ввод только объекта типа 'circle'\nВсе остальные объекты будут являться ошибочными.\n Для окончания ввода введите 'run' \nДля выхода введите 'quit'\n");

    while (1)
    {
        fgets(string, 50, stdin);

        for (short i = 0; i < 50; i++) // приведение к одному регистру
        {
            string[i] = tolower(string[i]);
        }
        
        strip_extra_spaces(string); //____circle(... ___... __...___) -> circle(..._..._...)
        
        if (string[0] == 'c')
        {
            check = check_word_circle(string);
            if (check < 0)
            {
                printf("Ошибка синтаксиса!\n");
            }
            else
            {
                numbers_circle(string, mas_circle);
            }
            
        }
        else if (strcmp("run", string))
        {
            break;
        }
        else if (strcmp("quit", string))
        {
            return 0;
        }
    }
    
    for (unsigned short i = 0; i < mas_circle->capacity; i++)
    {
        for (unsigned short j = 0; j < mas_circle->capacity; j++)
        {
            if (i == j)
            {
                continue;
            }
            double trajectory = sqrt( ((mas_circle->mas[j][0] - mas_circle->mas[i][0]) * (mas_circle->mas[j][0] - mas_circle->mas[i][0])) + ((mas_circle->mas[j][1] - mas_circle->mas[i][1]) * (mas_circle->mas[j][1] - mas_circle->mas[i][1]))); //sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
            double area = M_PI * mas_circle->mas[i][2] * mas_circle->mas[i][2];
            double perimeter = 2 * M_PI * mas_circle->mas[i][2];
        }
    }
    
    return 0;
}