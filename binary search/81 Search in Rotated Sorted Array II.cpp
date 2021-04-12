//
//  81 Search in Rotated Sorted Array II.cpp
//  Leetcode
//
//  Created by Quinn on 2020/10/21.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include <vector>
using namespace std;

class Solution
{
public:
    bool check(vector<int> &nums, int l, int r, int target)
    {
        while (l < r)
        {
            int mid = l + r >> 1;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        return target == nums[l];
    }

    bool search(vector<int> &nums, int target)
    {
        if (nums.empty())
            return false;
        int n = nums.size() - 1;
        while (n > 0 && nums[n] == nums[0])
            n--;
        if (nums[0] <= nums[n])
            return check(nums, 0, n, target);
        int l = 0, r = n;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (nums[mid] < nums[0])
                r = mid;
            else
                l = mid + 1;
        }

        if (target >= nums[0])
            return check(nums, 0, l - 1, target);
        else
            return check(nums, l, n, target);
    }
};
