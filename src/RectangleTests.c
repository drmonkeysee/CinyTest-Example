//
//  RectangleTests.c
//  CinyTest-Example
//
//  Created by Brandon Stansbury on 8/19/14.
//  Copyright (c) 2014 Brandon Stansbury. All rights reserved.
//

#include "ciny.h"
#include "Rectangle.h"

/////
// Unit Tests for Rectangle module
/////

static void makerectangle_createsrectangle(void *context)
{
    const int expected_width = 8;
    const int expected_height = 5;
    
    const struct rectangle rect = make_rectangle(expected_width, expected_height);
    
    ct_assertequal(expected_width, rect.width);
    ct_assertequal(expected_height, rect.height);
}

static void rectanglearea_calculatesarea(void *context)
{
    const struct rectangle rect = make_rectangle(8, 5);
    
    const int area = rectangle_area(rect);
    
    ct_assertequal(40, area);
}

static void rectanglehypotenuse_calculateshypotenuse(void *context)
{
    const struct rectangle rect = make_rectangle(3, 7);
    
    const double hypo = rectangle_hypotenuse(rect);
    
    ct_assertaboutequal(7.62, hypo, 0.01);
}

static void rectangletostring_buildsrectanglestring(void *context)
{
    const struct rectangle rect = make_rectangle(6, 8);
    char output[50];
    
    const int characters_written = rectangle_tostring(rect, output, sizeof output);
    
    ct_asserttrue((size_t)characters_written < sizeof output, "Test buffer too small for rectangle_tostring");
    ct_assertequalstr("Rectangle { w: 6, h: 8 }", output);
}

/////
// Test suite accessor
/////

struct ct_testsuite rectangle_tests(void)
{
    static const struct ct_testcase tests[] = {
        ct_maketest(makerectangle_createsrectangle),
        ct_maketest(rectanglearea_calculatesarea),
        ct_maketest(rectanglehypotenuse_calculateshypotenuse),
        ct_maketest(rectangletostring_buildsrectanglestring)
    };

    return ct_makesuite(tests);
}
