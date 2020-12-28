//
//  172 Factorial Trailing Zeroes.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/17.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while(n) {
            ans += n / 5;
            n /= 5;
        }
        return ans;
    }
};
