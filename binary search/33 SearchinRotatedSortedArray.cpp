//
//  SearchinRotatedSortedArray.cpp
//  Leetcode
//
//  Created by Quinn on 2020/8/2.
//  Copyright © 2020 Quinn. All rights reserved.
//
#include <vector>
using std::vector;

class Solution
{
public:
    int check(vector<int> &nums, int l, int r, int target)
    {
        while (l < r)
        {
            int mid = l + r >> 1;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        if (nums[l] == target)
            return l;
        else
            return -1;
    }

    int search(vector<int> &nums, int target)
    {
        if (nums.empty())
            return -1;
        int n = nums.size();
        if (nums[n - 1] >= nums[0])
            return check(nums, 0, n - 1, target);
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (nums[mid] < nums[0])
                r = mid;
            else
                l = mid + 1;
        }

        if (target >= nums[0])
            return check(nums, 0, r - 1, target);
        else
            return check(nums, l, n - 1, target);
    }
};
