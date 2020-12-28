//
//  213 House Robber II.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/23.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        vector<int> f(n + 1), g(n + 1);
        int res = 0;
        
        // 不选第一个
        for(int i = 2; i <= n; i++) {
            f[i] = g[i - 1] + nums[i - 1];
            g[i] = max(g[i - 1], f[i - 1]);
        }
        res = max(f[n], g[n]);
        
        // 选第一个
        f.resize(n + 1, 0);
        g.resize(n + 1, 0);
        f[1] = nums[0];
        g[1] = INT_MIN;
        
        for(int i = 2; i <= n; i++) {
            f[i] = g[i - 1] + nums[i - 1];
            g[i] = max(g[i - 1], f[i - 1]);
        }
        
        res = max(res, g[n]);
        return res;
    }
};
