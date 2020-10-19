//
//  50 Pow(x, n).cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/1.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdlib.h>

class Solution {
public:
    double myPow(double x, int n) {
        bool is_minus = n < 0;
        double res = 1;
        for (long k = abs(long(n)); k > 0; k >>= 1) {
            if (k & 1) {
                res *= x;
            }
            x *= x;
        }
        
        if (is_minus) {
            res = 1 / res;
        }
        return res;
    }
};
