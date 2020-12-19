//
//  Circle.c
//  CinyTest-Example
//
//  Created by Brandon Stansbury on 1/1/17.
//  Copyright (c) 2017 Brandon Stansbury. All rights reserved.
//

#include "Circle.h"

#include <math.h>
#include <stdio.h>

static const double Pi = 3.1415927;

struct circle circle_make(int radius)
{
    return (struct circle){radius};
}

double circle_diameter(struct circle c)
{
    return 2 * Pi * c.radius;
}

double circle_area(struct circle c)
{
    return Pi * pow(c.radius, 2);
}

int circle_tostring(struct circle c, size_t size, char output[size])
{
    return snprintf(output, size, "Circle { r: %d }", c.radius);
}

void circle_print(struct circle c)
{
    char buffer[20];

    const int write_count = circle_tostring(c, sizeof buffer, buffer);

    if (write_count < 0) {
        fputs("Circle string conversion failed!\n", stderr);
    } else if ((size_t)write_count < sizeof buffer) {
        printf("%s\n", buffer);
    } else {
        fputs("Circle buffer too small!\n", stderr);
    }
}
