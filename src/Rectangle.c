//
//  Rectangle.c
//  CinyTest-Example
//
//  Created by Brandon Stansbury on 8/19/14.
//  Copyright (c) 2014 Brandon Stansbury. All rights reserved.
//

#include "Rectangle.h"

#include <math.h>
#include <stdio.h>

struct rectangle rectangle_make(int width, int height)
{
    return (struct rectangle){width, height};
}

int rectangle_area(struct rectangle rect)
{
    return rect.width * rect.height;
}

double rectangle_hypotenuse(struct rectangle rect)
{
    return sqrt(pow(rect.width, 2) + pow(rect.height, 2));
}

int rectangle_tostring(struct rectangle rect, size_t size, char output[size])
{
    return snprintf(output, size, "Rectangle { w: %d, h: %d }", rect.width,
                    rect.height);
}

void rectangle_print(struct rectangle rect)
{
    char buffer[30];

    const size_t write_count = rectangle_tostring(rect, sizeof buffer, buffer);

    if (write_count < sizeof buffer) {
        printf("%s\n", buffer);
    } else {
        fputs("Rectangle buffer too small!\n", stderr);
    }
}
