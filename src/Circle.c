//
//  Circle.c
//  CinyTest-Example
//
//  Created by Brandon Stansbury on 1/1/17.
//  Copyright (c) 2017 Brandon Stansbury. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Circle.h"

#define BUFFER_SIZE 20u
static const double Pi = 3.1415927;

struct circle circle_make(int radius)
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

int circle_tostring(struct circle c, char output[], size_t size)
{
    static const char * const restrict template = "Circle { r: %d }";
    const int num_chars = snprintf(output, size, template, c.radius);
    return num_chars;
}

void circle_print(struct circle c)
{
    char buffer[BUFFER_SIZE];
   
    const int write_count = circle_tostring(c, buffer, sizeof buffer);
    
    if ((size_t)write_count < BUFFER_SIZE) {
        printf("%s\n", buffer);
    } else {
        fprintf(stderr, "Circle buffer too small!\n");
    }
}
