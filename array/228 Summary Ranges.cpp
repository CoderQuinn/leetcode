//
//  228 Summary Ranges.cpp
//  Leetcode
//
//  Created by Quinn on 2020/12/30.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> res;

        for (int i = 0; i < nums.size(); i++)
        {
            int j = i + 1;
            while (j < nums.size() && nums[j] == nums[j - 1] + 1)
                j++;
            string t;
            if (j == i + 1)
            {
                t = to_string(nums[i]);
            }
            else
            {
                t = to_string(nums[i]) + "->" + to_string(nums[j - 1]);
            }
            res.push_back(t);
            i = j - 1;
        }

        return res;
    }
};
