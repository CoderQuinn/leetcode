//
//  209 Minimum Size Subarray Sum.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/22.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int res = INT_MAX;

        for (int i = 0, j = 0, sum = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            while (sum - nums[j] >= s)
            {
                sum -= nums[j++];
            }
            if (sum >= s)
                res = min(res, i - j + 1);
        }

        if (res == INT_MAX)
            res = 0;
        return res;
    }
};
