#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "mass.h"

void numbers_circle(char* str, list* circle) // circle( 12.443 -212.232, 2)
{
    short i = 0;
    short sign = 1;
    double number;
    short position = 0;
    while (str[i])
    {
        if (str[i] == '-')
        {
            sign *= -1;
        } else if (isdigit(str[i]))
        {
            number = atof(&str[i]);
            while (isdigit(str[i]) || str[i] == '.')
            {
                i += 1;
            }
            circle->mas[circle->capacity - 1][position] = number * sign;
            position += 1;
            sign = 1;
        } else
        {
            i += 1;
        }
    }
}

double perimeter_c(double radius)
{
    if (radius < 0)
        return -1;
    return 2 * M_PI * (radius);
}

double area_c(double radius)
{
    if (radius < 0)
        return -1;
    return M_PI * radius * radius;
}

short intersection_c(list* mas_circle, int i, int j)
{
    if (sqrt(pow(mas_circle->mas[j][0] - mas_circle->mas[i][0], 2)
             + pow(mas_circle->mas[j][1] - mas_circle->mas[i][1], 2))
        < mas_circle->mas[i][2] + mas_circle->mas[j][2])
    {
        return 1;
    } else
    {
        return 0;
    }
}