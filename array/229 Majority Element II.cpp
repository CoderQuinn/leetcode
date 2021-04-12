//
//  229 Majority Element II.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/30.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> res;

        int r1, r2, c1 = 0, c2 = 0;
        for (auto x : nums)
        {
            if (c1 && x == r1)
            {
                c1++;
            }
            else if (c2 && x == r2)
            {
                c2++;
            }
            else if (!c1)
            {
                c1++;
                r1 = x;
            }
            else if (!c2)
            {
                c2++;
                r2 = x;
            }
            else
            {
                c1--;
                c2--;
            }
        }

        c1 = 0, c2 = 0;
        for (auto x : nums)
        {
            if (x == r1)
            {
                c1++;
            }
            else if (x == r2)
            {
                c2++;
            }
        }

        auto n = nums.size();
        if (c1 > n / 3)
            res.push_back(r1);
        if (c2 > n / 3)
            res.push_back(r2);

        return res;
    }
};
