//
//  70 Climbing Stairs.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/18.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1, c;
        for(int i = 1; i < n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};
