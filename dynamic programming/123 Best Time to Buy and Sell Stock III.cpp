//
//  123 Best Time to Buy and Sell Stock III.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/30.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> f(n + 1);

        for(int i = 1, min_p = INT_MAX; i <= n; i++)
        {
            int &v = prices[i - 1];
            f[i] = max(f[i - 1], v - min_p);
            min_p = min(min_p, v);
        }

        int res = 0;
        for(int i = n, max_p = 0; i >= 1; i--)
        {
            int &v = prices[i - 1];
            res = max(res, max_p - v + f[i - 1]);
            max_p = max(max_p, v);
        }

        return res;
    }
};
