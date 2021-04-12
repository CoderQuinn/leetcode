//
//  456 132 Pattern.cpp
//  Leetcode
//
//  Created by Quinn on 2021/3/26.
//  Copyright © 2021 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int max_k = INT_MIN, n = nums.size();
        stack<int> stk; // 维护的2
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] < max_k)
                return true;
            while (!stk.empty() && stk.top() < nums[i])
            {
                max_k = max(stk.top(), max_k);
                stk.pop();
            }
            stk.push(nums[i]);
        }
        
        return false;
    }
};
