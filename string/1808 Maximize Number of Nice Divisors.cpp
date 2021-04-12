//
//  1808 Maximize Number of Nice Divisors.cpp
//  Leetcode
//
//  Created by Quinn on 2021/3/29.
//  Copyright © 2021 Quinn. All rights reserved.
//

#include <stdio.h>

using namespace std;

class Solution {
public:
    typedef long long LL;
    const int MOD = 1e9 + 7;
    int qmi(int a, int k)
    {
        int res = 1;
        while(k)
        {
            if(k & 1) res = (LL)res * a % MOD;
            k >>= 1;
            a = (LL) a * a % MOD;
        }
        return res;
    }

    int maxNiceDivisors(int m) {
        if(m <= 3) return m;

        if(m % 3 == 0) return qmi(3, m / 3);
        else if(m % 3 == 1) return (LL)qmi(3, (m - 4) / 3) * 4 % MOD;
        else return (LL)qmi(3, (m - 2) / 3) * 2 % MOD;
    }
};
