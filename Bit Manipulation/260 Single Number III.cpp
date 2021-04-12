//
//  260 Single Number III.cpp
//  Leetcode
//
//  Created by Quinn on 2021/4/1.
//  Copyright © 2021 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int get(vector<int> &nums, int k, int t)
    {
        int res = 0;
        for (auto &x : nums)
        {
            if ((x >> k & 1) == t)
                res ^= x;
        }
        return res;
    }

    vector<int> singleNumber(vector<int> &nums)
    {
        int c = 0;
        for (auto &x : nums)
            c ^= x;
        int k = 0;
        while ((c >> k & 1) == 0)
            k++;
        int a = get(nums, k, 0), b = get(nums, k, 1);
        return {a, b};
    }
};
