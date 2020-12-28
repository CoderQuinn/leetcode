//
//  152 Maximum Product Subarray.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/15.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int ans = nums[0];
        int f = ans, g = ans;

        for (int i = 1; i < nums.size(); i++)
        {
            int j = nums[i];
            int fj = f * j, gj = g * j;
            f = max(j, max(fj, gj));
            g = min(j, min(fj, gj));
            ans = max(ans, f);
        }

        return ans;
    }
};
