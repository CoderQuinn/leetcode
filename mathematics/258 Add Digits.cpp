//
//  258 Add Digits.cpp
//  Leetcode
//
//  Created by Quinn on 2021/3/30.
//  Copyright © 2021 Quinn. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    int addDigits(int num) {
        if(num == 0) return 0;
        if(num % 9) return num % 9;
        return 9;
    }
};
