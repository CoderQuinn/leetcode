//
//  29 Divide Two Integers.cpp
//  Leetcode
//
//  Created by Quinn on 2020/9/21.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    typedef long long LL;
    int divide(int dividend, int divisor) {
        int sign = 1;
        if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))  sign = -1;
        
        vector<LL> exp;
        LL res = 0;
        LL a = abs(LL(dividend)), b = abs(LL(divisor));
        for(LL i = b; i <= a; i *= 2)
        {
            exp.push_back(i);
        }
        
        for(int i = int(exp.size() - 1); i >= 0; i--)
        {
            if(a >= exp[i])
            {
                a -= exp[i];
                res += 1ll << i;
            }
        }
        
        res *= sign;
        if(res > INT_MAX || res < INT_MIN) res = INT_MAX;
        
        return (int)res;
    }
};
