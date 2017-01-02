//
//  Circle.h
//  CinyTest-Example
//
//  Created by Brandon Stansbury on 1/1/17.
//  Copyright (c) 2017 Brandon Stansbury. All rights reserved.
//

#ifndef Circle_h
#define Circle_h

/////
// Circle definition
/////

struct circle {
    int radius;
};

/////
// Circle module operations
/////

struct circle make_circle(int radius);

double circle_diameter(struct circle c);

double circle_area(struct circle c);

int circle_tostring(struct circle c, char *output, size_t size);

#endif
