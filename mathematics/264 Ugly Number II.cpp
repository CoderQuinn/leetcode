//
//  264 Ugly Number II.cpp
//  Leetcode
//
//  Created by Quinn on 2020/9/18.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> nums(1, 1);
        for (int i = 0, j = 0, k = 0; nums.size() < n;)
        {
            int t = min(min(2 * nums[i], 3 * nums[j]), 5 * nums[k]);
            nums.push_back(t);
            if (t == 2 * nums[i])
                i++;
            if (t == 3 * nums[j])
                j++;
            if (t == 5 * nums[k])
                k++;
        }
        return nums.back();
    }
};
