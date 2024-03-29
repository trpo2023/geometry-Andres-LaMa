#include <ctype.h>
#include <stdio.h>

void strip_extra_spaces(char* str)
{
    int i, x;
    for (i = x = 0; str[i]; ++i)
        if (!isspace(str[i]) || (i > 0 && !isspace(str[i - 1])))
            str[x++] = str[i];
    str[x] = '\0';
}

short check_word_circle(char* str)
{
    short i = 0;
    char instance[] = "circle";
    for (i = 0; i < 6; i++)
    {
        if (instance[i] != str[i])
        {
            return -1;
        }
    }

    short check_branch = 0;
    short check_number = 0;
    short check_comma = 0;
    short check_sing = 0;

    while (str[i] && str[i] != '\n') // circle( f.12, 3 -22-3)
    {
        if (str[i] == '(' && check_branch >= 0)
        {
            check_branch += 1;
            i += 1;
        } else if (str[i] == ')' && check_branch - 1 >= 0)
        {
            check_branch -= 1;
            i += 1;
        } else if (str[i] == ' ')
        {
            i += 1;
        } else if (str[i] == ',')
        {
            if (check_number != 2)
            {
                return -4;
            }

            check_comma += 1;
            i += 1;
        } else if (isdigit(str[i])) // circle(1 2, -22-3)
        {
            short check_dot = 0;
            while (isdigit(str[i]) || str[i] == '.')
            {
                if (str[i] == '.')
                {
                    check_dot += 1;
                }
                if (check_dot > 1)
                {
                    return -6;
                }
                i += 1;
            }
            check_number += 1;
        } else if (str[i] == '-')
        {
            if (check_number == 2)
            {
                return -5;
            }
            check_sing += 1;
            i += 1;
            if (str[i] == '-' && str[i + 1] == '-')
            {
                return -5;
            } else
            {
                check_sing = 0;
            }
        } else
        {
            return -7;
        }
    }
    if (check_branch != 0)
    {
        return -2;
    } else if (check_number != 3)
    {
        return -3;
    } else if (check_comma != 1)
    {
        return -4;
    } else if (check_sing != 0) //идея для каждой ошибки выводить свой код //
    {
        return -5;
    }
    return 0;
}