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

#define BUFFER_SIZE 30u

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

int rectangle_tostring(
    struct rectangle rect, size_t size, char output[size]
)
{
    static const char *const restrict template = "Rectangle { w: %d, h: %d }";
    const int num_chars = snprintf(
        output, size, template, rect.width, rect.height
    );
    return num_chars;
}

void rectangle_print(struct rectangle rect)
{
    char buffer[BUFFER_SIZE];

    const int write_count = rectangle_tostring(rect, sizeof buffer, buffer);

    if ((size_t)write_count < BUFFER_SIZE) {
        printf("%s\n", buffer);
    } else {
        fputs("Rectangle buffer too small!\n", stderr);
    }
}
