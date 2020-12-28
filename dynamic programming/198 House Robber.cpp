//
//  198 House Robber.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/21.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1), g(n + 1);
        
        for(int i = 1; i <= n; i++) {
            f[i] = g[i - 1] + nums[i - 1];
            g[i] = max(f[i - 1], g[i - 1]);
        }
        
        return max(f[n], g[n]);
    }
};
