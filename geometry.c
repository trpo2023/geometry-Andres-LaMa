#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define circle_s 0
#define triangle_s 1
#define poligon_s 2

typedef struct Point
{
    int x;
    int y;
}point;

typedef struct Circle
{
    point place;
    int radius;
}circle;

typedef struct Triangle
{
    point place[4];
}triangle;

typedef struct Poligon
{
    point *mas;
    int size;
}poliogon;


void init_triangle(triangle *tr_mas, int tsize)
{

}

void init_circle(triangle *ci_mas, int csize)
{

}

void init_poligon(triangle *po_mas, int psize)
{

}

int check_number_circle(char *string, int g) ///_____circle(________23.22____55, 4.5___) /// _____circle(________23.22____55, 4.5_
{
    short i = g;
    if (string[i] != '(')
    {
        return 0;
    }

    short check_branch = 0;
    double number;
    short check_number = 0;
    short check_comma = 0;



    while (i < 50 - g)
    {
        short check_dot = 0;

        if (string[i] == '(' && check_branch >= 0)
        {
            check_branch += 1;
            i += 1;
        }
        else if (string[i] == ')')
        {
            check_branch -= 1;
            i += 1;
        }
        else if (string[i] == ' ')
        {
            i += 1;
        }
        else if (string[i] == ',')
        {
            check_comma += 1;
            if (check_number < 2 || check_comma > 1)
            {
                printf("Ошибка в запятых\n");
                return 0;
            }
            
            i += 1;
        }
        else if (string[i] == '.')
        {
            printf("Лишняя точка\n");
            return 0;
        }
        
        
        else if (isdigit(string[i]))
        {
            number = atof(&string[i]);
            if (check_number == 0)
            {
                number = number;
            }
            else if (check_number == 1)
            {
                /* code */
            }
            else if (check_number == 2)
            {
                /* code */
            }
            else
            {
                printf("Что-то пошло не так... Чисел как-то много\n");
                return 0;
            }
            check_number += 1;
            while (isdigit(string[i]) || string[i] == '.' )
            {
                if (string[i] == '.')
                {
                    check_dot += 1;
                }
                if (check_dot > 1)
                {
                    printf("Лишняя точка\n");
                    return 0;
                }
                
                i += 1;
            }
        }
        else if (string[i] == '\n')
        {
            break;
        }
        
        else if (!isdigit(string[i]))
        {
            printf("Ошибка синтаксиса! Обнаружен посторонний символ!\n");
            return 0;
        }
    }
    if (check_comma != 1)
    {
        printf("Ошибка с количеством запятых\n");
        return 0;
    }
    if (check_branch != 0)
    {
        printf("Ошибка со скобками");
        return 0;
    }
    printf("Все гуд. Вводи следующее\n");
    return 1;
}

int check_word_circle(char *string, short k)
{
    char circle[] = "circle";

    short len = 0;
    short i;
    for (i = k; isalpha(string[i]); i++)
    {
        len += 1;
    }

    if (strlen(circle) == len) ///_____circle(
    {
        // len += i;
        for (short j = k; j < len; j++)
        {
            if (string[j] != circle[j - k])
            {
                printf("Ошибка i - k \n");
                return 0;
            }
        }
    }
    else
    {
        printf("Ошибка len!\n");
        return 0;
    }
    if (!check_number_circle(string, i))
    {
        printf("Ошибка синтаксиса в скобках!\n");
        return 0;
    }
    return 1;
}

int main()
{
    // int status_string[] = {0, 0, 0};
    char string[50] = "0";
    int check = 0;


    while (1)
    {
        printf("Введите название фигуры и координаты. Для выхода нажмите 'q'\n");
        fgets(string, 50, stdin);

        for (short i = 0; i < 50; i++)
        {
            string[i] = tolower(string[i]);
        }
        
        
        short i = 0;
        while (string[i] == ' ') /// _____circle(...)
        {
            i += 1;
        }
        
        switch (string[i])
        {
            case 'c':
                check += check_word_circle(string, i);
                break;
            case 't':
                // check += check_world_triangle(string, i);
                printf("В разработке\n");
                break;
            case 'p':
                // check += check_world_polygon(string, i);
                printf("В разработке\n");
                break;
            case 'q':
                printf("Выход...\n");
                return 0;
            default:
                printf("Ошибка синтаксиса! Это не фигура!\n");
                break;
        }
        
        if (!check)
        {
            // break;
        }
        check = 0;
        
    }
    
    

    return 0;
}