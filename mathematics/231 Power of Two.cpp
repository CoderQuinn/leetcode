//
//  231 Power of Two.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/30.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    // lowbit
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & -n) == n;
    }
};
