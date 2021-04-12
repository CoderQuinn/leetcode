//
//  300 Longest Increasing Subsequence.cpp
//  Leetcode
//
//  Created by Quinn on 2021/4/8.
//  Copyright © 2021 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), len = 0, INF = 10000;
        vector<int> q(n + 1);
        q[0] = -INF - 1;

        for(int i = 0; i < n; i++)
        {
            int l = 0, r = len;
            while(l < r)
            {
                int mid = l + r + 1 >> 1;
                if(q[mid] < nums[i]) l = mid;
                else r = mid - 1;
            }
            len = max(len, l + 1);
            q[l + 1] = nums[i];
        }
        return len;
    }
};
