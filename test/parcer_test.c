#include <ctest.h>
#include <math.h>
#include <stdlib.h>

#include <../src/libgeometry/lexer.h>
#include <../src/libgeometry/mass.h>
#include <../src/libgeometry/parser.h>

CTEST(syntax_suite, simple_return)
{
    char* str = "circle(1 2, 3)";
    ASSERT_EQUAL(0, check_word_circle(str));

    str = "cricle(1 2, 3)";
    ASSERT_EQUAL(-1, check_word_circle(str));

    str = "circle(1 2, 3";
    ASSERT_EQUAL(-2, check_word_circle(str));

    str = "circle(1 2,)";
    ASSERT_EQUAL(-3, check_word_circle(str));

    str = "circle(1, 2, 3)";
    ASSERT_EQUAL(-4, check_word_circle(str));

    str = "circle(1 2, -22-3)";
    ASSERT_EQUAL(-5, check_word_circle(str));

    str = "circle(1 2.1.12, 3)";
    ASSERT_EQUAL(-6, check_word_circle(str));

    str = "circle(1 fq2, 3)";
    ASSERT_EQUAL(-7, check_word_circle(str));
}

CTEST(parser, perimeter_c)
{
    ASSERT_DBL_NEAR(-1, perimeter_c(-54));
    ASSERT_DBL_NEAR(M_PI, perimeter_c(0.5));
    ASSERT_DBL_NEAR(2 * M_PI * 54, perimeter_c(54));
}

CTEST(parser, area_c)
{
    ASSERT_DBL_NEAR(-1, area_c(-34));
    ASSERT_DBL_NEAR(M_PI, area_c(1));
    ASSERT_DBL_NEAR(4 * M_PI, area_c(2));
    ASSERT_DBL_NEAR(9 * M_PI, area_c(3));
    ASSERT_DBL_NEAR(25 * M_PI, area_c(5));
}

CTEST(parser, intersection_c)
{
    list* mas_circle = list_create();

    mas_realloc(mas_circle);
    numbers_circle("circle(1 1, 2)", mas_circle);
    mas_realloc(mas_circle);
    numbers_circle("circle(1 2, 3)", mas_circle);
    mas_realloc(mas_circle);
    numbers_circle("circle(50 34.3, 4)", mas_circle);

    for (int i = 0; i < mas_circle->capacity; i++)
    {
        for (int j = 0; j < mas_circle->capacity; j++)
        {
            if (i == j)
            {
                continue;
            }
            ASSERT_INTERVAL(0, 1, intersection_c(mas_circle, i, j));
        }
    }
}