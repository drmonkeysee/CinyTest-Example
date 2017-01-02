//
//  Circle.c
//  CinyTest-Example
//
//  Created by Brandon Stansbury on 1/1/17.
//  Copyright (c) 2017 Brandon Stansbury. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "Circle.h"

const double Pi = 3.1415927;

struct circle make_circle(int radius)
{
    return (struct circle){ radius };
}

double circle_diameter(struct circle c)
{
    return 2 * Pi * c.radius;
}

double circle_area(struct circle c)
{
    return Pi * pow(c.radius, 2);
}

int circle_tostring(struct circle c, char *output, size_t size)
{
    static const char * const restrict template = "Circle { r: %d }";
    int num_chars = snprintf(output, size, template, c.radius);
    return num_chars;
}
