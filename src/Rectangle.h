//
//  Rectangle.h
//  CinyTest-Example
//
//  Created by Brandon Stansbury on 8/19/14.
//  Copyright (c) 2014 Brandon Stansbury. All rights reserved.
//

#ifndef Rectangle_h
#define Rectangle_h

#include <stddef.h>

//
// Rectangle definition
//

struct rectangle {
    int width, height;
};

//
// Rectangle module operations
//

struct rectangle rectangle_make(int width, int height);

int rectangle_area(struct rectangle rect);

double rectangle_hypotenuse(struct rectangle rect);

int rectangle_tostring(struct rectangle rect, size_t size, char output[size]);

void rectangle_print(struct rectangle rect);

#endif
