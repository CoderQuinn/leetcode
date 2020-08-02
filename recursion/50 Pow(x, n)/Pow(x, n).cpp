//
//  Pow(x, n).cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/1.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        long long N = n;
        if (n < 0) {
            N = -N;
            x =   1 / x;
        }
        return my_pow_core(x, n);
    }
    
    double my_pow_core(double x, long long n) {
        
        if (n == 0) return 1;
        
        double half_result = my_pow_core(x, n / 2);
        double result = half_result * half_result;
        if (n & 1) {
            result *= x;
        }

        return result;
    }
};
