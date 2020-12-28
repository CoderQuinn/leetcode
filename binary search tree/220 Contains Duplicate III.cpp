//
//  220 Contains Duplicate III.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/9.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        typedef long long LL;
        multiset<LL> S;
        S.insert(1e18), S.insert(-1e18);

        for (int i = 0, j = 0; i < nums.size(); i++)
        {
            if (i - j > k)
                S.erase(S.find(nums[j++]));
            LL x = nums[i];
            auto it = S.lower_bound(x);
            if (*it - x <= t)
                return true;

            --it;
            if (x - *it <= t)
                return true;
            S.insert(x);
        }

        return false;
    }
};
