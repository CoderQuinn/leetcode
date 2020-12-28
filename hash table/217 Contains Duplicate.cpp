//
//  217 Contains Duplicate.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/10.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> s;

        for (auto &v : nums)
        {
            if (s.count(v))
            {
                return true;
            }
            else
            {
                s.insert(v);
            }
        }

        return false;
    }
};
