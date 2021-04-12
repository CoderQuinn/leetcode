//
//  263 Ugly Number.cpp
//  Leetcode
//
//  Created by Quinn on 2020/9/18.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0) return false;
        while(n % 2 == 0) n /= 2;
        while(n % 3 == 0) n /= 3;
        while(n % 5 == 0) n /= 5;
        return n == 1;
    }
};
