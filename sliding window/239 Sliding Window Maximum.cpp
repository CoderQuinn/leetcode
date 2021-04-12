//
//  239 Sliding Window Maximum.cpp
//  Leetcode
//
//  Created by Quinn on 2021/1/2.
//  Copyright © 2021 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> q;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++)
        {
            if (!q.empty() && i - q.front() + 1 > k)
            {
                q.pop_front();
            }

            while (!q.empty() && nums[q.back()] <= nums[i])
            {
                q.pop_back();
            }

            q.push_back(i);

            if (i + 1 >= k)
            {
                res.push_back(nums[q.front()]);
            }
        }

        return res;
    }
};
