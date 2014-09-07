//
//  Rectangle.c
//  CinyTest-Example
//
//  Created by Brandon Stansbury on 8/19/14.
//  Copyright (c) 2014 Monkey Bits. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "Rectangle.h"

struct rectangle make_rectangle(int width, int height)
{
    return (struct rectangle){ width, height };
}

int rectangle_area(struct rectangle rect)
{
    return rect.width * rect.height;
}

double rectangle_hypotenuse(struct rectangle rect)
{
    return sqrt(pow(rect.width, 2) + pow(rect.height, 2));
}

int rectangle_tostring(struct rectangle rect, char *output, size_t size)
{
    static const char * const template = "Rectangle { w: %d, h: %d }";
    int num_chars = snprintf(output, size, template, rect.width, rect.height);
    return num_chars;
}
