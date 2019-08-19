//
//  Circle.h
//  CinyTest-Example
//
//  Created by Brandon Stansbury on 1/1/17.
//  Copyright (c) 2017 Brandon Stansbury. All rights reserved.
//

#ifndef Circle_h
#define Circle_h

#include <stddef.h>

/////
// Circle definition
/////

struct circle {
    int radius;
};

/////
// Circle module operations
/////

struct circle circle_make(int radius);

double circle_diameter(struct circle c);

double circle_area(struct circle c);

int circle_tostring(struct circle c, size_t size, char output[size]);

void circle_print(struct circle c);

#endif
