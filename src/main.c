//
//  main.c
//  CinyTest-Example
//
//  Created by Brandon Stansbury on 1/1/17.
//  Copyright (c) 2017 Brandon Stansbury. All rights reserved.
//

#include "ciny.h"

struct ct_testsuite rectangle_tests(void);
struct ct_testsuite circle_tests(void);

int main(int argc, const char *argv[])
{
    const struct ct_testsuite suites[] = {
        rectangle_tests(),
        circle_tests()
    };

    size_t results = ct_run(suites);

    return results != 0;
}
