//
//  128 Longest Consecutive Sequence.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/31.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> set;
        for (auto &v : nums)
            set.insert(v);

        int res = 0;
        for (auto &x : nums)
        {
            if (set.count(x) && !set.count(x - 1))
            {
                int y = x;
                while (set.count(y))
                {
                    set.erase(y);
                    y++;
                }
                res = max(res, y - 1 - x + 1);
            }
        }

        return res;
    }
};
