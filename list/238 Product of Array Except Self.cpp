//
//  238 Product of Array Except Self.cpp
//  Leetcode
//
//  Created by Quinn on 2021/1/2.
//  Copyright © 2021 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, 1);
        
        for (int i = 1; i < n; i++)
        {
            res[i] = res[i - 1] * nums[i - 1];
        }
        
        for (int i = n - 1, s = 1; i >= 0; i--)
        {
            res[i] *= s;
            s *= nums[i];
        }
        
        return res;
    }
};
