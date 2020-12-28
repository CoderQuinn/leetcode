//
//  188 Best Time to Buy and Sell Stock IV.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/17.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        const int INF = 1e9;
        int res = 0, n = prices.size();
        if (k >= n / 2)
        {
            for (int i = 1; i < n; i++)
            {
                res += max(0, prices[i] - prices[i - 1]);
            }
            return res;
        }
        
        vector<vector<int>> f(2, vector<int>(k + 1, -INF));
        auto g = f;
        f[0][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                f[i & 1][j] = max(f[i - 1 & 1][j], g[i - 1 & 1][j] + prices[i - 1]);
                g[i & 1][j] = g[i - 1 & 1][j];
                if (j > 0)
                    g[i & 1][j] = max(g[i & 1][j], f[i - 1 & 1][j - 1] - prices[i - 1]);
                res = max(res, f[i & 1][j]);
            }
        }
        
        return res;
    }
};
