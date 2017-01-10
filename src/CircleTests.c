//
//  CircleTests.c
//  CinyTest-Example
//
//  Created by Brandon Stansbury on 1/1/17.
//  Copyright (c) 2017 Brandon Stansbury. All rights reserved.
//

#include "ciny.h"
#include "Circle.h"

/////
// Unit Tests for Circle module
/////

static void circlemake_createscircle(void *context)
{
    const int expected_radius = 6;
    
    const struct circle c = circle_make(expected_radius);
    
    ct_assertequal(expected_radius, c.radius);
}

static void circlediameter_calculatesdiameter(void *context)
{
    const struct circle c = circle_make(6);
    
    const double diameter = circle_diameter(c);
    
    ct_assertaboutequal(37.7, diameter, 0.01);
}

static void circlearea_calculatesarea(void *context)
{
    const struct circle c = circle_make(4);
    
    const double area = circle_area(c);
    
    ct_assertaboutequal(50.26, area, 0.01);
}

static void circletostring_buildscirclestring(void *context)
{
    const struct circle c = circle_make(9);
    char output[50];
    
    const int characters_written = circle_tostring(c, output, sizeof output);
    
    ct_asserttrue((size_t)characters_written < sizeof output, "Test buffer too small for circle_tostring");
    ct_assertequalstr("Circle { r: 9 }", output);
}

/////
// Test suite accessor
/////

struct ct_testsuite circle_tests(void)
{
    static const struct ct_testcase tests[] = {
        ct_maketest(circlemake_createscircle),
        ct_maketest(circlediameter_calculatesdiameter),
        ct_maketest(circlearea_calculatesarea),
        ct_maketest(circletostring_buildscirclestring)
    };

    return ct_makesuite(tests);
}
