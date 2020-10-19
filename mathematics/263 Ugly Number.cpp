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
    bool isUgly(int num) {
        if(num <= 0) return false;
        while(num % 2 == 0) num /= 2;
        while(num % 3 == 0) num /= 3;
        while(num % 5 == 0) num /= 5;
        
        return num == 1;
    }
};
